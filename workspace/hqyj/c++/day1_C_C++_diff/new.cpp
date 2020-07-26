#include <iostream>
using namespace std;

int main(int argc,char *argv[])
{
    int *p;
    p = new int; //new在堆区开辟一个int类型的空间，返回空间首地址给p

    *p += 14;
    cout<<*p<<endl;
    delete p;

    p = new int(5); //new在堆区开辟一个int类型空间，并且将5存入空间
    cout<<*p<<endl;
    delete p;   //释放空间

    p = new int[5];
    int i = 0;
    for(i = 0;i < 5;i++)
    {
        p[i] = i;
        cout<<p[i]<<endl;
    }
    delete [] p; //释放p所指向的数组空间
}