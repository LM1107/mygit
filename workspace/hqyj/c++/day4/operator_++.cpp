#include <iostream>
using namespace std;

class Demo{
public:
    Demo(){}
    Demo(int x)
    {
        this->x = x;
    }
    friend Demo operator +(Demo &a,Demo &b);
    
    friend Demo  operator ++(Demo &d,int)
    {
        Demo temp(d.x);
        d.x++;
        return temp;
    }

    friend ostream& operator <<(ostream &out,const Demo &b)
    {
        out << b.x;
        return out;
    }

    friend Demo& operator ++(Demo &d)
    {
        ++d.x;
        return d;
    }

    int getVal()
    {
        return x;
    }
private:
    int x;
};

Demo operator +(Demo &a,Demo &b)  //友元运算符重载函数的定义
{
    Demo temp;
    temp.x = a.x + b.x;
    return temp;
    //return Demo(a.x+b.x); //返回一个临时对象，对象名未知，匿名对象
}

int main()
{
    Demo a(1),b(2);

    Demo c = a + b;

    cout << " c ++ =" << c++ << endl;

    cout << " c = " << c << endl;

    Demo d = a + b;

    cout << " ++d = " << ++d << endl;

}