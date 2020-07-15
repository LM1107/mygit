#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *callback(void *arg)
{
    int i = 10;
    while(i--)
    {
        printf("----starting callback-----\n");
        sleep(1);
    }
    pthread_exit(0); //return (void *)1;
}

int main()
{
    printf("create thread1:\n");
    pthread_t threadID;
    int err;
    pthread_create(&threadID,NULL,callback,NULL);
    pthread_detach(threadID);

    sleep(1);
    pthread_exit(0); //退出main pthread这个线程，但是进程并没退出，所以接着执行后面的线程
    return 0;
}