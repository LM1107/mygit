#ifndef _A_PRTF_B_H_
#define _A_PRTF_B_H_

#include <iostream>
using namespace std;

class B;
class A{
public:
    A(int);
    void Show(B &);
private:
    int x;
};

class B{
public:
    friend void A::Show(B &);
    B(int);
private:
    int x;
};

#endif