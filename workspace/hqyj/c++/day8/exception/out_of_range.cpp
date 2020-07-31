#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    vector<int> v(10);
    try{
        v.at(100) = 100;    //抛出out_of_range异常
    }
    catch(out_of_range &err){
        cerr << err.what() << endl;
    }
    string s = "hello";
    try{
        char c = s.at(100); //抛出out_of_range异常
    }
    catch(out_of_range &err){
        cerr<<err.what()<<endl;
    }
    return 0;
}