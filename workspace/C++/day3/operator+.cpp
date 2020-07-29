#include <iostream>
using namespace std;

//运算符重载，也可以发生函数重载

//对于内置的数据类型的表达式的运算符是不可能重载的
//  自定义的才可以用运算符重载

//不要滥用运算符重载

class Person{
public:
    //通过成员函数重载加号运算符+
    Person operator+ (Person &p)
    {
        Person temp;
        temp.m_A = this->m_A+p.m_A;
        temp.m_B = this->m_B+p.m_B;
        return temp;
    }

    //函数重载版本
    Person operator+ (int num)
    {
        Person temp;
        temp.m_A = this->m_A+num;
        temp.m_B = this->m_B+num;
        return temp;
    }
    
    void prnt()
    {
        cout << m_A << endl;
        cout << m_B << endl;
    }

    int m_A;
    int m_B;
};

/*  通过全局函数来重载加号运算符+
Person operator+ (Person p1,Person p2)
{
    Person temp;
    temp.m_A = p1.m_A+p2.m_A;
    temp.m_B = p1.m_B+p2.m_B;
    return temp;
}
*/

int main()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;

    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    Person p3 = p1 + p2;
    
    //成员函数重载的本质：Person p3 = p1.operator+(p2);
    //全局函数重载的本质：Person p3 = operator(p1,p2);
    
    Person p4 = p3 + 10;

    p3.prnt();
    p4.prnt();
}