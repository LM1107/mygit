#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 128

int connServer(const char *IP,char *port,int backlog);
int recvMsg(int connfd,char *buf,int length);
int sendMsg(int connfd,char *buf,char *str,int length);

#endif