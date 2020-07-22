#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <string.h>

#define N 128

int main(int argc,char *argv[])
{
    //1.创建套接字
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("socket");
        return -1;
    }

    //2.套接字绑定IP和端口号
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(12346);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   
    connect(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));

    char buf[N] = {0};
    int ret = 0;
    while(1)
    {
        printf("input> ");
        fgets(buf,N,stdin);
        if(strncmp(buf,"quit\n",5)==0)
            break;
        write(sockfd,buf,strlen(buf));
        bzero(buf,sizeof(buf));
        read(sockfd,buf,sizeof(buf));
        printf("recv from server:%s\n",buf);
    }
    printf("client exit\n");
    close(sockfd);
    return 0;
}