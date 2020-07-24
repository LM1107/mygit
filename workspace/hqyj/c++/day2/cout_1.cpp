#include<iostream>
//如果没有using namespace std; 则后面的代码需要加上std::
//示例： std::cout std::cin
using namespace std;

int main()
{
    cout << "hello"
         << "world"
         << endl;
    cout << "hello"
            "world"
         << endl;

    int a = 123;
    double b = 456.789;
    char c = 'a';
    cout<<a<<b<<c<<endl;
    return 0;
}