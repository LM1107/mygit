#include "server.h"

int xxx(int connfd,sqlite3 *db)
{
    printf("helleo\n");
}

int hhandler(int connfd,sqlite3 *db)
{
    int t = 0;
    while(1)
    {
        int ret = Login(connfd,&t,db);
        if(ret == 1)
        {
            t = 0;
            break;
        }
        if(t == 3)
        {
            t = 0;
            printf("you've tried 3 times,plz reconnect\n");
            printf("connect close\n");
            close(connfd);
            return -1;
        }else{
            continue;
        }	
    }
    if(t != 3)
    {
        while(1)
        {
            int ret = handler(connfd);
            if(ret == 1)
            {
                printf("connect close\n");
                close(connfd);
                return 0;
            }
        }
    }
}

int Login(int connfd,int *t,sqlite3 *db)
{
    char ID[NS] = {0};
    char PW[NS] = {0};
    char buf[NS] = {0};
    recvMsg(connfd,ID,NS);
    recvMsg(connfd,PW,NS);

    int ret = dbSelect(ID,PW,db);
    if(ret == -1)
    {
        return -1;
    }else if(ret != 0)
    {
        strcpy(buf,"correct");
        sendMsg(connfd,buf,NS);
        return 1;
    }
    (*t)++;
    sprintf(buf,"warning:wrong!you get %d times",3-(*t));
    sendMsg(connfd,buf,NS);
    return 0;
}

int handler(int connfd)
{
    char cmd[NS] = {0};
    char filename[NS] = {0};
    int ret = recvMsg(connfd,cmd,NS);
    printf("recv : %s\n",cmd);

    if(ret < 0)
    {    
        perror("failed to read cmd");
        return -1;
    }

    if(strncmp(cmd,"upload",6)==0)
    {
        if(strlen(cmd)==6)
            return 0;
        sscanf(cmd,"%*s%s",filename);
        bzero(cmd,NS);
        recvMsg(connfd,cmd,NS);
        if(strncmp(cmd,"upload wrong",12)==0)
        {
            printf("%s\n",cmd);
            return 0;
        }else{
            printf("%s\n",cmd);
            upload(connfd,filename);
        }
    }else if(strncmp(cmd,"download",8)==0)
	{
        if(strlen(cmd)==8)
            return 0;
        sscanf(cmd,"%*s%s",filename);
        ret = checkFile(filename);
        if(ret == -1)
        {
            bzero(cmd,NS);
            strcpy(cmd,"no such file,plz check filename");
            sendMsg(connfd,cmd,NS);
        }else{
            bzero(cmd,NS);
            sendMsg(connfd,cmd,NS);
            printf("find %s success\n",filename);
            download(connfd,filename);
        }
	}else if(strncmp(cmd,"show",4)==0)
    {
        show(connfd);
    }else if(strncmp(cmd,"quit",4)==0)
    {
        return 1;
    }else
    return 0;
}

int TcpServerInit(const char *IP,int port,int backlog)
{
	//建立socket连接
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd < 0)
		PERROR("socket");

	//设置sockaddr_in 结构体中的相关参数
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(IP);
	//local_addr.sin_addr.s_addr = INADDR_ANY;//让系统自动检测本地网卡IP并绑定

	//绑定函数bind()
	int ret = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(ret < 0)
        PERROR("bind");

	//调用listen()函数，设置监听模式
	ret = listen(listenfd,backlog);
	if(ret == -1)
		PERROR("listen");

	return listenfd;
}

