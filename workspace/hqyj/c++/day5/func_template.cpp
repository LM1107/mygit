#include <iostream>
using namespace std;

//函数模板的非类型模板形参，只能是int类型/指针/引用
template<clss T,int>T add(T,T);

//len:非类型模板形参名，常用来 指定数组空间大小
template<clss T,int len>   //开辟的空间大小由 非类型模板形参len决定，由调用该函数时，传递的数据决定
T add(T x,T y)
{
    T *buf = new T(len);
    return x + y;
}

int main()
{
    cout << add<int,12>(1,2) <<endl;
}
