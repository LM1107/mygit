#include <iostream>
using namespace std;
#include <memory>

#define pri() cout<<"line:"<<__LINE__<<" func:"<<__func__<<endl;

class Base
{
public:
    Base(){pri();}
    ~Base(){pri();}
    void func(){pri();}
};

void test()
{
    /*
    *
    *
    */
    
    unique_ptr<Base> p(new Base);
    p->func();
    //unique_ptr<Base> pp(p);  错误，不能将p所指向的空间地址赋值给pp
    //pp->func();                       因为p是独占这个空间
}

int main()
{
    test();
}