int Accept(int listenfd)
{
	//客户端地址信息
	struct sockaddr_in client_addr={0};
	int len = sizeof(client_addr);

	int connfd = accept(listenfd,(struct sockaddr *)&client_addr,&len);
	if(connfd < 0)
		PERROR("accept error\n");

	//输出对方的IP地址信息
	printf("client connected [%s:%d]\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
	return connfd;
}

/*进行一次读取
**返回值：实际读取的值
**注意：非全部读取，仅仅是一次！
*/
int recvMsg(int connfd,char *buf,int length)
{
	int ret = 0;
    int size = 0;
	while(size < length)
	{
		ret = read(connfd, buf+size, length-size);
		if(ret < 0)
		{
			perror("\n[recv_%s] recv file failed\n");
			exit(-1);
		}
		size += ret;
		if(ret < length)
			return size;
	}
	return size;
}

int sendMsg(int connfd,char *buf,int length)
{
	int ret = 0;
	int size = 0;
	while(size<length)
	{
		ret = write(connfd, buf+size, length-size);
		if(ret < 0)
		{
			perror("recv");
			exit(-1);
		}
        size += ret;
	}
	return size;
}

int upload(int connfd,char *filename)
{
    char file_len[16] = {0};//文件长度
	char file_name[128] = {0};//文件名称
	char buf[1024] = {0};//数据缓冲区

    recvMsg(connfd,buf,144);

    strncpy(file_len, buf, sizeof(file_len));//取出文件大小
	strncpy(file_name, buf+sizeof(file_len), sizeof(file_name));//取出文件名称
		
	printf("ready receive!!!! file name:[%s] file size:[%s]\n",file_name, file_len);

    //新的文件名
	sprintf(buf, "../servBackup/recv_%s", file_name);
    
    int ffd = open(buf, O_WRONLY | O_CREAT, 0666);
		
	int size = atoi(file_len);//文件大小
	int write_len = 0;//记录已写入的字节数
    
    transFile(connfd,ffd,size);

	close(ffd);

    return 0;
}

int transFile(int connfd,int ffd,int length)
{
    char buf[BUF_SIZE] = {0};
    int ret = 0;
    int size = 0;
    while(size<length)
    {
        ret = recvMsg(connfd,buf,BUF_SIZE);
        if(ret < 0)
            PERROR("recvMsg")
        //写入新建的文件
        sendMsg(ffd,buf,ret);

        size += ret;
    }
    return size;
}

int download(int connfd,char *filename)
{
    printf("filename:%s\n",filename);
	char buf[BUF_SIZE] = {0};
    char file_info[BUF_SIZE] = {0};

    char file_name[NS] = {0};
    sprintf(file_name, "../servBackup/%s", filename);

    int fd = open(file_name,O_RDONLY);
    if(fd == -1)
    {
        printf("open [%s] failed\n",file_name);
        return -1;
    }
    int len = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    sprintf(file_info,"%d",len);
    strcpy(file_name,filename);
    strcpy(file_info+16,file_name);

    sendMsg(connfd,file_info,144);

    while(1)
    {
        bzero(buf,sizeof(buf));
        //读取数据
        
        int ret = read(fd,buf,sizeof(buf));
        
        sendMsg(connfd,buf,ret);

        if(ret == 0)
        {
            printf("send file[%s] succeed!!!!\n", file_name);
            break;
        }
    }
    close(fd);
    return 0;
}

int show(int connfd)
{
    char *ptr = getFile();
    char buf[BUF_SIZE] = {0};
    strcpy(buf,ptr);
    sendMsg(connfd,buf,BUF_SIZE);
    printf("--show---all--\n");
    free(ptr);
}

char *getFile()
{
    char *buf = (char *)malloc(BUF_SIZE);
    bzero(buf,BUF_SIZE);
    char temp[BUF_SIZE] = {0};
    struct dirent *dfp;

    DIR *dir = opendir("../servBackup");

    while((dfp = readdir(dir))!= NULL)
    {
        if(strncmp(dfp->d_name,".",1)==0||strncmp(dfp->d_name,"..",2)==0)
            continue;
        sprintf(temp,"filename:%s\n",dfp->d_name);
        strcpy(buf+strlen(buf),temp);
    }
    return buf;
}

int checkFile(char *file)
{
    char *ptr = getFile();
    char buf[BUF_SIZE] = {0};
    strcpy(buf,ptr);
    char *p;
    p = strstr(buf,file);
    if(p==NULL)
    {
        free(ptr);
        return -1;
    }else{
        free(ptr);
        return 0;
    }
}