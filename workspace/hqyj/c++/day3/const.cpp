#include <iostream>
using namespace std;

//const 修饰类的成员变量时，只能通过构造函数初始化列表进行初始化

class Demo{
public:
    Demo(int x,int y):x(x),y(y)  //构造函数初始化列表用来初始化成员变量
    {
    //     this->x = x;   错误，成员x是一个只读变量，不能修改
    //     this->y = y;   
    }
    //类外定义版本
    //Demo(int ,int);
    int getVal()
    {
        return x;
    }
    /*void Demo::setVal(){
        x = a;    //错误  const修饰的成员变量，初始化后，不能修改
        y = b;
    }
    参数初始化列表只能在构造函数中使用
    */
private:
    //const int x = 12;   错误，const成员变量不能在声明的时候赋初值
    const int x; 
    int y;
};

//构造函数参数初始化列表的类外定义
//Demo::Demo(int a,int b):x(a),y(b){}

int main()
{
    Demo obj(10,12);
    cout<<obj.getVal()<<endl;
}