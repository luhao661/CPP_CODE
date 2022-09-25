#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_3_H
#define BCLX12_10_3_H
#include <string>

class Stock
{
private:
    char * str;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const char *p, long n = 0, double pr = 0.0);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show()const;
    const Stock& topval(const Stock& s) const;

    friend std::ostream& operator<<(std::ostream &os,const Stock &s);
//***注***
//如果写成(..., const Stock s)，则程序会调用默认的复制构造函数来初始化对象s，
//后果是此函数结束时调用析构函数，最终会把Stock stocks[STKS]全部释放掉，
//导致后面打印的是乱码，而且在第二次调用析构函数时程序会崩溃
//若一定要写成(..., const Stock s)，则必须定义复制构造函数
};

#endif /*BCLX12_10_3_H*/
