#include <iostream>
using namespace std;
#include <string>

class Demo{
public:
    Demo(){}
    Demo(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    friend ostream& operator <<(ostream &cout,Demo &);

private:
    int x;
    int y;
};


ostream& operator <<(ostream &out,Demo &b)
{
    out << "x = " << b.x;
    out << " y = " << b.y;
}

int main()
{
    Demo obj1(20,20);
    cout << obj1 << endl;
}
