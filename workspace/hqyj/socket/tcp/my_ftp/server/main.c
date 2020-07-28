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

	int t = 0;
	while(1)
	{
		t = 0;
        //等待接收客户端连接
		int connfd = Accept(listenfd);
        //分情况执行
		while(1)
		{
			ret = Login(connfd,&t,&db);
			if(ret == 1)
				break;
			if(t == 3)
			{
				printf("you've tried 3 times,can't login now\n");
				printf("connect close\n");
				close(connfd);
				break;
			}else{
				continue;
			}
			
		}
		if(t != 3)
		{
			while(1)
			{
				ret = handler(connfd);
				if(ret == 1)
				{
					printf("connect close\n");
					close(connfd);
					break;
				}
			}
		}
	}
	dbClose(db);
	close(listenfd);
	return 0;
}

