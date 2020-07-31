#include "template.hpp"

//第一种解决方式，直接包含源文件
//#include "template.cpp"

//第二种解决方法，将.h文件和.cpp文件写在一起，将后缀名改为.hpp文件

int main()
{
    Demo<char> a('a');  //类模板定义对象的使用方法，必须要有<>指定模板替换的类型
    a.setVal('b');
    cout << a.getVal() << endl;
}