#include <iostream>
using namespace std;

class B{
public:
    B(){cout<<"B"<<endl;}
    ~B(){cout<<"B XIGOU"<<endl;}
};

class Base{
public:
    Base(){m_A = 100;cout<<"Base n"<<endl;}
    Base(int val):m_A(val){cout<<"Base y"<<endl;}
    void getVal(){
        cout << m_A << endl;
    }
    ~Base(){cout<<"BASE:XIGOU"<<endl;}
    void setVal(){}
    B b;
private:
    int m_A;
};

class Son:public Base
{
public:
/*
* 如果基类没有声明构造函数，派生类构造函数参数初始化列表 隐式调用基类的 构造函数 Base()
* 如果基类已经声明构造函数，派生类和构造函数参数初始化列表，必须显式调用 基类的 构造函数
*
* 所以基类的成员变量 通过派生类的构造函数参数初始化列表进行初始化
*/
    Son(char c,int val):ch(c),Base(val){
        cout<<"Son"<<endl;
    }
    Son(char c):ch(c){cout<<"Son"<<endl;}
    Son(int val):m_A(val),Base(val){}
    ~Son(){cout<<"SON:XIGOU"<<endl;}
    //Son(int val):m_A(val),Base(){}
    void getVal(){
        cout << ch << endl;
    }
    void getCh(){
        cout << m_A << endl;
    }
    Base obb;
private:
    int m_A;
    char ch;
};

/*
* 一般的继承顺序：
*           先基类构造，再派生类构造；
* 析构的顺序：    
*           先派生类析构，再基类析构；
* 若派生类中有成员对象
*   构造顺序：
*           那么先基类构造，再成员对象的构造，最后派生类的构造；
*   析构顺序：
*           先派生类析构，再派生类成员析构，然后基类析构。
* 基类含有成员对象的继承：
*   构造顺序：
*           先对成员对象的构造，然后基类构造，最后派生类构造
*   析构顺序：
*           与构造顺序相反
*/

int main()
{
    Son obj1('a',98);
    //Son obj2('a');
    //Son obj3(99);

    obj1.getVal();
    obj1.Base::getVal();

    //obj2.getVal();
    //obj2.Base::getVal();

    //obj3.getCh();
    //obj3.Base::getVal();
    
    /*
    只有静态成员函数才可以使用
        Son::getVal();
        Base::getVal();
        Son::Base::getVal();
    */
}