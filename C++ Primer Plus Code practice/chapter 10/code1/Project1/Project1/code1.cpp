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
#if 0
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


//程序清单10.9 对象数组，this指针
//链接cxqd10.8
#if 0
#include "cxqd10.7.h"

const int STKS = 4;
int main()
{
    {
        // create an array of initialized objects
        Stock stocks[STKS] = 
        {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
        };

        std::cout << "Stock holdings:\n";
        int i;
        for (i = 0; i < STKS; i++)
            stocks[i].show();

        // set pointer to first element 声明并初始化一个指向Stock类对象的指针top
        const Stock* top = &stocks[0];
        for (i = 1; i < STKS; i++)
            top = &(top->topval(stocks[i]));//指针也可以用->来访问对象的方法成员

        // now top points to the most valuable holding
        std::cout << "\nMost valuable holding:\n";
        top->show();    
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单10.12 使用ADT——栈
//链接cxqd10.11.cpp
#if 0
#include <cctype>  // or ctype.h
#include "cxqd10.10.h"

int main()
{
    using namespace std;

    Stack st; // create an empty stack (隐式调用默认构造函数进行隐式初始化)

    unsigned long data;
    cout << "Please enter A to add a purchase order,"
        << "P to delete, or Q to quit.\n";
    char ch;
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
            case 'A':
            case 'a': 
                cout << "Enter a number to add: ";
                while(!(cin >> data))
                {
                    cin.clear();
                    while (cin.get() != '\n')
                        continue;
                    cout << "请输入数字：";
                }
                if (st.isfull())
                    cout << "stack already full\n";
                else
                    st.push(data);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
                cout << "stack already empty\n";
                else 
                {
                st.pop(data);//弹出栈的值会赋给data
                cout << "栈顶成员 ：" << data << " popped\n";
                }
                break;
        }
        cout << "Please enter A to add a purchase order,"
            << "P to delete, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}
#endif