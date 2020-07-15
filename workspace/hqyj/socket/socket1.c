#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    //1.创建套接字
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror(socket);
        return -1;
    }

    //2.套接字绑定IP和端口号
    struct sockaddr_in saddr;
    saddr.sin_port = htons(8080);
    saddr,sin_addr.s_addr = inet_addr("192.168.2.248");
    int ret = bind(sockfd,(struct sockaddr*&saddr,sizeof(saddr));
    if(ret<0)
    {
        perror("bind");
        return -1;
    }
    
    //3.设置为监听套接字
    ret = listen(sockfd,20);
    if(ret<0)
    {
        perror("listen");
        return -1;
    }

    //4.等待接收客户端链接
    struct sockaddr_in caddr;
    int len = sizeof(caddr);
    int connfd = accept(sockfd,(struct sockaddr*)&caddr,&len);
    if(connfd<0)
    {
        perror("accept");
        return -1;
    }
    printf("%")
    return 0;
}