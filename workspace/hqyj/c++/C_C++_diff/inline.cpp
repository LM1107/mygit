#include <iostream>
using namespace std;
inline int func(); //内联函数的声明


int func() 
{
	int a = 10,b = 3;
    int c = a + b;
}
int main()
{
	func(); //程序编译时，系统将函数的代码语句，替换到此处。
}