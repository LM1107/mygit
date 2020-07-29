#include <iostream>
using namespace std;

class basePage{
public:
    void head()
    {
        cout << "juvetus" << endl;
    }
    void foot()
    {
        cout << "real madarid" <<endl;
    }
};

/*
*继承的好处：减少重复代码
*语法： class 子类 : public 父类
*子类 也称为 派生类
*父类 也称为 基类
*/
class Italy : public basePage
{
public:
    void content()
    {
        cout << "ac milan" << endl;
    }
};

class Laliga : public basePage
{
public:
    void content()
    {
        cout << "barcelona" << endl;
    }
};

int main()
{
    Italy club1;
    club1.head();
    club1.content();
    club1.foot();

    Laliga club2;
    club2.head();
    club2.content();
    club2.foot();
    
}