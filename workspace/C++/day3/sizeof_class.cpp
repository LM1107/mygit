#include <iostream>
using namespace std;

class Person{

};

class Demo{
    int m_Age;
    short c;    //满足字节序对齐
    char a;
public:
    void prnf() const{
        cout << "Heloo" << endl;
    }
};

void test01()
{
    Person p;
	cout<<"sizeof Person = "<<sizeof(p)<<endl;
}
void test02()
{
   	Demo obj;
    cout<<"sizeof obj = "<<sizeof(obj)<<endl;
}

int main()
{
	test01();
    test02();
}