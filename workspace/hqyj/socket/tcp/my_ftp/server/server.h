#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libgen.h>
#include <dirent.h>

#define NS 128
#define BUF_SIZE 1024

#define PERROR(m) { \
        perror(m); \
        return -1; \
    }

//外部函数
int handler(int connfd);
int TcpServerInit(const char *IP,int port,int backlog);
int Accept(int listenfd);

//内部函数
int sendMsg(int connfd,char *buf,int length);
int download(int connfd,char *temp);
int upload(int connfd,char *filename);   
int transFile(int connfd,int ffd,int length);
int recvMsg(int connfd,char *buf,int length);
int show(int connfd);
int Login(int connfd,int *t);
//加载函数
//void loading();

#endif

		