#include <iostream>
using namespace std;

/*
*   动态多态满足关系
*   1、有继承关系
*   2、子类重写父类虚函数
*
*   动态多态使用
*       父类的 指针 或者 引用 执行子类对象
*/

class Animal{
public:
    //虚函数
    //加上virtual关键字以后，变成虚函数，那么编译器再编译阶段就不能确定函数调用了
    void virtual speak(){cout<<"Animal"<<endl;}
};

class Cat : public Animal
{
public:
    void speak(){cout<<"cat speak"<<endl;}
};

class Dog : public Animal
{
public:
    void speak(){cout<<"dog speak"<<endl;}
};

void dospeak(Animal &a)
{
    a.speak();
}

/*
*   重写：函数返回值 函数名 参数列表 都必须相同
*   子类重写函数可加 virtual 可不加 不影响结果
*/

int main()
{
    Cat cat;
    dospeak(cat);

    Dog dog;
    dospeak(dog);
}