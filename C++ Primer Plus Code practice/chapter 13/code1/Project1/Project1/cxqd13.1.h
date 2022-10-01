#define _CRT_SECURE_NO_WARNINGS 1

// tabtenn0.h -- a table-tennis base class
#ifndef TABTENN0_H_
#define TABTENN0_H_

#include <string>
using std::string;

// simple base class
class TableTennisPlayer
{
private:
    string firstname;//***注***string类中确实使用了动态内存分配，
    string lastname;//但这个类没有使用，这个类不需要特别定义复制构造函数，析构函数等函数
    bool hasTable;
public:
    TableTennisPlayer(const string& fn = "none",
        const string& ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};
#endif
