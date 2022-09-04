#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include <iostream>
#include "cxqd10.4.h"

//定义默认构造函数
// constructors (verbose versions)
Stock::Stock()        // default constructor
{
    std::cout << "Default constructor called\n";
    m_company = "no name";
    m_shares = 0;
    m_share_val = 0.0;
    m_total_val = 0.0;
}

//定义构造函数
Stock::Stock(const std::string& co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    m_company = co;

    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
            << m_company << " shares set to 0.\n";
        m_shares = 0;
    }
    else
        m_shares = n;
    m_share_val = pr;
    set_tot();
}

//定义析构函数
// class destructor
Stock::~Stock()        // verbose class destructor
{
    std::cout << "Bye, " << m_company << "!\n";
}

// other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
            << "Transaction is aborted.\n";
    }
    else
    {
        m_shares += num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted.\n";
    }
    else if (num > m_shares)
    {
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    }
    else
    {
        m_shares -= num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    m_share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << m_company
        << "  Shares: " << m_shares << '\n';
    cout << "  Share Price: $" << m_share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << m_total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
#endif