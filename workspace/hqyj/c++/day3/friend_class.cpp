#include <iostream>
using namespace std;

/*  如果A把B的某个成员函数当成朋友，
    那么B类的这个成员函数能直接访问A类的静态成员
    通过A类对象，能访问A类的所有成员
*/

class B{
public:
    void prnmasg(A &a)      //如果 B 是 A 的友元类，那么在B类的成员函数中，能够通过A类对象访问A类的所有成员
    {
        a.x = 13;
        A::y = 13;    
        a.z = 24;
    }
};        //声明一个不完整的 B

class A{
public:
    A(int x):x(x)
    {
    }
    friend class B;     //声明 B 是 A 的友元类
    int z;
private:
    int x;
    static int y;
};

int A::y = 13;

int main()
{

}