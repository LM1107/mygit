#include <iostream>
using namespace std;

int CountTax(int salary)
{
    try{
        if(salary < 0)
            throw string("zero salary");
        cout << "1.couting tax" << endl;
    }
    catch(string s){
        cout << "2.CountTax error: " << endl;
        throw; //继续抛出捕获的异常
    }
    cout << "3.tax couted" << endl;
    return salary*0.15;
}

int main()
{
    double f = 1.2;
    try{
        CountTax(-1);
        cout << "4.end of try block" << endl;
    }
    catch(string s){
        cout << "5. s = " << s << endl;
    }
    cout << "6. finished" << endl;
}