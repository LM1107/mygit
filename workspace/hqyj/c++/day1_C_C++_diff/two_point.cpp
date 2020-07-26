#include <iostream>
#include <math.h>
using namespace std;

class Point{
public:
    void setx(int x)
    {
        this->x = x;
    }

    void sety(int y)
    {
        this->y = y;
    }

    int getx()
    {
        return x;
    }

    int gety()
    {
        return y;
    }
private:
    int x;
    int y;
};

class Distance{
public:

    //计算距离
    void getDis()
    {
        double dis = sqrt((p2.getx()-p1.getx())*(p2.getx()-p1.getx())+(p2.gety()-p1.gety())*(p2.gety()-p1.gety()));
        cout << dis << endl;
    }

    Point p1;
    Point p2;
};

int main()
{
    Distance d1;
    d1.p1.setx(1);
    d1.p1.sety(1);
    d1.p2.setx(2);
    d1.p2.sety(2);
    d1.getDis();
    return 0;
}