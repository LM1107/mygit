#include<iostream>
using namespace std;

void showValue(const int &val)
{
    //val = 1000;  加了const以后就不能修改值了。
    cout<<"val = "<<val<<endl;
}

int main()
{
    //常量引用
    //使用场景：用来修饰形参，防止误操作

    int a = 10;
    //int& ref = 10;  引用必须引一块合法的内存空间
    const int & ref = 10;
    //加上const之后 编译器将代码修改为: 
    //int temp = 10;
    //const int & ref = temp;

    int b = 100;
    showValue(b);
    cout<<"b = "<<b<<endl;

    system("pause");   //visual studio 专用，防止一闪而过
    return 0;
}