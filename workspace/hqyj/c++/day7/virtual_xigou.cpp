#include <iostream>
using namespace std;

/*
* 使用虚析构，解决基类指针指向派生类对象，无法彻底回收资源的情况
*/

class Base{
public:
    Base(){cout<<"Base"<<endl;}
    virtual ~Base(){cout<<"Base XIGHOU"<<endl;}
private:

};

class Son : public Base
{
public:
    Son(){cout<<"Son"<<endl;}
    ~Son(){cout<<"Son XIGOU"<<endl;}
private:

};

int main()
{
    Base *p = new Son;
    delete p;
    /*
    * 基类指针指向了派生类对象，而基类中的析构函数是非virtual的，
    *而虚析构函数是动态绑定的基础。现在析构函数不是virtual的，因此
    *不会发生动态绑定，而是静态绑定，指针的静态类型为基类指针，
    *因此在delete的时候只会调用基类的析构函数，而不会调用派生类
    *的析构函数。
    */

    //while(1)
    /*
    * 使用while(1)的时候，阻塞程序的结束，可以排除系统回收的问题
    */
    return 0;
}