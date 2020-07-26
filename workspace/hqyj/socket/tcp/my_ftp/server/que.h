#ifndef _QUE_H_
#define _QUE_H_

typedef int (*HANDLER)(int);

typedef struct node{
    HANDLER handler;
    int fd;
    struct node *next;
}linklist;

typedef struct que{
    struct que *head;
    struct que *rear;
}lqueue;

lqueue *createLqueue(void);

int enLqueue(lqueue *lq, int fd);

linklist *deLqueue(lqueue *lq);

#endif