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
#if 0
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


//程序清单11.12 使用友元函数(用于处理第一个操作数不是类对象的情况)
//链接cxqd11.11.cpp
#if 0
#include "cxqd11.10.h"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;

    //使用重载运算符函数operator+()
    temp = aida + tosca;     
    cout << "Aida + Tosca: " << temp << endl;
    //使用重载运算符函数operator*()
    temp = aida * 1.17;  
    cout << "Aida * 1.17: " << temp << endl;

    //使用ostream类的operator<<()重载运算符函数
    cout << "10.0 * Tosca: " 
    //使用Time类的operator*()友元函数，
    //然后使用Time类的operator<<()友元函数
        << 10.0 * tosca 
    //使用ostream类的operator<<()重载运算符函数
        << endl;

    return 0;
}
#endif


//程序清单11.15 使用Vector类模拟随机漫步问题
//链接cxqd11.14.cpp
#if 1
#include "cxqd11.13.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0,Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        while (result.magval() < target_distance)
        {
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
            steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif