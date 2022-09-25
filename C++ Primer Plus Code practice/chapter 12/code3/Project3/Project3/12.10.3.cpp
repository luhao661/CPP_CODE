#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
#include "12.10.3.h"
using namespace std;
// constructors
Stock::Stock()        // default constructor
{
    str = new char[1];
    *str = '\0';
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *p, long n, double pr)
{
    str = new char[strlen(p)+1];
    strcpy(str,p);
        
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
            << str << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
    delete[]str;
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
        shares += num;
        share_val = price;
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
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
/*
void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << str
        << "  Shares: " << shares << '\n';
    cout << "  Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}*/

//第二个const：表明函数不会修改被显式地访问的对象
//第三个const：表明函数不会修改被隐式地访问的对象
//第一个const：返回两个const对象的其中之一，因此返回的对象也应声明为const
const Stock& Stock::topval(const Stock& s) const
{
    if (s.total_val > this->total_val)//相当于if(s.total_val>this->total_val)
        return s;
    else
        return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock &s)
{
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    os << "Company: " << s.str
        << "  Shares: " << s.shares << '\n';
    os << "  Share Price: $" << s.share_val;
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << s.total_val << '\n';

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);

    return os;
}

#endif