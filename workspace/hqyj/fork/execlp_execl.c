#include<stdio.h>
#include<unistd.h>

int main()
{
    if(fork()==0)
    {
        //int ret = execlp("ls","ls","-l",NULL);
        int ret = execl("/bin/ls", "ls", "-l", NULL);
        if(ret<0)
        {
            //perror("execlp");
            perror("execl");
            return -1;
        }
    }else{
        printf("hello\n");
        sleep(1);
    }
    return 0;
}