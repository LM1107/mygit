#include <iostream>
using namespace std;
#include "myexception.h"

int func(int x,int y) throw(myException)
{
    if(y != 0)
        return x/y;
    throw(myException("err y == 0"));
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
    try{
        cout << func(a,b) << endl;
    }
    catch(myException &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}