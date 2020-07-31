#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
    T m;
};

//class Son:public Base      //错误的，必须要知道父类的T类型，子类才能继承
class Son:public Base<int>
{

};

//如果想灵活指定父类中的T类型，子类也需要类模板
template<class T1,class T2>
class Son2:public Base<T2>
{
public:
    Son2()
    {
        cout << "T1的类型为："<<typeid(T1).name()<<endl;
        cout << "T2的类型为："<<typeid(T2).name()<<endl; 
    }
    T1 b;
};

void test()
{
    Son s;
}

void test2()
{
    Son2<int,char>obj2;
    cout << obj2.b << endl;
    cout << obj2.m << endl;
}

int main()
{
    //test();
    test2();
}