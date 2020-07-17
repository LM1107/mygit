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
    
    struct sockaddr_in caddr;
    bzero(&caddr,sizeof(caddr));
    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(12345);
    caddr.sin_addr.s_addr = inet_addr("224.10.10.1");

    char buf[N] = "HELLO THRER!\n";
    sendto(sockfd,buf,N,0,(struct sockaddr*)&caddr,sizeof(caddr));
    printf("[%s:%d]\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));

    return 0;
}