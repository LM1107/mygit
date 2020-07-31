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
    /*定义一个智能指针，指向堆区空间
    shared_ptr<Base> p(new Base);        //在堆区开辟一片 Base类型的空间，然后让智能指针 p 指向该空间

    p->func();      //智能指针 重载了 "*" 和 "->" 两个运算符;  
    */
    shared_ptr<Base> p = make_shared<Base>(Base());
    /*
    *    make_shared 分配内存后，构造函数调用一次，析构函数调用 两次，  保证资源完全回收，比new更加安全
    */
    p->func();
    shared_ptr<Base> pp(p);
    pp->func();
}

int main()
{
    test();
}