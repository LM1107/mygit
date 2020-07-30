/*
*5.1定义一个Point类，派生出Rectangle类和Circle类，计算各派生类对象的面积Area（）。
*/

#include "point_inherit.h"

int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}

Point::Point()
{
    x = 0;
    y = 0;
}

int Rectangle::getArea()
{
    int l = (x1 - getX());
    int h = (y1 - getY());
    return l*h;
}

Rectangle::Rectangle(int a,int b)
{
    x1 = a;
    y1 = b;
}

Circle::Circle(int a,int b)
{
    x2 = a;
    y2 = b;
}

double Circle::getArea()
{
    int xr = (x2 - getX());
    int yr = (y2 - getY());
    double r = sqrt(xr*xr + yr*yr);
    return 3.14*r*r;
}
