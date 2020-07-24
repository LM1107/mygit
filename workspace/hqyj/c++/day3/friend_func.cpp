#include <iostream>
using namespace std;

class Demo{
public:
    Demo(int x):x(x){}
    friend void setValue(Demo &obj);
    int y;
private:
    int x;
    static int z;
};

int Demo::z = 13;

void setValue(Demo &obj)   //友元函数在类外部的定义形式 不能有Demo::
{
    //x = 13;         //错误，友元已经打破了类的封装，函数没有this指针。则无法直接访问类的成员
    //y = 14;
    Demo::z = 15;     //正确，友元函数只能通过Demo:: 访问类的静态成员
    
    obj.x = 23;       //正确，友元函数是类对象的朋友，那么在友元函数可以通过对象点号.来访问私有成员
}

int main()
{
    Demo obj(2);
    Demo obj2(obj);
  
    //obj.setValue(obj);      //错误，友元函数打破类的封装，与具体的对象无关，不能对象点号调用
    setValue(obj);
}