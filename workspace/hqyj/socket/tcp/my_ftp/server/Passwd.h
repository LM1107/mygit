#ifndef _PASSWD_H_
#define _PASSWD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int dbInit(sqlite3 **db);

int dbSelect(char *ID,char *PW,sqlite3 *db);

int dbClose(sqlite3 *db);
#endif