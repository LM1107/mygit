#ifndef _POOL_H
#define _POOL_H

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <pthread.h>  

/*线程池结构*/  
typedef struct  
{  
    pthread_mutex_t queue_lock;  
    pthread_cond_t queue_ready;  

    /*链表结构，线程池中所有等待任务*/  
    lqueue *que;

    //线程数组
    pthread_t *threadid;

    /*线程池中允许的活动线程数目*/  
    int max_thread_num;  

    /*当前等待队列的任务数目*/  
    int cur_queue_size;  

}CThread_pool;  

int pool_add_worker (void *(*process) (void *arg), void *arg);  

void *thread_routine (void *arg);  

void pool_init(int max_thread_num);

#endif