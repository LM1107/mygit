#include "pool.h"
#include "que.h"

//线程池对象指针
CThread_pool *pool = NULL;  

//添加任务
int pool_add_worker (int fd,sqlite3 *db,HANDLER handler)
{
    //上锁
    pthread_mutex_lock (&(pool->queue_lock));
    enLqueue(pool->que,fd,db,handler);

    //当前任务数加一
    pool->cur_queue_size++;  

    //好了，等待队列中有任务了，唤醒一个等待线程；
    //注意如果所有线程都在忙碌，这句没有任何作用
    pthread_cond_signal (&(pool->queue_ready));   //使条件成立 （给信号）


    pthread_mutex_unlock (&(pool->queue_lock)); //解锁

   }

//线程执行
void *thread_routine (void *arg)
{
    while (1)  
    {  
          
        //如果等待队列为0并且不销毁线程池，则处于阻塞状态; 注意 
        //pthread_cond_wait是一个原子操作，等待前会解锁，唤醒后会加锁
        if(pool->cur_queue_size <= 0)  
        {
            pthread_mutex_lock (&(pool->queue_lock));  
            printf ("thread id:%#x is waiting\n", (int)pthread_self ());  
            pthread_cond_wait (&(pool->queue_ready), &(pool->queue_lock));  
            //等待 任务加入任务队列
        }else{ 

            printf ("thread id:%#x is starting to work\n", (int)pthread_self ()); 
    /*
            assert (pool->cur_queue_size != 0);  //如果任务队列 长度为0 终止
            assert (pool->que->head->next == NULL);   //如果head为空  终止
    */
            //等待队列长度减去1，并取出链表中的头元素
            pool->cur_queue_size--;  
            //出队
            linklist *temp = deLqueue(pool->que);
            //解锁
            pthread_mutex_unlock (&(pool->queue_lock));

            //调用函数指针，执行任务
            temp->handler(temp->fd,temp->db);  
            free (temp);  //销毁这个节点
            temp = NULL;
        }  
    }
}

//线程池初始化
//初始化 条件变量 互斥锁 任务队列
void pool_init(int max_thread_num)
{
    pool = (CThread_pool *) malloc (sizeof (CThread_pool));  

    pthread_mutex_init (&(pool->queue_lock), NULL);  
    pthread_cond_init (&(pool->queue_ready), NULL);  

    pool->que = createLqueue();

    pool->max_thread_num = max_thread_num;  
    pool->cur_queue_size = 0;  

    pool->threadid = (pthread_t *) malloc (max_thread_num * sizeof (pthread_t));  
    
    //根据参数创建多个线程
    int i = 0;  
    for (i = 0; i < max_thread_num; i++)  
    {   
        pthread_create (&(pool->threadid[i]), NULL, thread_routine,NULL);  
    }
}