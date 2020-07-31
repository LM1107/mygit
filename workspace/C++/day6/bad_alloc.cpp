#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    try {
        char * p = new char[0x7fffffff];  //无法分配这么多空间，会抛出异常
    }
    catch (bad_alloc & e)  {
        cerr << e.what() << endl;
    }
    return 0;
}