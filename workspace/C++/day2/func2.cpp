#include<iostream>
using namespace std;

//占位参数
//返回值类型 函数名（数据类型）()

//目前阶段的占位参数，还用不到，后面高阶学习会用上
//占位参数 还可以有默认参数
//void func(int a,int = 10){}
void func(int a,int)
{
    cout<<"this is fun"<<endl;
}

int main()
{
    func(10,10);
    system("pause");
}