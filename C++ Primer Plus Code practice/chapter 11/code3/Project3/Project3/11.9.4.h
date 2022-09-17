#define _CRT_SECURE_NO_WARNINGS 1

#ifndef bclx11_9_4
#define bclx11_9_4
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);

    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);

    //声明友元(属于非成员函数)
    friend Time operator+(const Time& t1,const Time &t2);
    friend Time operator-(const Time& t1, const Time& t2);
    friend Time operator*(const Time& t1,double mult);
    friend Time operator*(double mult, const Time& t1);//友元函数重载

    //声明一个返回ostream对象的友元函数(属于非成员函数)
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
#endif /*bclx11_9_4*/
