#include<iostream>
using namespace std;

//引用做局部变量的返回值
//返回局部变量引用
int& test01()
{
    int a = 10; //局部变量存放在内存四区中的栈区
    return a;
}

//返回静态变量引用
int& test02()
{
    static int a = 20; //静态变量，存放在全局区。
    return a;
}

int main()
{
/*
    int &ref = test01();
    cout<<"ref = "<<ref<<endl;
*/
    int &ref = test02();
    cout<<"ref = "<<ref<<endl;

    test02() = 100;
    //如果函数的返回值是引用，那么该函数调用可以作为左值存在
    cout<<"ref = "<<ref<<endl;
}