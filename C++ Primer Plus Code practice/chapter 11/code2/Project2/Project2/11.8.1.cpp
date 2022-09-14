#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include "11.8.1.h"
#include <iostream>
using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;    // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

Stonewt Stonewt::operator*(double a)const
{
    Stonewt result;


    return result;
}

Stonewt operator*(double a, const Stonewt& st)
{
    return st * a;
}

// conversion functions
Stonewt::operator int() const
{

    return int(pounds + 0.5);//实现对小数部分的四舍五入
                                              //若pounds值为1.4，则返回1
}                                             //若pounds值为1.5，则返回2

Stonewt::operator double()const
{
    return pounds;
}
#endif