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

    friend Demo operator -(Demo &,Demo &);

    void getVal()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

private:
    int x;
    int y;
};


Demo operator -(Demo &a,Demo &b)  //友元运算符重载函数的定义
{
    Demo temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    return temp;
}


int main()
{
    Demo obj1(20,20);
    Demo obj2(10,10);
    Demo obj3 = obj1 - obj2;   //===>  operator+(obj1,obj2);
    obj3.getVal();
}
