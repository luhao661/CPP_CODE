#define _CRT_SECURE_NO_WARNINGS 1

// acctabc.h  -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;

protected://派生类的成员可以直接访问基类的保护成员，但不能直接访问基类的私有成员
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    Formatting SetFormat() const;
    const std::string& FullName() const 
    { 
        return fullName; 
    }
    long AcctNum() const 
    {
        return acctNum; 
    }
    void Restore(Formatting& f) const;

public:
    AcctABC(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0; //纯虚函数(在抽象基类实现中有定义)
    double Balance() const
    {
        return balance;
    };
    virtual void ViewAcct() const = 0;     //纯虚函数(在抽象基类实现中无定义)
    virtual ~AcctABC()
    {}
};

// Brass Account Class
class Brass :public AcctABC//继承AcctABC类
{
public:
    Brass(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0) : AcctABC(s, an, bal)//成员初始化列表，创建并初始化AcctABC抽象基类对象
    {}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string& s = "Nullbody", long an = -1,
        double bal = 0.0, double ml = 500,
        double r = 0.10);
    BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m)
    {
        maxLoan = m;
    }
    void ResetRate(double r) 
    {
        rate = r; 
    };
    void ResetOwes() 
    {
        owesBank = 0; 
    }
};

#endif
