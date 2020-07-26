#include <iostream>
using namespace std;

void demo(void)
{
    cout << "this is namespace" << endl;
}

int a = 13;

namespace A{   //命名亦歌声明区A
    int a = 12;
}

namespace myspace{
    void demo(void)
    {
        cout << "this is myspace" << endl;
    }
}

int main()
{
    demo();
    //声明使用myspace名字空间的demo函数
    using myspace::demo;  
    demo();    //访问myspace名字空间的demo函数
    ::demo();  //访问全局域的demo函数

    //不声明直接使用名字空间中的变量或函数
    cout << a << endl;
    cout << A::a << endl;
    demo();
    return 0;
}