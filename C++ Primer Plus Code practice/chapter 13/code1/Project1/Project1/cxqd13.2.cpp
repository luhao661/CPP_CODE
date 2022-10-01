#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//tabtenn0.cpp -- simple base-class methods
#include "cxqd13.1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string& fn,
    const string& ln, bool ht) : firstname(fn), lastname(ln), hasTable(ht) 
{}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
#endif