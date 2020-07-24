#include "Passwd.h"

int dbInit(char *ID,char *PW)
{
#if 1	
    char *errmsg = NULL;
	sqlite3 *db = NULL;
	int ret = sqlite3_open("servSQL.db",&db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	
    //对于数据库的操作
	char sql[128] = {0};
	sprintf(sql,"select * from user where (id='%s' and Passwd='%s');",ID,PW);
	
    int n = 0; //数据个数
	int m = 0; //每条数据的字段个数
	int i = 0,j = 0,index = 0;
	char **result = NULL;
	ret = sqlite3_get_table(db,sql,&result,&n,&m,&errmsg);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}
	ret = sqlite3_close(db);
	if(ret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(db));
		return -1;
	}	
    if(n!=0)
    {
        return 1;
    }
	return 0;
#endif
}

