#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//程序清单11.3 不使用运算符重载，实现计算时间的程序
//链接cxqd11.2.cpp
#if 0
#include "cxqd11.1.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();

    cout << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单11.6 使用运算符重载，实现计算时间的程序
//链接cxqd11.5.cpp
#if 0
#include "cxqd11.4.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time morefixing(3, 28);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    // operator notation 法一：使用运算符表示法
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    // function notation 法二：使用operator+()方法
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    // std::cin.get();
    return 0;
}
#endif


//程序清单11.9 使用其他重载运算符(+-*)，实现计算时间的程序
//链接cxqd11.8.cpp
#if 1
#include "cxqd11.7.h"

int main()
{
    using std::cout;
    using std::endl;

    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.Show();
    cout << endl;

    cout << "waxing time = ";
    waxing.Show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;   // use operator+()
    total.Show();
    cout << endl;

    diff = weeding - waxing;    // use operator-()
    cout << "weeding time - waxing time = ";
    diff.Show();
    cout << endl;

    adjusted = total * 1.5;      // use operator*()
    cout << "adjusted work time = ";
    adjusted.Show();
    cout << endl;
    // std::cin.get();    
    return 0;
}
#endif