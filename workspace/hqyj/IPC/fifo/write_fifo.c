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
    int fd = open("myfifo",O_WRONLY);
    if(fd<0)
    {
        perror("open");
        exit(-1);
    }
    while(1)
    {
        char buf[64]={0};
        fgets(buf,sizeof(buf),stdin);
        if(strncmp(buf,"quit",4)==0)
        {
            write(fd,buf,strlen(buf));
            break;
        }
        write(fd,buf,strlen(buf));
    }
    close(fd);
    return 0;
}