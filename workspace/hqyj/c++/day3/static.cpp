#include <iostream>
using namespace std;

class Demo{
public:
    Demo(){}
    Demo(int v)
    {
        val = v;
    }
    int getVal();
    static int a；
private:
    static int val;   //声明一个静态的成员变量
};

//静态成员变量，与具体的对象无关，可以用作：
//  同类型的对象之间进行数据传递，也就是所有对象公用一个value
int Demo::val = 13; //静态成员变量，必须在类的外部进行初始化定义

int Demo::getVal()  
{
    return val;
}

int main()
{  
    Demo obj(10);
    cout << obj.getVal() << endl;

    Demo obj1;      //定义一个对象，要求必须重载默认构造函数
    cout << obj1.getVal() << endl;

    //Demo::val = 25;
    //obj.val = 23;     错误的，私有成员不能在外部访问

    Demo::a = 15;     //正确，共有的静态成员变量，与具体对象无关，可以直接Demo::来直接使用
    obj.a = 13;       
}