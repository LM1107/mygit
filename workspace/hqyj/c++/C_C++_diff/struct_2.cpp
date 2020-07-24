#include <iostream>
using namespace std;

struct Demo{
    //函数声明在结构体内部
    //void setval(int a,int b);
    void setval(int,int);
    void getval();
    //构造函数：函数名与结构体名一致，没有返回值（没有数据类型）
    //作用：    用来初始化结构体变量    
    //          用来定义结构体变量时被系统自动调用，不能被用户调用
    Demo(int a,int b)
    {
        x = a;
        y = b;
        cout<<"这里是构造函数"<<endl;
    }
    Demo()
    {
        cout<<"这里是默认参数构造函数"<<endl;
    }
    Demo(const Demo &d)
    {
        x = d.x;
        y = d.y;
        cout<<"这里是拷贝构造函数"<<endl;
    }

    //析构函数
    ~Demo()
    {
        cout<<"这里是析构函数"<<endl;
    }

private:
    int x,y; 
};

//定义一定要在结构体外
/*
void Demo::setval(int a,int b)
{
        x = a;
        y = b;
}
*/

void Demo::getval()
{
        cout<<"x = "<<x<<" "<<"y = "<<y<<endl;
}

//this指针
void Demo::setval(int x,int y)
{
        this->x = x;  //结构体成员函数提供this指针，指向当前结构体成员
        this->y = y;
}

int main()
{
    Demo obj1(10,12);  //有参构造函数
    Demo obj2;      //默认构造函数调用
    //obj1.setval(10,12);
    Demo obj3(obj1);

    obj1.getval();
    obj3.getval();
    return 0;
}