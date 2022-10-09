#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include "13.11.3.h"

#include <cstring>

/***********************************************************************************/

// DmaABC methods
DmaABC::DmaABC(const char* s = "no data", int r = 0)
{
    label = new char[std::strlen(s) + 1];
    std::strcpy(label, s);
    rating = r;
}

DmaABC::DmaABC(const DmaABC& d)
{
    label = new char[std::strlen(d.label) + 1];
    std::strcpy(label, d.label);
    rating = d.rating;
}

DmaABC::~DmaABC()
{
    delete[]label;
}

void DmaABC::View()const
{}

/***********************************************************************************/

// baseDMA methods
baseDMA::baseDMA(const char* l, int r):DmaABC(l,r)
{}

baseDMA::baseDMA(const baseDMA& rs):DmaABC(rs)
{}

baseDMA::~baseDMA()
{}
    
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
    if (this == &rs)
        return *this;

    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);

    rating = rs.rating;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

/***********************************************************************************/

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
    : baseDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs)
    : baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
    os << (const baseDMA&)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

/***********************************************************************************/

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
    : baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs)
    : baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA::hasDMA(const hasDMA& hs)
    : baseDMA(hs)  //显式使用基类复制构造函数(指向基类的引用可以指向派生类型)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
    if (this == &hs)
        return *this;

    baseDMA::operator=(hs);  //显式调用基类赋值运算符的函数表示法

    //***注***
    //不能写成运算符表示法
    //*this = hs;    //因为这样写调用的是hasDMA::operator=()，会形成递归调用

    delete[] style;         // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
    os << (const baseDMA&)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}

#endif