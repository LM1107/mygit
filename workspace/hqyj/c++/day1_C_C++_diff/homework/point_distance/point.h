#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include <math.h>
using namespace std;

class Point{
public:
    void setx(int x);
    void sety(int y);
    int getx();
    int gety();

private:
    int x;
    int y;
};

class Distance{
public:
    //计算距离
    void getDis();

    Point p1;
    Point p2;
};

#endif