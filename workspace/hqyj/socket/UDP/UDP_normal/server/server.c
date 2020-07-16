#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PERROR(m) { \
        perror(m); \
        return -1; \
    }

int main()
{
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
        PERROR("sockfd")

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8080);
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");

    int ret = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
    if(ret < 0)
        PERROR("bind")
    
    char buf[128] = {0};
    struct sockaddr_in caddr = {0};
    int caddr_len = sizeof(caddr);
    ret = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&caddr,&caddr_len);
    if(ret < 0)
        PERROR("recvfrom")
    printf("%s\n",buf);
    printf("客户端的IP:%s",inet_ntoa(caddr.sin_addr));
    printf("客户端的端口号:%d",ntohs(caddr.sin_port));
    return 0;
}