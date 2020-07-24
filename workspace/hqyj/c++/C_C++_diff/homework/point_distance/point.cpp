#include "point.h"

void Point::setx(int x)
{
    this->x = x;
}

void Point::sety(int y)
{
    this->y = y;
}

int Point::getx()
{
    return x;
}

int Point::gety()
{
    return y;
}

void Distance::getDis()
{
    double dis = sqrt((p2.getx()-p1.getx())*(p2.getx()-p1.getx())+(p2.gety()-p1.gety())*(p2.gety()-p1.gety()));
    cout << dis << endl;
}