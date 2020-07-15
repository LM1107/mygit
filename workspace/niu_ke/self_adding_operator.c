#include<stdio.h>

int main()
{
    int a = 5;
    //++(a++);
    //++5;    都是错的，++运算符只能对变量使用
    //因为(a++)返回的是一个值--5，所以对5进行自加操作是错误的。
    printf("%d\n",a);
    return 0;
}