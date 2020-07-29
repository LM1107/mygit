#include <iostream>
using namespace std;

/*
*   注意：
*       1、函数返回值，如果返回的是已经存在的对象的数据，不是局部的
*       2、在类体之外，要能改变类体中的成员数据
*       3、运算符重载函数应该返回 引用类型
*/

class Demo{
public:
    Demo(){}
    Demo(int x)
    {
        this->x = x;
        this->arr = new int[this->x];
    }
    int* operator[] (int i)
    {
        if(i < this->x)
        {
            return arr[i];
            //return (this->arr+i);
        }else{
            exit(-1);
        }
    }
private:
    int x;
    int *arr;
};

int main()
{
    Demo c(12);
    int i = 0;
    for (i = 0;i < 12;i++)
    {
        c[i] = i;
    }
    for (i = 0;i < 12;i++)
    {
        cout << c[i] <<" ";
    }
}