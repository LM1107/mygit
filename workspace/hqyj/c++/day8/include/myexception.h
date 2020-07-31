#ifndef _MY_EXCEPTION_H_
#define _MY_EXCEPTION_H_

/*
*   有了.a库后可以删掉
*       .cpp文件和.o文件
*/

#include <iostream>
#include <stdexcept>
using namespace std;

class myException : public exception
{
public:
    myException(const char *err) throw();
    myException(const myException &b) throw();
    ~myException()throw();
    const char * what() throw();
private:
    const char *errmsg;
};

#endif