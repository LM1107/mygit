#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int fd[2] = {0};
    int ret = pipe(fd);
    int count = 0;
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
        while(1)
        {
            char buf[64] = {0};
        }
    }
    else
    {
        close(fd[0]);
        while(1)
        {
            char buf[1] = {'a'};
            ret = write(fd[1],buf,1);
            if(ret < 0)
            {
                perror("write");
                close(fd[1]);
                exit(-1);
            }
            count += ret;
            printf("%d\n",count);
        }
    }
}