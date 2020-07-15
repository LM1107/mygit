#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    struct in_addr ip;
    ip.s_addr = inet_addr("192.168.2.248");
    printf("%u\n",ip.s_addr);
    printf("%s\n",inet_ntoa(ip));
    return 0;
}