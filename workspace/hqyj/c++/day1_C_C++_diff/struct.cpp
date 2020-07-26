#include<iostream>
using namespace std;

struct Demo{
    int a;
    int setval(int a);  //函数的声明 表示该函数中能访问结构体的私有成员，受保护的成员

    char getval() //函数声明定义在结构体中
    {
        return c;
    }

protected:  //访问限定符，受保护的的成员
    int b;
    
private:    //访问限定符，私有的成员
    char c;
};

// :: 说明该函数是 Demo 结构体作用域中的，那么在函数中可以访问结构体中的所有成员。
int Demo::setval(int x)  // 结构体中， 成员函数在外部的定义形式  ::是作用域访问符
{
    return b;
}

int main(int argc,char *argv[])
{
    struct Demo obj;
    obj.a = 13;  //a成员是一个共有的成员，反映出结构体默认为public权限

    Demo obj1;   //C++中结构体的新式使用方法，C中无法使用
    //obj1.b = 112;  错误：b成员是受保护的，不能在结构体之外访问
    //obj1.c = 'm';  错误：c成员是私有的，不能在结构体之外的变量访问

}