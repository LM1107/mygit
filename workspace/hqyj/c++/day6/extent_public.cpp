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

class Son : public Father  //共有继承
{
public:
    void getX(){
        cout << x << endl;   //公有继承，在派生类的内部可以访问基类的公有成员变量
        cout << y << endl;   //公有继承，在派生类的内部可以访问基类的保护成员变量
        //cout << z << endl;   任何权限继承，在派生类的内部都不可以访问基类的私有成员变量
    }
    void setA(){

    }
private:
    int a;
};

int main()
{
    Son obj;
    cout << obj.x << endl;
    cout << obj.y << endl;
}