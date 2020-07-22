#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(int argc,char *argv[])
{
    int fd = open("/dev/input/mouse0",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        exit(-1);
    }
    char buf[128] = {0};

    fd_set wfd,rfd;

    FD_ZERO(&wfd);
    FD_SET(0,&wfd);
    FD_SET(fd,&wfd);

    struct timeval tm = {2,0};

    while(1)
    {
        rfd = wfd;
        int ret = select(fd+1,&rfd,NULL,NULL,&tm);
        if(ret < 0)
        {
            perror("select");
            continue;
        }else if(ret == 0)
        {
            printf("timeout\n");
            sleep(1);
            continue;
        }else{  //表示 设定时间内 集合中有 可用文件描述符
            if(FD_ISSET(0,&rfd))
            {
                memset(buf,0,sizeof(buf));
                read(0,buf,sizeof(buf));
                printf("keyboard:%s\n",buf);
            }else if(FD_ISSET(fd,&rfd))
            {
                memset(buf,0,sizeof(buf));
                read(fd,buf,sizeof(buf));
                printf("mouse:%s\n",buf);
            }
        }
    }
    return 0;
}