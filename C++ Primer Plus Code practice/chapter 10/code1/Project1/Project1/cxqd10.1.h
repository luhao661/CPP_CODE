#define _CRT_SECURE_NO_WARNINGS 1

// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>  

class Stock  // class declaration 类声明，此类设计被标记为Stock
{
private://私有接口
    std::string company;//公司名称     //类成员
    long shares;//所持股票数量
    double share_val;//每股的价格
    double total_val;//股票总值
    void set_tot() { total_val = shares * share_val; }

public://公共接口
    void acquire(const std::string& co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};    // note semicolon at the end

#endif   /*STOCK00_H_*/