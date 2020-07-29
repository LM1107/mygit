#include <iostream>
using namespace std;

//类型模板形参
/*template : 关键字， 
    <>：类型模板参数列表: 
        class T:声明类型模板形参,
        T将用来替换数据类型
*/
template <class T,class B> T add(T x,T y);    //函数模板的声明
template <typename T,typename B> T add(T x,T y);  //class 与 typename 等同
/*
template <class T,class B>
T add(T x,T y); //可以换行
*/
template <class T> T add(T x,T y)             //函数模板的定义
{
    return x + y;
}

int main()
{
    //函数模板的隐式调用，自动匹配参数的数据类型
    cout << add(1,2) << endl;
    cout << add(1.2,1.3) << endl;

    //函数模板的显示调用
    cout << add<int>(2,3) <<endl;
    cout << add<float>(2.5,2.5) <<endl;
    cout << add<double>(2.5,1.5) <<endl;
}