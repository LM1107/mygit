
#include "client.h"

int connServer(const char *IP,char *port,int backlog)
{
	//建立socket连接
	int connfd = socket(AF_INET,SOCK_STREAM,0);
	if(connfd < 0)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in saddr;

	//设置sockaddr_in 结构体中的相关参数
	bzero(&saddr,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(port));
	saddr.sin_addr.s_addr = inet_addr(IP);
	
	//绑定函数connect()
    int ret = connect(connfd, (struct sockaddr*)&saddr, sizeof(saddr));
    if(ret < 0)
    {
        perror("connect");
        return -1;
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
    printf("server recv Msg:%s\n",buf);
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
		size += ret;
	}
	return size;
}
