#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//程序清单13.3 使用一个简单的基类
//链接cxqd13.2.cpp
#if 0
#include "cxqd13.1.h"

int main(void)
{
    using std::cout;

    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";

    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单13.6 使用派生类，演示派生类和基类的关系
//链接cxqd13.5.cpp 
#if 0
#include "cxqd13.4.h"

int main(void)
{
    using std::cout;
    using std::endl;

    TableTennisPlayer player1("Tara", "Boomdea", false);
    player1.Name();           // 基类对象使用基类的方法
    if (player1.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";

    //声明并初始化派生类对象
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name();          // 派生类对象使用基类的方法
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    //使用基类对象初始化派生类对象
    // initialize RatedPlayer using TableTennisPlayer object
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    RatedPlayer rplayer3(333, "Aaa", "Bbb", true);
    TableTennisPlayer player3 (rplayer3);//使用派生类对象初始化基类对象
    player3.Name();
    cout.put('\n');

    RatedPlayer rplayer4(444, "Ccc", "Ddd", true);
    TableTennisPlayer player4;//使用派生类对象赋值给基类对象
    player4 = rplayer4;
    player4.Name();
    cout.put('\n');

    // std::cin.get();
    return 0;
}
#endif


//程序清单13.9 测试含虚函数的基类和派生类
//链接cxqd13.8.cpp
#if 1
#include "cxqd13.7.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;

    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl<<endl;

    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg account balance: $" << Piggy.Balance() << endl<<endl;

    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
    // std::cin.get();
    return 0;
}
#endif


//程序清单13.10 类的多态(同一个方法在派生类和基类中的行为不同)——虚函数
//链接
#if 1
#endif