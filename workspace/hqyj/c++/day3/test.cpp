#include <iostream>
using namespace std;

class Demo{
public:
    void setVal(int x)
    {
        this->x = x;
    }
    int getVal()
    {
        return x;
    }
private:
    int x;
};

int main()
{   
    Demo obj;
    obj.setVal(10);
    cout<< obj.getVal() <<endl;
}