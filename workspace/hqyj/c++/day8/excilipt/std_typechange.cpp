#include <iostream>
using namespace std;

class Base{
public:
    Base(int x):x(x){}
    ~Base(){}
private:
    int x;
};

int main()
{
    //const char *p = "he";
    //char *p = "he";
    
    char *p = new char[6];
    *p = 'A';

    cout << p << endl;

    //int a = reinterpret_cast<int>(p);  64位不行
    int *b = reinterpret_cast<int *>(p);

    //cout << a << endl;
    cout << "b = " << b << endl;

    Base *q = new Base(5);
    int *m = reinterpret_cast<int *>(q);
    cout << "*m = " << *m << endl;

    const char *p2 = "hello world";
    char *p3 = const_cast<char *>(p2);
    cout << "P3 = " << p3 << endl;
}