#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
    int ret = 0;
    key_t key = ftok(".",'b');
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int shmid = shmget(key,128,IPC_CREAT|0777);
    if(shmid < 0)
    {
        perror("shmget");
        return -1;
    }
    printf("shmid = %d\n",shmid);
    char *shmp = shmat(shmid,NULL,0);
    if(shmp == (void *)-1)
    {
        perror("shmat");
        return -1;
    }
    //数据处理
    strcpy(shmp,"hello");
    ret = shmdt(shmp);
    if(ret < 0)
    {
        perror("shmdt");
        return -1;
    }
    ret = shmctl(shmid,IPC_RMID,NULL);
    if(ret < 0)
    {
        perror("shmctl");
        return -1;
    }
    return 0;
}        