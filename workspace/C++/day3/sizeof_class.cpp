#include <iostream>
using namespace std;

class Person{

};

class Demo{
    int m_Age;
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