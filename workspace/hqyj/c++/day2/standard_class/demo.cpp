#include "demo.h"

Demo::Demo(int x,int y)
{
    this->x = x;
    this->y = y;
    cout<<"这是构造函数"<<endl;
}

Demo::~Demo()
{
    cout<<"这是析构函数"<<endl;
}

void Demo::getValue()
{
    cout<<this->x<<endl;
    cout<<this->y<<endl;
}