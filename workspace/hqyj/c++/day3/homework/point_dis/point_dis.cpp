#include "point_dis.h"

point::point(int x,int y)
{
    this->x = x;
    this->y = y;
}

double getDis(point &p1,point &p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}