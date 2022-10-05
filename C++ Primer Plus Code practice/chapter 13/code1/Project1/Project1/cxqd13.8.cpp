#define _CRT_SECURE_NO_WARNINGS 1

#if 0
// brass.cpp -- bank account class methods
#include <iostream>
#include "cxqd13.7.h"

using std::cout;
using std::endl;
using std::string;

// Brass methods

Brass::Brass(const string& s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; "
        << "deposit is cancelled.\n";
    else
        balance += amt;
}

// formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

format setFormat()//设置原格式函数
{
    // set up ###.## format
    return cout.setf(std::ios_base::fixed,
        std::ios_base::floatfield);
}

void restore(format f, precis p)//重置格式和精度函数
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}

void Brass::Withdraw(double amt)
{
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
        << "withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt
        << " exceeds your balance.\n"
        << "Withdrawal canceled.\n";

    restore(initialState, prec);
}
double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;

    restore(initialState, prec); // Restore original format
}

/******************************************************************************************************************************************/

// BrassPlus Methods

BrassPlus::BrassPlus(const string& s, long an, double bal,
    double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass& ba, double ml, double r)
    : Brass(ba)   // uses implicit copy constructor
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();   //***注***明确指定使用基类的方法，若没有写明是Brass::则会调用派生类中的同名的方法(相当于递归调用)
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);  // ###.### format
    cout << "Loan Rate: " << 100 * rate << "%\n";

    restore(initialState, prec);
}

// redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
    // set up ###.## format
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Brass::Balance();//由于BrassPlus是Brass的派生类，所以派生类的方法可以访问基类的方法(两个类的方法彼此都可见)(P283)
    //或写成double bal=Balance();***注***可以不写Brass::，因为派生类中未定义Balance()，只有基类中有，默认会调用基类中的

    if (amt <= bal)
        Brass::Withdraw(amt);//***注***明确指定使用基类的方法，若没有写明是Brass::则会调用派生类中的同名的方法(相当于递归调用)
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;//advance银行贷款
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";

    restore(initialState, prec);
}

#endif