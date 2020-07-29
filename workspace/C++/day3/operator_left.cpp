#include <iostream>
using namespace std;

class Person{
public:
    
    //    Person operator<< (cout){}
    
    /*利用成员函数重载左移运算符，
    调用时的本质为：p.operator<<(cout)
    简化版本 p<<cout; 不是想要达到的效果
    所以不会利用成员函数重载<<运算符*/

    friend ostream& operator<< (ostream &cout,Person p);

    Person(int a,int b):m_A(a),m_B(b){}

private:
    int m_A;
    int m_B;
};

/*只能利用全局函数重载<<运算符
  因为cout全局只能有一个，不能创建一个新的出来，所以需要用引用
  本质：operator<<(cout,p); 简化：cout<<p;*/
ostream& operator<< (ostream &cout,Person p)
{
    cout << "m_A = "<<p.m_A<<" m_B = "<<p.m_B;
    return cout;
}

int main()
{
    Person p(10,10);

    cout << p <<endl;
}
