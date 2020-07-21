#include "server.h"

void handler(int connfd)
{
    char cmd[BUF_SIZE] = {0};
    char filename[N] = {0};
    int ret = read(connfd,cmd,sizeof(cmd));
    if(ret < 0)
    {    
        perror("failed to read cmd");
        return;
    }
    sscanf(cmd,"%*s%s",filename);
#if 1
    if(strncmp(cmd,"upload",6)==0)
    {
        upload(connfd,filename);
    }else{
        return;
    }
#else
    if(strncmp(cmd,"download",8)==0)
    {
        download(connfd,filename);
    }else if(strncmp(cmd,"upload",6)==0)
    {
        upload(connfd,filename);
    }else{
        return;
    }
#endif
    return;
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

//int download(int connfd,char *filename);

int upload(int connfd,char *filename)
{
    char file_len[16] = {0};//文件长度
	char file_name[128] = {0};//文件名称
	char buf[1024] = {0};//数据缓冲区

    recvMsg(connfd,buf,144);

    strncpy(file_len, buf, sizeof(file_len));//取出文件大小
	strncpy(file_name, buf+sizeof(file_len), sizeof(file_name));//取出文件名称
		
	printf("ready receive!!!! file name:[%s] file size:[%s] \n",file_name, file_len);

    //新的文件名
	sprintf(buf, "recv_%s", file_name);
    
    int ffd = open(buf, O_WRONLY | O_CREAT, 0666);
		
	int size = atoi(file_len);//文件大小
	int write_len = 0;//记录已写入的字节数
    
    transFile(connfd,ffd,size);

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