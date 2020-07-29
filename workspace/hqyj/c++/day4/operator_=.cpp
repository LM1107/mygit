#include <iostream>
#include <string>
using namespace std;

class Demo{
public:
    Demo(){}
    Demo(int n,string s)
    {
        m_age = new int(n);
        name = new string(s);
    }
    ~Demo()
    {
        if(m_age != NULL)
        {
            delete m_age;
            delete name;
            m_age = NULL;
            name = NULL;
        }
    }

    Demo& operator= (Demo &d)
    {
        if(m_age != NULL)
        {
            delete m_age;
            delete name;
            m_age = NULL;
            name = NULL;
        }

        m_age = new int (*d.m_age);
        name = new int (s);

        return *this;

    }

    void prnt()
    {
        cout<<*m_age<<endl;
        cout<<name<<endl;
    }

private:
    int *m_age;
    string name;
};

int main()
{
    Demo obj1("Tom",18);
    Demo obj2("Peter",20);
    Demo obj3("Ken",22);
    obj3 = obj2 = obj1;
    obj2.prnt();
    obj3.prnt();
}