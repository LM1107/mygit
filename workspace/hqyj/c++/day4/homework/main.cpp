#include "mystring.h"

int main()
{
    myString obj1(28);
    myString obj2(28);
    cin >> obj1 >> obj2;
    //obj1.prnt();
    //obj2.prnt();
    myString obj3 = obj2 - obj1;
    obj3.prnt();
    myString obj4 = obj2 + obj1;
    obj4.prnt();
}