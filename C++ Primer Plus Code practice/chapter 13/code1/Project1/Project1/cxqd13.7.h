#define _CRT_SECURE_NO_WARNINGS 1

// brass.h  -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

// Brass Account Class
class Brass
{
private:
    std::string fullName;//客户姓名
    long acctNum;         //账号
    double balance;       //当前结余
public:
    //创建账号
    Brass(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0);
    //存款
    void Deposit(double amt);
    //(虚方法)取款
    virtual void Withdraw(double amt);
    //当前结余
    double Balance() const;
    //(虚方法)显示账户信息
    virtual void ViewAcct() const;
    //(虚方法)析构函数
    virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
    //最大透支款额
    double maxLoan;
    //透支贷款利率
    double rate;
    //当前的透支总额
    double owesBank;
public:
    //派生类构造函数
    BrassPlus(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0, double ml = 500,
        double r = 0.11125);
    //派生类构造函数(使用基类对象初始化派生类对象)
    BrassPlus(const Brass& ba, double ml = 500,
        double r = 0.11125);
    //(虚方法)
    virtual void ViewAcct()const;
    //(虚方法)
    virtual void Withdraw(double amt);
    //修改客户的最大透支额
    void ResetMax(double m) { maxLoan = m; }
    //修改客户的利率
    void ResetRate(double r) { rate = r; };
    //记录客户所欠银行的金额
    void ResetOwes() { owesBank = 0; }
};

#endif
