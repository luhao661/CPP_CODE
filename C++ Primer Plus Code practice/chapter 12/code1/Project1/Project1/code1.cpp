#define _CRT_SECURE_NO_WARNINGS 1

//程序清单12.3 研究一个不完善的类
//链接12.2.cpp
#if 0
#include "cxqd12.1.h"
#include <iostream>
using std::cout;
using std::endl;

void callme1(StringBad&);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{
    {
        cout << "Starting an inner block.\n";
        StringBad s1("Celery Stalks at Midnight");
        StringBad s2("Lettuce Prey");
        StringBad s3("Spinach Leaves Bowl for Dollars");
        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        cout << "s3: " << s3 << endl;

        //错误：只调用了默认的复制构造函数，进行了浅复制
        //导致静态成员不变
        callme1(s1);
        cout << "s1: " << s1 << endl;
        callme2(s2);
        cout << "s2: " << s2 << endl;

        cout << "Initialize one object to another:\n";
        //错误：只调用了默认的复制构造函数，进行了浅复制
        //导致静态成员不变，只是赋值了指针的值(这直接导致后面调用析构函数时会出现释放两次内存，其结果是不确定的)
        StringBad s4 = s1;
        cout << "s4: " << s4 << endl;

        cout << "Assign one object to another:\n";
        //错误：只调用了默认的赋值运算符重载函数，进行了浅复制
        //导致的后果与上述的一致
        StringBad s5;
        s5 = s1;
        cout << "s5: " << s5 << endl;

        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";
    // std::cin.get();
    return 0;
}

void callme1(StringBad& r_s)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << r_s << "\"\n";
}

void callme2(StringBad s)
{
    cout << "String passed by value:\n";
    cout << "    \"" << s << "\"\n";
}
#endif


//程序清单12.6 使用一个比较完善的String类，实现字符串的存储和比较
//链接cxqd12.5.cpp
#if 1
#include "cxqd12.4.h" 
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];     // array of objects
    char temp[MaxLen];          // temporary string storage

    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);

        while (cin && cin.get() != '\n')//输入不为空行且没读取到换行符
            continue;

        if (!cin || temp[0] == '\0')    // empty line? ***注***temp[0]=='\0'，用于旧版实现，此处可不写
            break;              // i not incremented
        else
            sayings[i] = temp;  //使用赋值运算符重载函数的重载，进行字符串到对象的赋值
    }
    int total = i;              // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i][0] << ": " << sayings[i] << endl;

        int shortest = 0;//创建索引
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if (sayings[shortest].length()>sayings[i].length())//比较字符串长度
                shortest = i;
            if (sayings[first]> sayings[i] )//比较字符串首字母的顺序
                first = i;
        }
        cout << "Shortest saying:\n" << sayings[shortest] << endl;;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany()
            << " String objects. Bye.\n";
    }
    else
        cout << "No input! Bye.\n";
    // keep window open 
    /*    if (!cin)
            cin.clear();
        while (cin.get() != '\n')
            continue; */
    return 0;
}
#endif