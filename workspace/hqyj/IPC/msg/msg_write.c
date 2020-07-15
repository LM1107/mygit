/*************************************************************************
    > File Name: msg_write.c
    > Author: lm1107
    > Mail: cdwjlm@163.com 
    > Created Time: 2020年07月13日 星期一 09时29分02秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct my_message{
	long int msg_type;
	char buf[68];
}MMSG;

int main(int argc, char *argv[])
{
	MMSG mmsg;
	int ret = 0;
	key_t key = ftok(".",'b');
	if(key < 0)
	{
		perror("ftok");
		return -1;
	}
	int msgid = msgget(key,IPC_CREAT|0666);
	if(msgid < 0)
	{
		perror("msgget");
		return -1;
	}
	printf("msgid = %d\n",msgid);
	while(1)
	{
	mmsg.msg_type = 100;
	char str[68] = {0};
	fgets(str,sizeof(str),stdin);
	strcpy(mmsg.buf,str);
	int res = msgsnd(msgid,&mmsg,sizeof(MMSG)-sizeof(long int),0);
	if(res < 0)
	{
		perror("msgsnd");
		return -1;
	}
	if(strncmp(str,"end",3)==0)
		break;
	}
	return 0;
}

