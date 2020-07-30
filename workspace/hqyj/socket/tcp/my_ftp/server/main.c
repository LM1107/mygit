#include "server.h"

int main(int argc, char *argv[])
{
	int listenfd = TcpServerInit("0.0.0.0",12345,10);
	printf("server is running\n");

	sqlite3 *db = NULL;
	int ret =dbInit(&db);
	if(ret < 0)
	{
		printf("open database failed,please retry connect\n");
		exit(-1);
	}
	pool_init(5);
	while(1)
	{
        //等待接收客户端连接
		int connfd = Accept(listenfd);

		printf("connfd:%d\n",connfd);
        //分情况执行
		pool_add_worker(connfd,db,hhandler);
	}
	dbClose(db);
	close(listenfd);
	return 0;
}

