#define _CRT_SECURE_NO_WARNINGS 1

//程序清单12.3 研究一个不完善的类
//链接12.1.cpp
#if 1
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
        //错误：只调用了默认的重载赋值运算符函数，进行了浅复制
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