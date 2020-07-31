#include <iostream>
using namespace std;

/*
*   reinterpret_cast <newType>(表达式) ： 将一个指针转换成另一个指针类型，或者int类型
*   const_cast<newType>(表达式)：将const类型指针，转换成普通指针
*   static_cast<newType>(表达式) ：将基类的指针转换成派生类的指针。
*   dynamic_cast<newType>(表达式) ：在有虚函数的类中使用
*/

class Base
{
public:
    Base(){x = 10;}
    Base(int x):x(x){}
    ~Base(){}
private:
    int x;
};

class Subclass:public Base{
public:
    Subclass(){}
    Subclass(int a):a(a){}
    ~Subclass(){}
    void prnt(){cout << a << endl;}
private:
    int a;
};

int main()
{
    Base *b = new Base(10);
    Subclass *s;
    s = static_cast<Subclass *>(b);
    s->prnt();
}