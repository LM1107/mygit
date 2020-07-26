#include "que.h"

lqueue *createLqueue(void)
{
	lqueue *lq = (lqueue *)malloc(sizeof(lqueue));//给队列开辟空间
	if(NULL == lq)
		return NULL;
	
	lq->rear = lq->front = (linklist *)malloc(sizeof(linklist));//给链表头节点开辟空间
	if(lq->front == NULL) 
		return NULL;

	lq->front->next = NULL;//表示队列为空

	return lq;
}

int enLqueue(lqueue *lq, int fd)
{
	if(NULL == lq)
		return -1;
	
	//准备新节点
	linklist *new = (linklist *)malloc(sizeof(linklist));
	if(NULL == new)
		return -1;
	new->fd = fd;
    new->handler = handler;
	new->next = NULL;

	//新节点入队，即新节点添加到队尾
	lq->rear->next = new;
	lq->rear = new;//rear指针指向队尾节点(即new节点)

	return 0;
}

linklist *deLqueue(lqueue *lq)
{
	if(lq->front->next == NULL)
		return NULL;
	
	linklist *p = lq->front->next;//p指向队头节点的指针
	lq->front->next = p->next;

	return p;
}

