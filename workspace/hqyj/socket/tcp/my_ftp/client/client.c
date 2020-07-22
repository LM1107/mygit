#include "client.h"

int TcpServerInit(const char *IP,int port)
{
	//建立socket连接
	int connfd = socket(AF_INET,SOCK_STREAM,0);
	if(connfd < 0)
		PERROR("socket");

	//设置sockaddr_in 结构体中的相关参数
	struct sockaddr_in dest_addr;
	bzero(&dest_addr,sizeof(dest_addr));
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(port);
	dest_addr.sin_addr.s_addr = inet_addr(IP);
	//dest_addr.sin_addr.s_addr = INADDR_ANY;//让系统自动检测本地网卡IP并绑定

	int ret = connect(connfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
	if(ret != 0)//连接成功
        PERROR("connect");
    return connfd;
}

//内部函数
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

int handler(int connfd,char *buf)
{    
    char temp[N] = {0};
    strcpy(temp,buf);
    sendMsg(connfd,temp,N);

    if(0 == strcmp("help", temp) )
    {
        printf("*********************************************\n");
        printf("* help                             #show help\n");
        printf("* show                          #show allfile\n");
        printf("* upload <filename>              #upload file\n");
        printf("* download <filename>          #download file\n");
        printf("* quit                            #quit stuDB\n");
        printf("*********************************************\n");
    }
    else
    if(0 == strcmp("show", temp) )
    {
            return 0;
    }
    else
    if(0 == strncmp("upload", temp,6) )
    {  
        upload(connfd,temp);
        return 0;
    }
    else
    if(0 == strncmp("download", temp,8) )
    {   
        download(connfd,temp);
        return 0;    
    }
    else
    if(0 == strcmp("quit",temp))
        return 1;
    else
        printf("CMD ERR!!!, try help!!!\n");
}

int upload(int connfd,char *temp)
{
    char buf[BUF_SIZE] = {0};
    char file_info[BUF_SIZE] = {0};
    char file_name[N] = {0};

    sscanf(temp,"%*s%s",file_name);

    int fd = open(file_name,O_RDONLY);
    if(fd == -1)
    {
        printf("open [%s] failed",file_name);
        return -1;
    }
    int len = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    sprintf(file_info,"%d",len);
    strcpy(file_info+16,file_name);

    write(connfd,file_info,144);

    while(1)
    {
        bzero(buf,sizeof(buf));
        //读取数据
        
        int ret = read(fd,buf,sizeof(buf));
        
        sendMsg(connfd,buf,ret);

        if(ret == 0)
        {
            printf("send file[%s] succeed!!!!", file_name);
            break;
        }
    }
    close(fd);
    return 0;
}

int download(int connfd,char *temp)
{
    char file_len[16] = {0};//文件长度
	char file_name[128] = {0};//文件名称
	char buf[1024] = {0};//数据缓冲区

    recvMsg(connfd,buf,144);

    strncpy(file_len, buf, sizeof(file_len));//取出文件大小
	strncpy(file_name, buf+sizeof(file_len), sizeof(file_name));//取出文件名称
		
	printf("ready receive!!!! file name:[%s] file size:[%s] \n",file_name, file_len);

    //新的文件名
	sprintf(buf, "%s", file_name);
    
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
