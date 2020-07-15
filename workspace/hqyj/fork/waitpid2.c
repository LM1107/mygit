#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    pid_t pid2;
    pid_t pid1 = fork();
    if(pid1<0)
    {
        perror("fork");
        exit(-1);
    }
    if(pid1 == 0)
    {
        sleep(10);
        exit(0);
    }
    else
    {
        do{
            pid2 = waitpid(pid1,NULL,WNOHANG);
            if(pid2 == 0)
            {
                printf("No child exited!\n");
                sleep(1);
            }
        }while(pid2 == 0);
        if(pid2 == pid1)
        {
            printf("successfully get child!\n");
        }else{
            printf("some error occured\n");
        }
    }
}