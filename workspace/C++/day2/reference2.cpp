#include<iostream>
using namespace std;

//值传递
void mySwap01(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}

//地址传递
void mySwap02(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;    
}

//引用传递
void mySwap03(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    
    //mySwap01(a,b);  值传递，形参不会修改实参
    //mySwap02(&a,&b);  地址传递，形参会修改实参
    mySwap03(a,b);  //引用传递，形参会修改实参
                    //别名可以与原名相同

    cout << "a =" << a << endl;
    cout << "b =" << b << endl;

    system("pause");

    return 0;
}