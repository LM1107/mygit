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
    int ret = 0;
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
        PERROR("sockfd")

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8080);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buf[128] = "HELLO\n";
    int saddr_len = sizeof(saddr);
    ret = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&saddr,saddr_len);
    if(ret < 0)
        PERROR("sendto")

    ret = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&saddr,&saddr_len);
    if(ret < 0)
        PERROR("recvfrom")
    printf("%s\n",buf);

    return 0;
}