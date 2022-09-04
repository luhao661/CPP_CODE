#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单10.3 声明一个类对象，使用类方法
//链接cxqd10.2.cpp
#if 0
#include "cxqd10.1.h"

int main()
{
    Stock   fluffy_the_cat;

    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();
    // std::cin.get();
    return 0;
}
#endif


//程序清单10.6 构造函数和析构函数以及C++11的列表初始化用于类
//链接cxqd10.5.cpp
#if 1
#include "cxqd10.4.h"

int main()
{
    {//此对大括号提供了一个代码块，使得stock1,stock2,stock3等这些自动变量
     //将在程序运行至代码块外时消失，执行析构函数可以被观察到
     //否则将在main()块结束时(程序结束时)调用析构函数，但在窗口环境下无法直观观察到
        using std::cout;
        cout << "Using constructors to create new objects\n";
        //隐式调用构造函数
        Stock stock1("NanoSmart", 12, 20.0);         
        stock1.show();

        //显式调用构造函数
        Stock stock2 = Stock("Boffo Objects", 2, 2.0); 
        stock2.show();

        //可以将一个对象的内容赋给另一个
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();

        //使用构造函数重置对象的内容(显式调用构造函数)
        //构造函数除了用来初始化对象，也可以用来给对象赋值
        cout << "Using a constructor to reset an object\n";
        //***注***
        //构造函数创建一个临时对象，将其赋值给stock1后调用析构函数删除临时对象
        stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
        cout << "Revised stock1:\n";
        stock1.show();

        //隐式调用默认构造函数
        Stock stock3;
        stock3.show();

        //C++11的列表初始化用于类
        Stock stock4 = {"abc def",20,20.0};//显式调用构造函数
        stock4.show();
        Stock stock5 = {};//隐式调用构造函数
        stock5.show();

        cout << "Done\n";
    }

    return 0;
}
#endif