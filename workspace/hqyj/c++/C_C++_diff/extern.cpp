#include <iostream>
using namespace std;

//外部链接
//引用链接一个C语言的函数，要求编译时将函数 所在的.o文件一起编译
extern "C" int add(int,int);

int a =13;

int main()
{
    int a = 12;
    //extern int a;  //引用外部变量 a ; 切记，引用外部变量不能用初值
    cout << a << endl;
    cout << ::a << endl; // ::告诉编译器使用全局作用域的a变量
                         // ::默认全局域
    cout << add(12,5) << endl;
}