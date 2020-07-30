#include "que.h"

lqueue *createLqueue(void)
{
	lqueue *lq = (lqueue *)malloc(sizeof(lqueue));//给队列开辟空间
	if(NULL == lq)
		return NULL;
	
	lq->rear = lq->head = (linklist *)malloc(sizeof(linklist));//给链表头节点开辟空间
	if(lq->head == NULL) 
		return NULL;

	lq->head->next = NULL;//表示队列为空
	lq->rear->next = NULL;

	return lq;
}

int enLqueue(lqueue *lq, int fd,sqlite3 *db,HANDLER handler)
{

	//准备新节点
	linklist *new = (linklist *)malloc(sizeof(linklist));
	if(NULL == new)
		return -1;

	new->fd = fd;
	new->db = db;
    new->handler = handler;
	new->next = NULL;

	if(lq->head->next==NULL)
	{
		lq->head->next=new;
		lq->rear->next=new;
	}else{
	//新节点入队，即新节点添加到队尾
		lq->rear->next = new;
		lq->rear = new;//rear指针指向队尾节点(即new节点)
	}
	return 0;
}

linklist *deLqueue(lqueue *lq)
{
	if(lq->head->next == NULL)
		return NULL;
	
	linklist *p = lq->head->next;//p指向队头节点的指针
	lq->head->next = p->next;

	return p;
}

