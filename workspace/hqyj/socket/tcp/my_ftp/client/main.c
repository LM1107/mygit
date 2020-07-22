#include "client.h"

int main()
{
    int connfd = TcpServerInit("127.0.0.1",12345);

    printf("Connect success\n");

    while(1)
    {
        printf("ftp> ");
        fflush(stdout);
        char buf[N] = {0};
        fgets(buf,N,stdin);
        buf[strlen(buf)-1]='\0';

        int ret = handler(connfd,buf);
        if(ret == 1)
            break;
        printf("\n");
    }
    close(connfd);
    return 0;
}
