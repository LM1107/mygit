#include "mystring.h"

myString::myString(){}

myString::myString(int len)
{
    this->len = len;
    this->arr = new char [this->len];
}

myString::~myString()
{
    delete [] arr;
}

void myString::prnt()
{
    cout << this->arr << endl;
}

istream& operator>> (istream& in,myString &m)
{
    char temp[68];
    in>>temp;
    m.len = strlen(temp);
    m.arr = new char [m.len+1];
    strcpy(m.arr,temp);
    return in;
}

myString operator + (myString &s1,myString &s2)
{
    myString temp;
    temp.len = s1.len + s2.len;
    temp.arr = new char [temp.len+1];
    strcpy(temp.arr,s1.arr);
    strcat(temp.arr,s2.arr); 
    return temp;
}

myString operator - (myString &s1,myString &s2)
{
    myString temp;
    int n = strlen(s2.arr);
    temp.arr = new char [s1.len+1];
    strcpy(temp.arr,s1.arr);
    char *ptr = NULL;
    while(1)
    {
        ptr = strstr(temp.arr,s2.arr);
        if(ptr == NULL)
        {
            break;
        }else{
            strcpy(ptr,ptr+n);
        }
    }
    return temp;
}