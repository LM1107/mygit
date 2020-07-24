#include <iostream>
using namespace std;

//1、const 修饰类的成员函数，const必须卸载参数列表的后面；
//2、const 修饰的成员函数，表示 函数空间中所有的成员变量都是只读。
//3、const 修饰的成员函数，不能访问类的非const成员

class Demo{
public:
    Demo(int ,int );
    //const void setVal(int ,int );  //声明一个const成员函数
    void setVal(int ,int ) const;
    int getVal() const;
    void display(){}

private:
    const int x; 
    int y;
};

Demo::Demo(int a ,int b):x(a),y(b)
{

}

/*const在前面
const void Demo::setVal(int a,int b)
{
    //x = a;
    y = b;      
}
*/

void Demo::setVal(int a,int b) const //定义一个const成员函数，注意定义时，必须要有const关键字
{
    //x = a;
    //y = b;      //const修饰的函数 不能修改属性
    //y++

    //display();  //display()是一个非const成员
    getVal();     
}


int Demo::getVal() const
{
    return y;  //不是在修改属性，而是将属性返回回去
}

int main()
{
    Demo obj(10,12);
    obj.setVal(4,5);
    cout<<obj.getVal()<<endl;
}