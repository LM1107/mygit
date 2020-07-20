/*************************************************************************
    > File Name: main.c
    > Author: lm1107
    > Mail: cdwjlm@163.com 
    > Created Time: 2020年07月20日 星期一 13时30分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

int callback(void *param,int num,char **value,char **name)
{
	int i = 0;
	for(;i<num;i++)
	{
		printf("%s:%s\n",name[i],value[i]);
	}
	return 0;
}

int main(int argc, char *argv[]){
	char *errmsg = NULL;
	sqlite3 *db = NULL;
	int ret = sqlite3_open("test.db",&db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	//对于数据库的操作
	char sql[128] = {0};
	ret = sprintf(sql,"select * from user;");
	int n = 0; //数据个数
	int m = 0; //每条数据的字段个数
	int i = 0,j = 0,index = 0;
	char **result = NULL;
	ret = sqlite3_get_table(db,sql,&result,&n,&m,&errmsg);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	for(i = 0;i < (n+1)*m;i++)
	{
		printf("%s ",result[i]);
	}
	// ret = sqlite3_exec(db,sql,callback,NULL,&errmsg);
	// if(ret != SQLITE_OK)
	// {
	// 	printf("%s\n",sqlite3_errmsg(db));
	// 	return -1;
	// }
	
	ret = sqlite3_close(db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	return 0;
}

