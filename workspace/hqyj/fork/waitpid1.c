#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int status;
    printf("Hello\n");
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(-1);
    }
    if(pid == 0)
    {
        printf("BYE\n");
        exit(100);
    }
    else
    {
        if(waitpid(-1,&status,0) > 0)
        {
            if(WIFEXITED(status)!=0)
            {
                printf("%d\n",WEXITSTATUS(status));
            }
        }
    }
    return 0;
}