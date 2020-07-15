/*************************************************************************
    > File Name: server.c
    > Author: lm1107
    > Mail: cdwjlm@163.com 
    > Created Time: 2020年07月14日 星期二 23时42分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 128

int main(int argc, char *argv[]){
	if(argc<3)
	{
		printf("Usage : %s <ip><port>\n",argv[0]);
		exit(-1);
	}

	struct sockaddr_in servaddr;

	//建立socket连接
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	printf("listenfd = %d\n",listenfd);

	//设置sockaddr_in 结构体中的相关参数
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);
	
	//绑定函数bind()
	int ret = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(ret < 0)
	{
		perror("bind");
		exit(-1);
	}
	printf("bind success!\n");

	//调用listen()函数，设置监听模式
	ret = listen(listenfd,10);
	if(ret == -1)
	{
		perror("listen");
		exit(-1);
	}

	printf("Listening....\n");

	struct sockaddr_in cliaddr;
	char buf[N] = {0};
	socklen_t addrlen;	
	while(1)
	{
		int connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&addrlen);
		if(connfd < 0)
		{
			perror("accept");
			exit(-1);
		}

		if(recv(connfd,buf,N,0)==-1)
		{
			perror("recv");
			exit(-1);
		}
		printf("received msg : %s\n",buf);

		strcpy(buf,"HELLO THIS IS SERVER\n");
		send(connfd,buf,N,0);
		close(connfd);
	}
	close(listenfd);
	exit(0);
}
