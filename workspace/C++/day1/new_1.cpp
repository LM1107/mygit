
#include<iostream>
using namespace std;

int *func()
{
    //利用new关键字，可以将数据开辟到堆区
    //指针本质也是局部变量，放在栈上，指针指向的数据保存在堆区
    int *p = new int(10);
    return p;
}

int main()
{
    int *p = func();

    cout << *p << endl;
    //如果想要释放堆区的数据，利用关键字delete
    delete p;

    return 0;
}
