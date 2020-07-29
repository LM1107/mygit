#include <iostream>
using namespace std;

template <class T> T add(T,T);

template <class T = int>  //类型模板形参默认初值，没有实际作用，但是C++11这个新标准语法支持
T add(T x,T y)
{
    return x + y;
}

int main()
{
    cout << add(1.2,1.3) << endl;
    cout << add< >(1.2,1.3) << endl;
}