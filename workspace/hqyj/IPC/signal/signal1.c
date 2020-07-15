#include<signal.h>
#include<stdio.h>

void handler(int sig)
{
    if(sig == SIGINT)
    {
        printf("this is a SIGINT");
        return;
    }
    else if(sig == SIGTSTP)
    {
        printf("this is a SIGTSTP");
        return;
    }

}

int main()
{
    signal(SIGINT,handler);
    signal(SIGTSTP,handler);
    while(1);
    return 0;
}