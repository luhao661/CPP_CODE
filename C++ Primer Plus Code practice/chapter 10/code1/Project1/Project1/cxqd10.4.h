#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STOCK1_H_
#define STOCK1_H_

#include <string>

class Stock
{
private:
    std::string m_company;//前面加上m_，作用是防止方法的形参和类成员的名称相同
    long m_shares;
    double m_share_val;
    double m_total_val;
    void set_tot() { m_total_val = m_shares * m_share_val; }
public:
    // default constructor 声明默认构造函数
    Stock();     
    //声明构造函数(可以添加参数默认值)
    Stock(const std::string& co, long n = 0, double pr = 0.0);
    // noisy destructor 声明析构函数
    ~Stock();       
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show() const;//新语法     声明show()不会修改对象
};

#endif
