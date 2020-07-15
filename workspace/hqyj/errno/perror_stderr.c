/*************************************************************************
    > File Name: perror_stderr.c
    > Author: lm1107
    > Mail: cdwjlm@163.com 
    > Created Time: 2020年07月11日 星期六 13时06分45秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
	int fd = open("1.txt",O_RDONLY);
	if(fd<0)
	{
		printf("%s\n",strerror(errno));
		printf("%d\n",errno);
	}
	return 0;
}

