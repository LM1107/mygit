#include <iostream>
using namespace std;
#include <string>

class Demo{
public:
    Demo(){}
    Demo(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    /*成员函数
    Demo operator+ (Demo &d)
    {
        Demo temp;
        temp.x = this->x + d.x;
        temp.y = this->y + d.y;
        return temp;
    }
    */

    friend Demo operator +(Demo &,Demo &);
    
    friend Demo operator +(Demo &,int num);
    
    friend ostream& operator <<(ostream &,Demo &);
    //将要输出的数据 插入到输出流上

    void getVal()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

private:
    int x;
    int y;
};

Demo operator +(Demo &a,Demo &b)  //友元运算符重载函数的定义
{
    Demo temp;
    temp.x = a.x + b.x;
    temp.y = b.y + a.y;
    return temp;
    //return Demo(a.x+b.x); //返回一个临时对象，对象名未知，匿名对象
}

Demo operator +(Demo &a,int num)
{
    Demo temp;
    temp.x = a.x + num;
    temp.y = a.y + num;
    return temp;
}

int main()
{
    /*
    string a = "hello ";
    string b = "world";

    string c(" welcome");

    cout << a+b+c <<endl;
    */
    Demo obj1(10,10);
    Demo obj2(10,10);
    Demo obj3 = obj1 + obj2;   //===>  operator+(obj1,obj2);
    Demo obj4 = obj1 + 10;
    obj3.getVal();
    obj4.getVal();
}
