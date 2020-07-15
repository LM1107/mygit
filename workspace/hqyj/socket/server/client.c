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
	
	//调用connet()函数向服务器端建立TCP连接
    int res = connect(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(res < 0)
    {
        perror("connect");
        exit(-1);
    }

	char buf[N] = "HELLO THIS IS CLIENT";
	send(listenfd,buf,N,0);
		if(recv(listenfd,buf,N,0)==-1)
		{
			perror("recv");
			exit(-1);
		}
		printf("recv from server: %s\n",buf);

    close(listenfd);
    exit(0);
}
