#include <iostream>
using namespace std;

int main()
{
    int const a = 12;
    //int const *p = &a;
    int *p = (int *)&a;  //类型强制转换 修改了const 的限定
    *p += 1;  //改变新的存储区域的内容，a的数值不受影响。

    cout<< a <<endl;  //值不变
}