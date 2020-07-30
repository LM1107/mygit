#include <iostream>
using namespace std;


class A{
public:
    //A(int a):x(a){}
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A
{
public:
    B(){}
    void setVal(int a,int b)
    {
        x = a;
        y = b;
    }
    int m_a;
};

class C : protected A
{
public:
    C(){}
    void setVal(int a,int b)
    {
        x = a;
        y = b;
    }
};

class D : private A
{
public:
    D(){}
    void setVal(int a,int b)
    {
        x = a;
        y = b;
    }
    void getVal()
    {
        cout << x << endl;
        cout << y << endl;
    }
};

int main()
{
    B b;
/*
*父类中所有非静态成员属性都会被子类继承下去
*16
*父类中私有成员属性 是被编译器给隐藏了访问不到，但是确实是被继承下来了
*/
    cout<<"sizeof b = "<<sizeof(b)<<endl;
    b.setVal(10,20);
    cout << b.x << endl;;
    //cout << b.y << endl;  //继承来的受保护的成员变量

    C c;
    c.setVal(10,20);
    //cout << c.x << endl;\

    D d;
    d.setVal(10,20);
    d.getVal();
    //cout << d.x << endl;
}