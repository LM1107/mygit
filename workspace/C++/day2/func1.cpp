#include<iostream>
using namespace std;

//函数默认参数
//如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
int func(int a,int b = 10,int c = 10)
{
    return a + b + c; 
}

//1.如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都有默认值。
/*
int func2(int a = 10,int b ，int c )
{
    return a + b + c;
}
*/
//2.如果函数声明有默认值，函数实现的时候就不能有默认参数。
/*
int fun2(int a = 10,int b = 10);
int fun2(int a = 10,int b = 10)
{
    return a + b;
}
*/
int main()
{
    //cout<<func(10)<<endl;
    cout<<func(10,30)<<endl; //以实参为准
    return 0;
}