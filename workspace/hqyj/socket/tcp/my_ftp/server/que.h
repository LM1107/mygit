#ifndef _QUE_H_
#define _QUE_H_

typedef int (*HANDLER)(int);

typedef struct node{
    HANDLER handler;
    int fd;
}



#endif