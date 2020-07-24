#include "client.h"

int main()
{
    int connfd = TcpServerInit("127.0.0.1",12345);

    printf("Connect success\n");

    int i = 0;
    char ID[N] = {0};
    char PW[N] = {0};
    
    while(1)
    {    
        bzero(ID,sizeof(ID));
        printf("plz input ur ID:\n");
        fgets(ID,N,stdin);
        ID[strlen(ID)-1]='\0';

        bzero(PW,sizeof(PW));
        printf("plz input ur Passwd:\n");
        fgets(PW,N,stdin);
        PW[strlen(PW)-1]='\0';

        int ret = login(connfd,ID,PW);
        if(ret == 1)
            break;
        i++;
        if(i == 3)
        {
            close(connfd);
            return -1;
        }
    }

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
