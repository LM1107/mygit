#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

char buf[100];
pthread_mutex_t mutex;

void *callback(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        int i = 0;
        for(;i<20;i++)
            buf[i] = 'b';
        printf("thread:%s\n",buf);
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
}

int main()
{
    pthread_t threadID;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&threadID,NULL,callback,NULL);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        //fgets(buf,sizeof(buf),stdin);
        int i = 0;
        for(;i<20;i++)
        {
            buf[i] = 'a';
        }
        printf("main:%s\n",buf);
        pthread_mutex_unlock(&mutex);
        usleep(100000);
    }
    return 0;
}