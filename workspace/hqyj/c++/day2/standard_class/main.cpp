#include "demo.h"

int main()
{
    Demo obj(10,12);  //定义初始化一个对象
    obj.getValue();

    Demo obj1();
    //obj1.getshow()
    Demo obj2(2,1);
    obj2 = obj;  //赋值运算
    obj2.getValue();

    //默认拷贝构造
    Demo obj3 = obj2; //定义一个对象，用obj对象进行初始化

    Demo obj4(obj2);  //采用默认的拷贝构造
    obj4.getValue();

    Demo *p;
    p = &obj4;
    p->getValue();

    Demo *q = new Demo(1,1);
    delete q; //手动释放堆区空间 系统自动调用析构函数回收资源
    //    while(1);
    //  程序结束时，系统自动调用析构函数 来回收资源
}