#include <iostream>
using namespace std;

class B{
public:
    B(int i) : data(i){
        cout << "fu zhi" << endl;
    }
    ~B(){
        cout << "xi gou" << endl;
    }
    B(const B &b){
        data = b.data;
        cout << "shallow copy" << endl;
    }
    B &operator=(B &obj)
    {
        cout << "deep copy" << endl;
    }
private:
    int data;
};

B play(B b)
{
    return b;
}

int main()
{
    play(1);
    cout<<endl;
    
    B obj1 = play(2);
    cout << endl; 

    B obj2;
    obj2 = play(3);
    cout << endl;
}