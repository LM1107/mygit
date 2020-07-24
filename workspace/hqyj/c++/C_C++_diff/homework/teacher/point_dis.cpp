#include <iostream>
#include <cmath>
using namespace std;

class point{
public:
    point (int ,int);
    double getDis(point &);
private:
    int x,y;
};

point::point(int x,int y)
{
    this->x = x;
    this->y = y;
}

double point::getDis(point &p)
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    //p.x 为什么在此函数中有效
    //在类的成员函数中，可以通过同类型的对象点号访问私有成员
    //同类型的几个对象，都可以通过一个成员函数来访问私有成员数据
}

int main()
{
    point p1(0,3);
    point p2(4,0);
    cout << p1.getDis(p2) << endl;
}