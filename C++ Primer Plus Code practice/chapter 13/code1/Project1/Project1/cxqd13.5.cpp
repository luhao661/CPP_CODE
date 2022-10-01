#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include "cxqd13.4.h"
#include <iostream>

//基类的方法
TableTennisPlayer::TableTennisPlayer(const string& fn,
    const string& ln, bool ht) 
    : firstname(fn), lastname(ln), hasTable(ht) //***注***可以不用成员初始化列表，
{}//而是在函数体中进行string对象间的赋值，所以要先对firstname调用默认构造函数再调用赋值运算符重载函数，
//而用成员初始化列表会直接调用复制构造函数，这样效率更高

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

//派生类的方法
RatedPlayer::RatedPlayer(unsigned int r, const string& fn,
    const string& ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{//***注***基类的对象应该在程序进入派生类构造函数之前被创建
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
    : TableTennisPlayer(tp), rating(r)
{
}
#endif