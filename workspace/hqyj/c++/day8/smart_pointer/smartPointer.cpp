#include <iostream>
using namespace std;

/*
*   智能指针：
*       是一个特殊的类模板，重载了"->" "*" 运算符 实现了C++的自动内存回收机制
*   weak_ptr 弱指针  unique_ptr 独占型指针 shared_ptr 共享指针
*/

void test()
{
    int *p = new int [23];

    delete [] p;
}