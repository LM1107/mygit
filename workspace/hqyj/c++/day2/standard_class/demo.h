#ifndef _DEMO_H_
#define _DEMO_H_

#include <iostream>
using namespace std;

class Demo{         //声明定义一个类
public:
    Demo(int ,int); //声明构造函数
    ~Demo();        //声明析构函数

    void getValue();  //声明一个成员函数
private:
    int x,y;
};

#endif