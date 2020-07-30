#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class ClockwithDate
{
public:
    ClockwithDate();
    string getTime();
    string change(int);
    int sec;
    int min;
    int hour;
    int day;
    int month;
    int year;
};

ClockwithDate::ClockwithDate()
{
    sec = 1;
    min = 25;
    hour = 18;
    day = 28;
    month = 7;
    year = 2020;    
}

string ClockwithDate::change(int a)
{
    string str;
    stringstream ss;
    ss << a;
    ss >> str;
    return str;
}

string ClockwithDate::getTime()
{
    string str1 = change(year);
    string str2 = change(month);
    string str3 = change(day);
    string str4 = change(hour);
    string str5 = change(min);
    string str6 = change(sec);

    string str = str1 + "-" +str2 + "-" + str3 + " " + str4 + ":" + str5 + ":" + str6;
    return str;
}

int main()
{
    ClockwithDate t;
    cout << t.getTime() << endl;
}