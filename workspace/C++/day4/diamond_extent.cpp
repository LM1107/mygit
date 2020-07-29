#include <iostream>
using namespace std;

class animal{
public:
    int m_Age;
private:
};

/*
*利用虚继承 解决菱形继承的问题
*语法：继承之前 加上关键字 virtual 变为虚继承
*Animal类称为 虚基类
*vbptr需基类指针 ---> vbtable虚基类表
*v-virtual b-base ptr-pointer
*虚基类继承实质为继承指针，然后通过指针偏移来得到m_Age
*/
class sheep :virtual public animal
{

};

class camel :virtual public animal
{

};

class alpaca : public sheep,public camel
{

};

int main()
{
    alpaca al;
    al.camel::m_Age = 18;
    al.sheep::m_Age = 20;

    cout<<"al.camel::m_Age = "<<al.camel::m_Age<<endl;
    cout<<"al.sheep::m_Age = "<<al.sheep::m_Age<<endl;
    cout<<"al.m_Age = "<<al.m_Age<<endl;

}