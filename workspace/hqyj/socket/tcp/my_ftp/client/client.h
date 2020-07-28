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
#include <dirent.h>

#define BUF_SIZE 1024
#define N 128

#define PERROR(m) { \
        perror(m); \
        return -1; \
    }

int TcpServerInit(const char *IP,int port);
int sendMsg(int connfd,char *buf,int length);
int recvMsg(int connfd,char *buf,int length);
int handler(int connfd,char *temp);
int download(int connfd,char *temp);
int upload(int connfd,char *temp);
int transFile(int connfd,int ffd,int length);
int show(int connfd);
int login(int connfd,char *IDtemp,char *PWtemp);
int checkFile(char *file);
//void loading();

#endif