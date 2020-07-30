#ifndef _QUE_H_
#define _QUE_H_

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sqlite3.h>

typedef int (*HANDLER)(int,sqlite3 *);

typedef struct node{
    HANDLER handler;
    int fd;
    sqlite3 *db;
    struct node *next;
}linklist;

typedef struct que{
    struct node *head;
    struct node *rear;
}lqueue;

lqueue *createLqueue(void);

int enLqueue(lqueue *lq, int fd,sqlite3 *db,HANDLER handler);

linklist *deLqueue(lqueue *lq);

#endif