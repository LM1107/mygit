#include "point_inherit.h"

int main()
{
    Rectangle r(10,10);
    cout << "Rectangle Area = " << r.getArea() << endl;

    Circle c(10,10);
    cout << "Circle Area = " << c.getArea() << endl;
}