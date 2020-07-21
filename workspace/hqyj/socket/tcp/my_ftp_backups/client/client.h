#ifndef _CLIENT_H_
#define _CLIENT_H_

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

#define BUF_SIZE 1024
#define N 128

#define PERROR(m) { \
        perror(m); \
        return -1; \
    }

//外部函数
void handler(int connfd);
int TcpServerInit(const char *IP,int port);

//内部函数
int sendMsg(int connfd,char *buf,int length);
int download(int connfd,char *filename);
int upload(int connfd,char *filename);   
int transFile(int connfd,int ffd,int length);
int recvMsg(int connfd,char *buf,int length);
//加载函数
//void loading();

#endif