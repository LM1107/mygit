#include "Passwd.h"

int dbInit(sqlite3 **db)
{	
    char *errmsg = NULL;
	int ret = sqlite3_open("servSQL.db",db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(*db));
		return -1;
	}
	return 0;
}

int dbSelect(char *ID,char *PW,sqlite3 *db)	
{
    //对于数据库的操作
	char sql[128] = {0};
	sprintf(sql,"select * from user where (id='%s' and Passwd='%s');",ID,PW);
	
    int n = 0; //数据个数
	int m = 0; //每条数据的字段个数
	char **result = NULL;
	char *errmsg = NULL;
	int ret = sqlite3_get_table(db,sql,&result,&n,&m,&errmsg);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	if(n!=0)
    {
        return 1;
    }
}

int dbClose(sqlite3 *db)
{
	int ret = sqlite3_close(db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}	
	return 0;
}

