/*
*利用NewClock类与Date类定义一个带日期的时钟类 ClockwithDate。
*对该类对象能进行增加减少秒数操作。
*/

#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class NewClock{
public:
    NewClock();
    NewClock(int,int,int);
    int sec;
    int min;
    int hour;
};

NewClock::NewClock()
{
    sec = 1;
    min = 25;
    hour = 18;
}

NewClock::NewClock(int a,int b,int c)
{
    sec = c;
    min = b;
    hour = a;
}

class Date{
public:
    Date();
    Date(int,int,int);
    int day;
    int month;
    int year;
};

Date::Date()
{
    day = 28;
    month = 7;
    year = 2020;
}

Date::Date(int a,int b,int c)
{
    day = c;
    month = b;
    year = a;
}

class ClockwithDate : public NewClock,public Date
{
public:
    ClockwithDate();
    ClockwithDate(int,int,int,int,int,int);
    int plus(int);
    int minus(int);
    string getTime();
    string change(int);
};

ClockwithDate::ClockwithDate(int a,int b,int c,int d,int e,int f):Date(a,b,c),NewClock(d,e,f)
{}

ClockwithDate::ClockwithDate():NewClock(),Date()
{}

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

int ClockwithDate::plus(int x)
{
    int tmp = sec + x;
    if(tmp >= 60)
    {
        sec = tmp - 60;
        min++;
        if(min >= 60)
        {
            min = 1;
            hour++;
            if(hour >= 24)
            {
                hour = 0;
                day++;
                if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                {
                    if(day >= 31)
                    {
                        month++;
                    }
                }else if(month == 2)
                {
                    if(day >= 28)
                    {
                        month++;
                    }
                }else{
                    if(day >= 30)
                    {
                        month++;
                    }
                }
                day = 1;
                if(month > 12)
                {
                    year++;
                }
            }
        }
    }else{
        sec = sec + x;
    }
}

int ClockwithDate::minus(int x)
{
    int tmp = sec - x;
    if(tmp <= 0)
    {
        sec = 60 + tmp;
        min--;
        if(min <= 0)
        {
            min = 59;
            hour--;
            if(hour <= 0)
            {
                hour = 23;
                day--;
                if(day <= 0)
                {
                    month--;
                    if(month <= 0)
                    {
                        month = 12;
                        year--;
                    }
                    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                    {
                        day = 31;
                    }else if(month == 2)
                    {
                        day = 28;
                    }else{
                        day = 30;
                    }
                }
            }
        }
    }else{
        sec = sec - x;
    }
}

int main()
{
    ClockwithDate t(2020,2,28,23,59,59);
    //ClockwithDate t;
    cout << "before plus,t1.Time is " << t.getTime() <<endl; 
    t.plus(5);
    cout << "after plus,Time is " << t.getTime() <<endl;
    t.minus(5);
    cout << "after minus,t1.Time is " << t.getTime() <<endl;
}