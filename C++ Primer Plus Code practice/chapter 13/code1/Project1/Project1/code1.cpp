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


//程序清单13.6 使用派生类
//链接cxqd13.5.cpp 
#if 1
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
    // std::cin.get();
    return 0;
}
#endif