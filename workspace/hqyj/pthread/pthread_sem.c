#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char buf[100];
sem_t sem_w;
sem_t sem_r;

void *read_buf(void *arg)
{
    while(1)
    {
        sem_wait(&sem_w);
        printf("resv: %s",buf);
        sem_post(&sem_r);
        if(strncmp(buf,"quit",4)==0)
            pthread_exit(0);
    }
}

void *write_buf(void *arg)
{
    while(1)
    {
        sem_wait(&sem_r);
        fgets(buf,sizeof(buf),stdin);
        sem_post(&sem_w);
        if(strncmp(buf,"quit\n",5)==0)
            pthread_exit(0);
    }
}

int main()
{
    pthread_t threadID1;
    pthread_t threadID2;
    int ret = pthread_create(&threadID1,NULL,read_buf,NULL);
    if(ret < 0)
    {
        perror("pthread_create");
        exit(-1);
    }
    ret = pthread_create(&threadID2,NULL,write_buf,NULL);
    if(ret < 0)
    {
        perror("pthread_create");
        exit(-1);
    }
    int res = sem_init(&sem_w,0,0);
    if(res < 0)
    {
        perror("sem_init");
        exit(-1);
    }
    res = sem_init(&sem_r,0,0);
    if(res < 0)
    {
        perror("sem_init");
        exit(-1);
    }
    sem_post(&sem_r);
    pthread_join(threadID1,NULL);
    pthread_join(threadID2,NULL);
    return 0;
}
