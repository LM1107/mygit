#include "server.h"

int main(int argc, char *argv[])
{
	int listenfd = TcpServerInit("0.0.0.0",12345,10);
	printf("server is running\n");

	while(1)
	{
        //等待接收客户端连接
		int connfd = Accept(listenfd);
        
        //分情况执行
		handler(connfd);

		close(connfd);
	}
	close(listenfd);
	return 0;
}

