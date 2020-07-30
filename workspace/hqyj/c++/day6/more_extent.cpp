#include <iostream>
using namespace std;

class A{
public:
    A(){cout<<"A"<<endl;}
    ~A(){cout<<"A XIGOU"<<endl;}
    void prnt(){cout<<"TA"<<endl;}
    int a;
private:
};

class B{
public:
    B(){cout<<"B"<<endl;}
    ~B(){cout<<"B XIGOU"<<endl;}
    void prnt(){cout<<"TB"<<endl;}
    int a;
};

/*
*   多重继承中：
*       构造顺序：与继承基类的顺序相关，第一继承的基类构造，第二继承的基类构造，派生类构造
*       析构顺序：与构造顺序相反
*/

class C : public A,public B
{
public:
    C(int x):val(x),A(),B()
    {
        cout<<"C"<<endl;
    }
    ~C(){cout<<"C XIGOU"<<endl;}
    void getVal(){cout<<a<<endl;}
private:
    int val;
};

int main()
{
    C c(10);
    //c.prnt();     //C++多重继承的(名字的)二义性
    c.A::prnt();    //类名::用来解决名字二义性问题
   
    c.B::a = 18;
    c.A::a = 20;
}