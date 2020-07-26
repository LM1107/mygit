#ifndef _POINT_DIS_H
#define _POINT_DIS_H

#include <iostream>
using namespace std;
#include <cmath>

class point{
public:
    point (int ,int);
    friend double getDis(point &,point &);
private:
    int x,y;
};

#endif