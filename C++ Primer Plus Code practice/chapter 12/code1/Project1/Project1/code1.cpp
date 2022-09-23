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
#if 0
#include "cxqd12.4.h" 
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    {
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
                if (sayings[shortest].length() > sayings[i].length())//比较字符串长度
                    shortest = i;
                if (sayings[first] > sayings[i])//比较字符串首字母的顺序
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
    }
    cin.clear();
    cin.get();

    return 0;
}
#endif


//程序清单12.7 使用指向对象的指针
//链接cxqd12.5.cpp
#if 0
#include "cxqd12.4.h"
#include <cstdlib>      // (or stdlib.h) for rand(), srand()
#include <ctime>        // (or time.h) for time()

const int ArSize = 10;
const int MaxLen = 81;

int main()
{
    using namespace std;
    String name;
    cout << "Hi, what's your name?\n>> ";
    cin >> name;

    cout << name << ", please enter up to " << ArSize
        << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];               // temporary string storage

    int i;
    for (i = 0; i < ArSize; i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') // empty line?
            break;                   // i not incremented
        else
            sayings[i] = temp;       // overloaded assignment
    }
    int total = i;                   // total # of lines read

    if (total > 0)
    {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << "\n";

        //声明并初始化指向对象的指针
        // use pointers to keep track of shortest, first strings
        String* shortest = &sayings[0]; // initialize to first object
        String* first = &sayings[0];
        for (i = 1; i < total; i++)
        {
            if (shortest->length()>sayings[i].length())
                shortest = &sayings[i];
            if (*first>sayings[i])        // compare values
                first = &sayings[i];     // assign address
        }
        cout << "Shortest saying:\n" << *shortest << endl;
        cout << "First alphabetically:\n" << *first << endl;

        srand(time(0));
        int choice = rand() % total; // pick index at random
        //使用对象来初始化新的String对象
        // use new to create, initialize new String object
        String* favorite = new String(sayings[choice]);
        cout << "My favorite saying:\n" << *favorite << endl;
        delete favorite;//***注***此处仅delete对象，
                                 //因此第一步仅释放str指针和len成员的空间，
                                 //并不释放str指向的内存，
                                 //第二步才调用析构函数，释放str指向的内存
    }
    else
        cout << "Not much to say, eh?\n";
    cout << "Bye.\n";
    // keep window open
    /*    if (!cin)
            cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单12.8 使用定位new运算符，用于对象(有瑕疵)
//无链接的文件
#if 0
#include "cxqd12.8.h"
#include <new> //定位new的特性
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //使用默认构造函数创建匿名对象 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//使用构造函数初始化新创建的匿名对象
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" << 
        "pc1: "<<pc1<<endl<<
        "buffer: "<<(void *)buffer <<endl<<//***注***若不写(void *)，则打印buffer上存的数据，由于buffer上存的是对象，无法直接打印出对象私有成员的内容，故打印的是乱码
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 6);//pc3指向的对象把pc1指向的对象覆盖了
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 调用析构函数        
    delete pc4;                          // free Heap2 调用析构函数
    delete[] buffer;                    // free buffer
    cout << "Done\n";             //***注***
    // std::cin.get();                   //执行delete[] buffer;后不会为定位new创建的对象调用析构函数
    return 0;                              //因为new/delete系统只知道已分配的512字节块buffer，而不知道定位new对这块内存作了何处理
}
#endif


//程序清单12.9 使用定位new运算符，用于对象(已修复问题)
//链接无
#if 0
#include "cxqd12.8.h"
#include <new> //定位new的特性
const int BUF = 512;

int main()
{
    char* buffer = new char[BUF];       // get a block of memory

    JustTesting* pc1, * pc2;

    pc1 = new (buffer) JustTesting;        //使用默认构造函数创建匿名对象 
                                                                //place object in buffer

    pc2 = new JustTesting("Heap1", 20);//使用构造函数初始化新创建的匿名对象
                                                                 // place object on heap

    cout << "\nMemory block addresses:\n" <<
        "pc1: " << pc1 << endl <<
        "buffer: " << (void*)buffer << endl <<//***注***若不写(void *)，则打印buffer上存的数据，由于buffer上存的是对象，无法直接打印出对象私有成员的内容，故打印的是乱码
        "pc2: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    cout.put('\n');
    JustTesting* pc3, * pc4;
    pc3 = new (buffer + sizeof(JustTesting))
        JustTesting("Better Idea", 6);//pc3指向的对象和pc1指向的对象，两个内存区域不重叠
    pc4 = new JustTesting("Heap2", 10);
    cout << "\nMemory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2;                          // free Heap1 调用析构函数        
    delete pc4;                          // free Heap2 调用析构函数

    //显式调用析构函数，与创建时相反的顺序删除对象
    // explicitly destroy placement new objects
    pc3->~JustTesting();  // destroy object pointed to by pc3
    pc1->~JustTesting();  // destroy object pointed to by pc1

    //所有对象都被销毁后，才能释放用于存储这些对象的存储区
    delete[] buffer;                    // free buffer

    return 0;                           
}
#endif


//
//链接
#if 1

#endif