#include <iostream>
#include <stdexcept>
using namespace std;

//C++新版本中，默认每一个函数都可能会抛出invalid argument
//如果该函数不会抛出异常，用throw() 或者使用  noexcept
int func(int x,int y) throw(invalid_argument)
{
    if(y != 0)         //错误检查
        return (x/y);
    //已经确定错误,throw抛出异常
    //抛出一个 无效参数类型的异常，异常错误信息为：error y== 0
    throw(invalid_argument("error:y==0"));   //抛出一个临时对象
    //抛出异常时，就会结束该函数的运行，相当于return 

    /*
    invalid_argument temp("error:y==0");
    throw(temp);
    * 抛出一个局部对象 也可以
    */
}

int main()
{
    int a,b;
AA:
    cin>>a>>b;
    try{
        cout << func(a,b) << endl;  
    }
    catch(invalid_argument &e)  //捕获 throw抛出的异常
    {
        cout << e.what() << endl;  //打印异常错误信息
        //此后可以进行异常错误处理
        goto AA;    //错误处理
    }
    cout << "T" << endl;
    return 0;
}