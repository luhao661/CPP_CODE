#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//15.8 编程练习
//1.
//链接15.8.1.cpp
#if 0
#include "15.8.1.h"

int main()
{
    using std::cout;

    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    cout << "\nAdjusted settings for 42\" TV:\n";
    s42.onoff();
    s42.chanup();
    s42.settings();

    Remote grey;

    cout << "\n42\" settings after using remote:\n";
    grey.set_chan(s42, 10);
    grey.volup(s42);
    grey.volup(s42);
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout << "\n58\" settings:\n";
    s58.settings();
    
    cout << "\n遥控器当前的模式：\n";
    grey.show_moshi();
    Tv v1(Tv::On);
    cout << "\n电视v1\" settings:\n";
    v1.settings();
    cout << "切换遥控器的交互模式：\n";

    if (v1.switch_moshi(grey))
    {
        cout << "遥控器当前的模式：\n";
        grey.show_moshi();
    }
    else
        cout << "电视机未打开！\n";

    return 0;
}
#endif


//2.
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.2.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout<<bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
#endif


//3.
//链接无
#if 0
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.3.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout << bg.what();
            bg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            hg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return std::sqrt(a * b);
}
#endif
//3.改正
//链接无
#if 1
#include <cmath> // or math.h, unix users may need -lm flag

#include "15.8.3.1.h"
// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {                  // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (bad_hmean& bg)    // start of catch block
        {
            cout << bg.what();
            bg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        catch (bad_gmean& hg)
        {
            cout << hg.what();
            hg.report();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
#endif

//4.
//链接无
#if 0
#include "15.8.4.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "First try block:\n";

    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {

            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {

            cout << sales2[i] << ' ';//当i为12时，索引值超界，引发异常
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    /*catch (LabeledSales::nbad_index& bad)//***注***两个catch块的顺序不能颠倒，P511
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }*/
    catch (Sales::bad_index& bad)
    {
        //想法一：是否可以用类名+作用域解析运算符来控制what()打印的内容？
        //即对于不同的类中的异常，用类名+作用域解析运算符来打印不同的字符串内容
        //cout << bad.bad_index::what();//***注***指定使用bad_index类公有继承的logic_error类的what()方法
        //以上方法不可用，因为nbad_index继承了bad_index类，而
        //而LabeledSales类对象出现异常后，初始化了nbad_index对象，
        //同时也初始化了bad_index类对象，而bad_index继承的logic_error类的what()方法的字符串内容为Index error in LabeledSales object
        //即LabeledSales类对象出现异常后，上面的方法打印不了Index error in Sales object
        //想法一失败

        //想法二：
        //使用RTTI来判断索引值错误是在Sales类中还是LabeledSales类中
        //由于只要求在合适时调用label_val()
        //相当于要根据不同的异常，调用label_val()和bi_val() 或只调用bi_val()
        if(typeid(bad)==typeid(LabeledSales::nbad_index))
        {
            LabeledSales::nbad_index bad1("chushihua",1);
            bad1 = dynamic_cast<LabeledSales::nbad_index &>(bad);//只允许隐式向上强制转换，相当于只允许nbad_index到nbad_index

            cout << bad1.what();
            cout << "Company: " << bad1.label_val() << endl;
            cout << "bad index: " << bad1.bi_val() << endl;
        }
        else
        {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }

    cout << "\nNext try block:\n";

    try
    {
        sales1[20] = 23345;//***注***此处索引值超界，operator[]()引发异常
        sales2[2] = 37.5;
        cout << "End of try block 2.\n";
    }
    /*catch (LabeledSales::nbad_index& bad)
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }*/
    catch (Sales::bad_index& bad)
    {
        if (typeid(bad) == typeid(LabeledSales::nbad_index))
        {
            LabeledSales::nbad_index bad1("chushihua", 1);
            bad1 = dynamic_cast<LabeledSales::nbad_index&>(bad);//只允许隐式向上强制转换，相当于只允许nbad_index到nbad_index

            cout << bad1.what();
            cout << "Company: " << bad1.label_val() << endl;
            cout << "bad index: " << bad1.bi_val() << endl;
        }
        else
        {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }
    cout << "done\n";
    // std::cin.get();
    return 0;
}
#endif