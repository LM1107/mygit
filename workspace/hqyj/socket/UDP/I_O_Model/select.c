#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
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
    saddr.sin_port = htons(8080);
    saddr.sin_addr.s_addr = inet_addr("192.168.2.248");
    int ret = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret<0)
    {
        perror("bind");
        return -1;
    }
    
    //3.设置为监听套接字
    ret = listen(sockfd,5);
    if(ret<0)
    {
        perror("listen");
        return -1;
    }
    int maxfd = sockfd;
    
    fd_set rdfs;
    char buf[N] = {0};
    int i = 0;
    while(1)
    {
        FD_ZERO(&rdfs);
        FD_SET(0,&rdfs);
        FD_SET(sockfd,&rdfs);
        ret = select(maxfd+1,&rdfs,NULL,NULL,NULL);
        if(ret < 0)
        {
            perror("select");
            return -1;
        }
        for(i = 0;i < maxfd;i ++)
        {
            if(FD_ISSET(i,&rdfs))
            {
                if(i == 1)
                {
                    fgets(buf,N,stdin);
                    printf("%s",buf);
                }else if(i == sockfd)
                {
                    //4.等待接收客户端链接
                    int connfd = accept(sockfd,NULL,NULL);
                    printf("New Connection connfd is coming:%d\n",connfd);
                    close(connfd);
                }
            }
        }
    }
    return 0;
}