#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
    int ret = mkfifo("myfifo",0777);
    if(ret < 0 && errno != EEXIST)
    {
        perror("mkfifo");
        exit(-1);
    }
    int fd = open("myfifo",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        exit(-1);
    }
    while(1)
    {
        char buf[64]={0};
        read(fd,buf,sizeof(buf));
        if(strncmp(buf,"quit",4)==0)
            break;
    }
    close(fd);
    return 0;
}