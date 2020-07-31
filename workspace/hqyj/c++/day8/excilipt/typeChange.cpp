#include <iostream>
using namespace std;

class Base{
public:
    //explicit Base(int x):x(x){}
    Base(int x):x(x){}
    ~Base(){}
    operator int();  //转换函数的声明
    operator int*();
    void prnt(){cout << "x = " << x <<endl;}
private:
    int x;
};

Base::operator int()  //转换函数的定义
{
    return x;   //函数声明定义时不能有数据类型，不代表不能return返回
}

Base::operator int*()
{
    return &x;
}

int main()
{
    Base obj(12);
    Base obj1 = 'a';     //如果 Base(int x) 前面有 explicit 关键字修饰 则此处的隐式转换不成立
    obj1.prnt();
    int a = 10;
    //obj = Base(a);
    //obj.prnt();
    a = obj;        // <---> a = obj.operator int();
    cout << a << endl;

    int *b = obj;
    cout << *b << endl;
}