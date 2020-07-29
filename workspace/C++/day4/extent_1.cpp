#include <iostream>
using namespace std;

/*子类继承父类后，当创建子类对象时，也会调用父类的构造函数
*构造顺序：先构造父类，再构造子类
*析构顺序：一般与构造顺序相反
*/
class Base{
public:
    Base(){
        a = 100;
        cout<<"this is Base"<<endl;
    }
    ~Base(){cout<<"this is ~Base"<<endl;}
    void func()
    {
        cout << "Base:func()" << endl;
    }
    static void prnt()
    {
        cout << "Base:prnt()" << endl;
    }
    static int m_a;
    int a;
};
int Base::m_a = 100;

class Son : public Base{
public:
    Son(){
        a = 200;
        cout<<"this is Son"<<endl;
    }
    ~Son(){cout<<"this is ~Son"<<endl;}
    void func()
    {
        cout << "Son:func()" << endl;
    }
    static void prnt()
    {
        cout << "Son:prnt()" << endl;
    }
    int a;
    static int m_a;
};
int Son::m_a = 200;

int main()
{
    Son s;
    cout << s.a << endl;    
    cout << s.Base::a << endl;
    
    //1、通过对象访问
    cout << "from obj:" << endl;
    cout << "Son m_a = " << s.m_a << endl;
    cout << "Base m_a = " << s.Base::m_a << endl;  
    
    //2、通过类名访问
    cout << "from class name:" << endl;
    cout << Son::m_a << endl;
    //第一个::代表通过类名访问 第二个::代表访问父类作用域下
    cout << Son::Base::m_a << endl; 
   
    //通过对象访问
    s.func();
    s.Base::func();
    //如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    //加上一个父类作用域就可以访问父类的同名成员变量

    //通过类名访问
    Son::prnt();
    Son::Base::prnt();
}