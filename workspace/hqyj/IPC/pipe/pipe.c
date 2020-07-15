#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int fd[2] = {0};
    int ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe");
        exit(-1);
    }
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        exit(-1);
    }
    if(pid == 0)
    {
        close(fd[1]);
        //close(fd[0]); 关闭读端，将会导致管道破裂
        char buf[64] = {0};
        while(read(fd[0],buf,sizeof(buf))!=0)
        {
            printf("%s",buf);
            bzero(buf,sizeof(buf));
        }
    }
    else
    {
        close(fd[0]);
        while(1)
        {
            char buf[64] = {0};
            fgets(buf,sizeof(buf),stdin);
            ret = write(fd[1],buf,strlen(buf));
            if(ret < 0)
            {
                perror("write");
                close(fd[1]);
                exit(-1);
            }
        }
    }
}