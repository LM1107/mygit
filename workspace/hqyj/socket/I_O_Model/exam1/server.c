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
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");
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
    int maxi = sockfd;
    
    fd_set set;
	fd_set rset;
	FD_ZERO(&rset);
	FD_SET(sockfd, &rset);
	int nready;
	int fd_set[N];

    int i = 0;
    for(i = 0;i < maxi;++ i)
    {
        fd_set[i] = -1;
    }
    fd_set[0] = sockfd;

    char buf[N] = {0};

    int arrlen = 1;

    while(1)
    {
        set = rset;
        nready = select(maxi+1,&set,NULL,NULL,NULL);
        if(nready < 0)
        {
            perror("select");
            return -1;
        }
        if(nready == -1)
		{
			perror("select");
            return -1;
		}
		if(FD_ISSET(sockfd, &set))//查看否有新的客户端请求
		{
			int clifd = accept(sockfd, NULL, NULL);
			if(clifd == -1)
			{
			    perror("accept");
                return -1;
		    }
			for(i = 1; i < N; ++i)
			{ 
				if(fd_set[i] == -1)
				{
					fd_set[i] = clifd;
					break;
				}
			}
			FD_SET(clifd, &rset);
			if(clifd > maxi)
				maxi = clifd;
			arrlen++;
			--nready;
		}
		for(i = 1; i < arrlen; ++i)//轮询数据连接
		{
			int set_fd = fd_set[i];
			if(FD_ISSET(set_fd, &set))
			{
				int n = read(set_fd, buf, 1024);
				if(n == -1)
				{
			        perror("read");
                    return -1;
		        }
				else if(n == 0)//客户端退出，
				{
					FD_CLR(set_fd, &rset);
					close(set_fd);
					fd_set[i] = -1;
				}
                write(set_fd, buf, strlen(buf));
                memset(buf, 0, 1024);
                if(--nready < 0)
				break;
			}
		}
    }
    close(sockfd);
    return 0;
}