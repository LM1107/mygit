#include <iostream>
using namespace std;

/*
* 纯虚函数：基类的虚函数没有方法实现（也就是没有函数定义），声明时在参数列表后面赋值=0；
*
* 抽象类：含有纯虚函数的类
*
*注意：抽象类没有完整的信息，不能拥有实例（也就是不能定义对象）
*/

class Graphic{
public:
    virtual float Area() = 0;
};

class Triangle : public Graphic
{
public:
    Triangle(){h =3;d=4;}
    float Area(){
        return (h*d)/2;
    }
private:
    int h;
    int d;
};
/*
void test(Graphic &g)
{
    cout<<g.Area()<<endl;
}
*/
int main()
{
    //Graphic g;
    //test(g);
    Triangle t;
    test(t);
}