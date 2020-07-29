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

    Demo operator +(Demo &b)
    {
        Demo temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
        //return Demo(a.x+b.x); //返回一个临时对象，对象名未知，匿名对象
    }
    
    Demo operator +(int num)
    {
        Demo temp;
        temp.x = this->x + num;
        temp.y = this->y + num;
        return temp;
    }

    ostream& operator <<(ostream &out)
    {
        out << this->x;
        return out;
    }
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

int main()
{
    Demo obj1(10,10);
    Demo obj2(10,10);
    Demo obj3 = obj1 + obj2;   //===>  operator+(obj1,obj2);
    Demo obj4 = obj1 + 10;
    obj3.getVal();
    obj4.getVal();
}
