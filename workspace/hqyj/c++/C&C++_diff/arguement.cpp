#include <iostream>
using namespace std;

//C++中对一个函数的形参 赋初值，叫做函数的默认参数。
//规则：
//      从参数列表的 右边 一次赋初值到 左边，中间不能漏掉一个
int func(int x,int y = 12)
{
    return x+y;
}

/*
int func(int x)  //函数的重载
{
    return x;
}
*/

int func(int x,int y,int z = 10);
{
    return x+y+z;
}

int main()
{
    int sum = func(5);
    cout << "sum: "<<sum<<endl;

    sum = func(1,2);
    cout << "sum: "<<sum<<endl;
}