#include <iostream>
#include <stdexcept>
using namespace std;
class Base
{
    virtual void func() {}
};
class Derived : public Base
{
public:
    void Print() {}
};
void PrintObj(Base & b)
{
    try {
        Derived & rd = dynamic_cast <Derived &>(b);
        //此转换若不安全，会拋出 bad_cast 异常
        rd.Print();
    }
    catch (bad_cast & e) {
        cerr << e.what() << endl;
    }
}
int main()
{
    Base b;
    PrintObj(b);
    return 0;
}