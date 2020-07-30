#include <iostream>
using namespace std;

class Base{
public:
    //Base(int x):x(x){}
    virtual void funa(void){cout<<"Ta"<<endl;}
    virtual void funb(void){cout<<"Tb"<<endl;}   
    //int x;
};

class Son : public Base
{
public:
    void funa(void){cout<<"B"<<endl;}
    void funb(void){cout<<"B"<<endl;}   
};

typedef void (*PFUN)(void);
int main()
{
    cout<<sizeof(Base)<<endl;
    /*
    Base b(12);
    long vtbl = (*(long*)&b);
    PFUN pfun = (PFUN)*((long*)vtbl);
    pfun();
    pfun = (PFUN)*((long*)vtbl+1);
    pfun();
    cout << *((long*)&b+1) << endl;
    */
}