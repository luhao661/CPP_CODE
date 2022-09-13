#define _CRT_SECURE_NO_WARNINGS 1

// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
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

    //声明运算符重载函数(属于成员函数)
    Time operator+(const Time& t) const;
    Time operator-(const Time& t) const;
    Time operator*(double n) const;

    //声明一个友元函数(其作为内联函数)(属于非成员函数)
    friend Time operator*(double m, const Time& t)
    {
        return t * m;
    }   

    //声明一个返回ostream对象的友元函数(属于非成员函数)
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};
#endif
