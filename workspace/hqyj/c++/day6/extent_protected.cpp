#include <iostream>
using namespace std;

class Father{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class Son : public Father  //共有继承 不写访问权限符，默认私有
{
public:
    void getX(){
        cout << x << endl;   //保护继承，在派生类的内部可以访问基类的公有成员变量
        cout << y << endl;   //保护继承，在派生类的内部可以访问基类的保护成员变量
        //cout << z << endl;   任何权限继承，在派生类的内部都不可以访问基类的私有成员变量
    }
    void setA(){

    }
private:
    int a;
};

int main()
{
    Father obj;
    Son obj1;
    //cout << obj.x << endl;      //保护继承，不能访问基类的共有成员
    //cout << obj.y << endl;  受保护的对象是无法通过点号来访问的
    obj1.getX();
    
    /*共有继承时，
    *   可以将派生类对象 赋值给 基类对象 （隐式向上转换) , 反之错误
    */
    obj = obj1;     //小范围 赋值给 大范围 将派生类类型 隐式转换成基类类型
    obj = Father(obj1); //
    //obj1 = Son(obj);  //大范围不能赋值给小范围

    /*
    obj = obj1;
    obj = Father(obj1);
    obj1 = Son(obj); 
    私有继承时，
    *   不能将派生类对象 赋值给基类对象
    *   也不能把基类对象 赋值给派生类对象
    */
}