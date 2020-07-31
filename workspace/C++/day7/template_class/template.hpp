#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include <iostream>
using namespace std;

//类模板
template <class T>  //类模板的声明，T主要用来替换类中相同的数据类型。
class Demo{
public:
    Demo(T);
    void setVal(T);
    T getVal();
private:
    int a;
};

template <class B>  //类模板成员函数在类外部定义时，会自动成为模板
Demo<B>::Demo(B x)  //Demo<B>::     表示Demo函数 属于 类模板的作用域，类型模板形参B将会替换T
{
    this->a = x;
}

template <class B>
void Demo<B>::setVal(B x)
{
    a = x;
}

template <class B>
B Demo<B>::getVal()
{
    return a;
}


#endif