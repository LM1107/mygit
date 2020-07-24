#include <iostream>
#include <stdio.h>
using namespace std;

class Demo{
public:
    Demo(char ch){
        p = new char [6];   //在堆区new开辟6个字节的数组空间
        *p = ch;            //将ch的数据存入空间
    }
    Demo(Demo &d)           //实现浅拷贝，两个同类型的成员指向同一个兑取
    {
        p = new char [6];
        *p = *d.p;
        cout << "浅拷贝构造函数" << endl;
    }
    ~Demo()
    {
        delete [] p;
        p = NULL;
        cout << "析构函数" << endl;
    }
    void setVal(char ch);
    char* getAddr();
    char getVal();
private:
    char *p;
};

void Demo::setVal(char ch)
{
    *p = ch;
}

char Demo::getVal()
{
    return *p;
}

char* Demo::getAddr()
{
    return p;
}

int main()
{
    Demo obj('a'); 

    Demo obj1(obj);     //默认拷贝构造函数

    obj.setVal('b');
    cout<<obj1.getVal()<<endl;
    //obj的值改变 obj1的值跟着改变 即代表两个指针指向同一个空间
    
    char *addr = obj.getAddr();
    char *addrr = obj1.getAddr();
    printf("%p\n%p\n",addr,addrr);
    //obj1 和 obj 的地址值相同
}