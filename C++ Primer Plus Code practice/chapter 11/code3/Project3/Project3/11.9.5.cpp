#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
#include "11.9.5.h"

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double pds,Mode form)
{
    if ((form != FLOAT_POUNDS)&&(form!= INTEGER_POUNDS))
    {
        cout << "错误的模式！\n";
        mode= FLOAT_POUNDS;
    }else
    mode = form;

    stone = int(pds) / pds_per_stn;    // integer division 整数除法
                     //求模后得到不满一英石的磅数，加上pds的小数部分
    pds_left = int(pds) % pds_per_stn + pds - int(pds);
    pounds = pds;    
}

// construct Stonewt object from stone, double values
//构造函数重载
Stonewt::Stonewt(int stn, double pds,Mode form)
{
    if (form != STONE)
    {
        cout << "错误的模式！\n";
        mode = STONE;
    }
    else
        mode = form;

    stone = stn;
    pds_left = pds;
    pounds = stn * pds_per_stn + pds;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    mode = FLOAT_POUNDS;
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

/*
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
*/

std::ostream& operator<<(const std::ostream os, const Stonewt st)
{
    if (st.mode == Stonewt::STONE)//***注***友元能访问对象的私有成员，但其不在类作用域内，要用明示常量的话要用作用域解析运算符
        cout << st.stone << " stone, " << st.pds_left << " pounds\n";
    else if (st.mode == Stonewt::FLOAT_POUNDS)
        cout << st.pounds << " pounds\n";
    else if (st.mode == Stonewt::INTEGER_POUNDS)
        cout << int(st.pounds + 0.5) << " pounds\n";
    else
        cout << "mode is invaild ! \n";
}

Stonewt Stonewt::operator+(const Stonewt s)const
{
    /*Stonewt result;

    result.pounds=pounds+s.pounds;

    return result;*/
    return Stonewt(pounds+s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt s)const
{}
Stonewt Stonewt::operator-()const
{}

Stonewt Stonewt::operator*(double x)const
{}

Stonewt operator*(double x, const Stonewt s)
{}

#endif