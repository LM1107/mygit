#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //int a,b,c;
    // cin>>a;
    // cin>>b;
    // cin>>c;
    // cin >> a >> b >> c;
    // cout<<a<<b<<c<<endl;

    // char buf[13];
    // cin >>buf;
    // cout << buf << endl;
    
    int a = 123456789;
    cout << right << setw(12) << a <<endl;

    cout << showbase <<0xa0 <<endl;
    return 0;
}