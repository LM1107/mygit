#include"client.h"

int main(int argc, char *argv[])
{
	if(argc<3)
	{
		printf("Usage : %s <ip><port>\n",argv[0]);
		exit(-1);
	}
	int connfd = connServer(argv[1],argv[2],10);
	if(connfd < 0)
		exit(-1);
	
	//等待接收客户端连接
	char buf[N] = {0};
    fgets(buf,N,stdin);
    write(connfd,buf,strlen(buf));
	close(connfd);
	return 0;
}