#include <iostream>
using namespace std;

class Demo{
public:
    Demo(){}
    Demo(int v)
    {
        val = v;
    }
    static int getVal();  //声明一个静态成员函数
private:
    static int val;   //声明一个静态的成员变量
    int y;
};

//静态成员变量，与具体的对象无关，可以用作：
//  同类型的对象之间进行数据传递，也就是所有对象公用一个value
int Demo::val = 13; //静态成员变量，必须在类的外部进行初始化定义

int Demo::getVal()  
{
    //return y;   //静态成员函数与具体的对象无关，函数中没有this指针 所以不能访问类的非静态成员
    return val;   //正确val为类的静态成员。
}

int main()
{  
    Demo obj(10);
    cout << obj.getVal() << endl;

    Demo obj1;      //定义一个对象，要求必须重载默认构造函数
    cout << obj1.getVal() << endl;
}