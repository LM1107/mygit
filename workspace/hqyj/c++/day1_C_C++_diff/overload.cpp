#include <iostream>
using namespace std;

#define pri() cout<<__LINE__<<__func__<<endl;
//函数重载：
// 1、函数名形同
// 2、函数参数个数和类型不同
int func()
{
    pri();
    return 0;
}

int func(int x,int y)
{
    pri();
    return x+y;
}

float func(float x,float y)
{
    pri();
    return x+y;
}

int main()
{
    func();
    func(1,2);
    func(1.3,2);
    func(1,2.3);
    //func(1.3,1.2);  C++里面小数默认double类型
    func(float(1.3),float(1.2));
    return 0;
}