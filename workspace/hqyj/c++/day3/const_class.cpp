#include <iostream>
using namespace std;

class Demo{
public:
    Demo(int ,int );
    void setVal(int ,int ) const;
    int getVal();
    void display(){}
    int z;
private:
    const int x; 
    int y;
};

Demo::Demo(int a ,int b):x(a),y(b)
{

}

void Demo::setVal(int a,int b) const 
{
       
}


int Demo::getVal()
{
    return y; 
}

int main()
{
    const Demo obj(10,12);  //定义初始化一个只读对象
    Demo const obj(2,4);
    obj.setVal(4,5)6363;·
    cout<<obj.getVal()<<endl; //const 修饰的对象，不能访问 非const成员函数
    //cout << obj.z << endl;      //cosnt 修饰的对象，能访问类的共有成员变量，但不能修改
}