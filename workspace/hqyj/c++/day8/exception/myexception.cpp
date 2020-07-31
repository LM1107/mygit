#include <iostream>
#include <stdexcept>
using namespace std;

/*
*   如果要说明函数不会抛出异常，那么要在函数声明，定义两处同时说明noexcept或者throw()s
*/

class myException : public exception
{
public:
    myException(const char *err) throw() : errmsg(err){}
    myException(const myException &b) throw(){}
    virtual ~myException()throw(){}
    const char * what() throw() {return errmsg;}
private:
    const char *errmsg;
};

int func(int x,int y) throw(myException)
{
    if(y != 0)
        return x/y;
    throw(myException("err y == 0"));
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
    try{
        cout << func(a,b) << endl;
    }
    catch(myException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}