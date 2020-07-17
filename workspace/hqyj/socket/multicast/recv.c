#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define N 128
int main(int argc,char *argv[])
{
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd < 0)
    {
        perror("socket");
        exit(-1);
    } 

    struct ip_mreq{
        struct in_addr imr_multiaddr;
        struct in_addr imr_interface;
    };
    struct ip_mreq mreq;
    bzero(&mreq,sizeof(mreq));
    mreq.imr_multiaddr.s_addr= inet_addr("224.10.10.1");
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));

    struct sockaddr_in caddr;
    bzero(&caddr,sizeof(caddr));
    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(12345);
    caddr.sin_addr.s_addr = inet_addr("0.0.0.0");

    bind(sockfd,(struct sockaddr*)&caddr,sizeof(caddr));

    socklen_t caddrlen = sizeof(caddr);
    char buf[N] = {0};
    recvfrom(sockfd,buf,N,0,(struct sockaddr*)&caddr,&caddrlen);
    printf("[%s:%d]\n%s\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port),buf);

    return 0;
}