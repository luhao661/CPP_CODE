#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// stonewt.cpp -- Stonewt methods
#include <iostream>
#include "11.9.6.h"

using std::cout;
using std::endl;

// construct Stonewt object from double value
Stonewt::Stonewt(double pds)
{
    stone = int(pds) / pds_per_stn;    // integer division 整数除法
                     //求模后得到不满一英石的磅数，加上pds的小数部分
    pds_left = int(pds) % pds_per_stn + pds - int(pds);
    pounds = pds;
}

// construct Stonewt object from stone, double values
//构造函数重载
Stonewt::Stonewt(int stn, double pds)
{
    stone = stn;
    pds_left = pds;
    pounds = stn * pds_per_stn + pds;
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
void Stonewt::show_pds() const
{
    cout << pounds << " pounds\n";
}

std::istream& operator>>(std::istream& is, Stonewt& st) 
{
    is >> st.pounds;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
    os << st.pounds<<endl;

    return os;
}

bool Stonewt::operator<(const Stonewt& s)const
{
    //return pounds < s.pounds ? true : false;
    //或写为
    return pounds < s.pounds;
}

bool Stonewt::operator<=(const Stonewt& s)const
{
    return pounds <= s.pounds ? true : false;
}

bool Stonewt::operator>(const Stonewt& s)const
{
    return pounds > s.pounds ? true : false;
}

bool Stonewt::operator>=(const Stonewt& s)const
{
    return pounds >= s.pounds ? true : false;
}

bool Stonewt::operator==(const Stonewt& s)const
{
    return pounds == s.pounds ? true : false;
}

bool Stonewt::operator!=(const Stonewt& s)const
{
    return pounds != s.pounds ? true : false;
}

#endif