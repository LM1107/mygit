#include <iostream>
using namespace std;

class Base1{
public:
    Base1()
    {
        m_A=100;
    }
    int m_A;
};

class Base2{
public:
    Base2()
    {
        m_A=200;
    }
    int m_A;
};

class Son : public Base1,public Base2
{
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }
    int m_C;
    int m_D;
};

int main()
{
    Son s;
    cout << "sizeof s = " << sizeof(s) << endl;
    cout << "Base1 :m_A = " << s.Base1::m_A << endl;
    cout << "Base2 :m_A = " << s.Base2::m_A << endl;
}