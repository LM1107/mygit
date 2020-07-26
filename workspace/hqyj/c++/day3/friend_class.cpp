#include <iostream>
using namespace std;

/*友元类
    如果 A 将 B类当成朋友，
    那么在 B类的所有成员函数中，
    能直接通过 A:: 访问 A 的静态成员
    通过 A 类对象点号，访问A类的所有成员
*/

class A{
public:
    A(int x):x(x)
    {
    }
    void prtxyz()
    {
        cout<<"x = "<<x<<endl;
        cout<<"y = "<<y<<endl;
        cout<<"z = "<<z<<endl;
    }

    friend class B;     //声明 B 是 A 的友元类
    int z;
private:
    int x;
    static int y;
};

int A::y = 13;

class B{
public:
    void prnmasg(A &a)      //如果 B 是 A 的友元类，那么在B类的成员函数中，能够通过A类对象访问A类的所有成员
    {
        a.x = 13;
        A::y = 13;    
        a.z = 24;
    }
};        //声明一个不完整的 B

int main()
{
    B b;
    A a(10);
    b.prnmasg(a);
    a. prtxyz();
}