#include <iostream>
#include <string.h>
using namespace std;

class myString{
public:
    myString();
    myString(int);
    ~myString();
    friend istream &operator>> (istream& in,myString &m);
    friend myString operator + (myString &s1,myString &s2);
    friend myString operator - (myString &s1,myString &s2);
    void prnt();
private:
    char *arr;
    int len;
};