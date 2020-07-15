#include<stdio.h>
#include<unistd.h>

int main(void)
{
    int pid = fork();
    if(pid > 0)
    {
        //父进程
        printf("parent,child id = %d \n",pid);
        sleep(1);
    }
    else if(pid == 0)
    {
        //子进程
        char * const arg[] = {"ls","-1","-a",NULL};
        execv("/bin/ls",arg);
        return 0;
    }
    else
    {
        perror("fork");
        return -1;
    }
    return 0;
}