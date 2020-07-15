#include"server.h"

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Usage : %s <ip><port>\n",argv[0]);
		exit(-1);
	}
	int listenfd = TcpServerInit(argv[1],argv[2],10);
	if(listenfd < 0)
		exit(-1);
	
	//等待接收客户端连接
	while(1)
	{
		int connfd = Accept(listenfd);
		if(connfd<0)
		{
			exit(-1);
		}
		char buf[N] = {0};
		recvMsg(connfd,buf,N);

		char str[N] = {0};
		fgets(str,N,stdin);
		write(connfd,str,strlen(buf));

		close(connfd);
	}
	close(listenfd);
	return 0;
}