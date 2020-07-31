#include <iostream>
using namespace std;

int main()
{
    double m,n;
    cin>>m>>n;
    try{
        cout << "before dividing" << endl;
        if(n == 0)
        {
            throw -1;    //抛出int类型异常
            cout << "T" << endl;  //不会被执行!!!
        }else
            cout << m/n << endl;
        cout << "after dividing" << endl;
    }
    catch(double d){
        cout << "catch(double)" << d << endl;
    }
    catch(int e){
        cout << "catch(int)" << endl;
    }
    catch(char f)
    {
        cout << "catch(char f)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}