#include "A_prtf_B.h"

A::A(int x)
{
    this->x = x;
}

void A::Show(B &b)
{
    cout<<"A_x = "<<this->x<<endl;
    cout<<"B_x = "<<b.x<<endl;
}

B::B(int x)
{
    this->x = x;
}