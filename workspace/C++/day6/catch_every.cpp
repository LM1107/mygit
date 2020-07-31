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
        }else if(m == 0){
            throw -1.0;  //抛出double类型异常
        }else
            cout << m/n << endl;
        cout << "after dividing" << endl;
    }
    catch(double d){
        cout << "catch(double)" << d << endl;
    }
    
    /*atch(int e){
        cout << "catch(int)" << endl;
    }
    catch(char f)
    {
        cout << "catch(char f)" << endl;
    }
    */
    catch(...){
        cout << "catch(...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}