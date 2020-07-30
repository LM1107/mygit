#ifndef _POINT_INHERIT_H_
#define _POINT_INHERIT_H_

#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
    Point();
    int getX();
    int getY();
private:
    int x;
    int y;
};

class Rectangle : public Point
{
public:
    Rectangle(int ,int );
    int getArea();
private:
    int x1;
    int y1;
};

class Circle : public Point
{
public:
    Circle(int,int);
    double getArea();
private:
    int x2;
    int y2;
};

#endif
