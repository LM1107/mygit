#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string str1;
    string str2;
    stringstream ss;
    int x;
    cin>>x;
    ss<<x;
    ss>>str;

    cout << str;
}