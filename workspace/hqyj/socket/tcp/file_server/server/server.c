
#include "server.h"

int TcpServerInit(const char *IP,char *port,int backlog)
{
	//建立socket连接
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd < 0)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in servaddr;

	//设置sockaddr_in 结构体中的相关参数
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(port));
	servaddr.sin_addr.s_addr = inet_addr(IP);
	
	//绑定函数bind()
	int ret = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(ret < 0)
	{
		perror("bind");
		exit(-1);
	}

	//调用listen()函数，设置监听模式
	ret = listen(listenfd,backlog);
	if(ret == -1)
	{
		perror("listen");
		exit(-1);
	}
	return listenfd;
}

int Accept(int listenfd)
{
	struct sockaddr_in cliaddr;
	socklen_t addrlen;	
	int connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&addrlen);
	if(connfd < 0)
	{
		perror("accept");
		exit(-1);
	}
	return connfd;
}
		
int recvMsg(int connfd,char *buf,int length)
{
	int ret = 0;
    ret = read(connfd, buf, length);
    if(ret < 0)
    {
        perror("recv");
        exit(-1);
    }
    buf[ret]='\0';
    printf("server recv Msg:%s",buf);
	return 0;
}

int sendMsg(int connfd,char *buf,char *str,int length)
{
	int ret = 0;
	int size = 0;
	while(size<length)
	{
        strcpy(buf,str);
		ret = write(connfd, buf, length);
		if(ret < 0)
		{
			perror("recv");
			exit(-1);
		}
	}
	return 0;
}

#if 0
int sendFile(int sockfd,char *filename)
{

}

int transFile(int sockfd,char *filename)
{

}
#endif