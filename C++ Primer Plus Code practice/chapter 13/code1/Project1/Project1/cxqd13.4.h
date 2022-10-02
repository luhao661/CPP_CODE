#define _CRT_SECURE_NO_WARNINGS 1

// tabtenn1.h -- a table-tennis base class
#ifndef TABTENN1_H_
#define TABTENN1_H_

#include <string>
using std::string;
// simple base class 基类
class TableTennisPlayer
{
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string& fn = "none",
        const string& ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};

// simple derived class 派生类
class RatedPlayer : public TableTennisPlayer//公有派生
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string& fn = "none",
        const string& ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned int r) { rating = r; }
};

#endif
