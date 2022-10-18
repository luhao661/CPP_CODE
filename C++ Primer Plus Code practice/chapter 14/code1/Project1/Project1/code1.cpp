#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//程序清单14.3 has-a关系，使用包含技术(即创建一个包含其他类对象的类)
//使用复合类
//链接cxqd14.2.cpp
#if 0
#include "cxqd14.1.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };
    //使用了构造函数的类型转换特性(显式类型转换)

    int i;
    for (i = 0; i < pupils; ++i)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; ++i)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//程序清单14.6 has-a关系，使用私有继承技术
//链接cxqd14.5.cpp
#if 0
#include "cxqd14.4.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student& sa, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
    Student ada[pupils] =
    { Student(quizzes), Student(quizzes), Student(quizzes) };

    int i;
    for (i = 0; i < pupils; i++)
        set(ada[i], quizzes);

    cout << "\nStudent List:\n";
    for (i = 0; i < pupils; ++i)
        cout << ada[i].Name() << endl;

    cout << "\nResults:";
    for (i = 0; i < pupils; i++)
    {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done.\n";
    // cin.get();

    return 0;
}

void set(Student& sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);

    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];

    while (cin.get() != '\n')
        continue;
}
#endif


//程序清单14.9 使用公有单重继承
//链接cxqd14.8.cpp
#if 0
#include "cxqd14.7.h"
const int LIM = 4;

int main()
{
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;

    Worker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

    int i;
    for (i = 2; i < LIM; i++)
        pw[i]->Set();

    for (i = 0; i < LIM; i++)
    {
        pw[i]->Show();
        std::cout << std::endl;
    }
    // std::cin.get();
    return 0;
}
#endif


//程序清单14.12 使用公有多重继承(公有MI)
//链接cxqd14.11.cpp
#if 0
#include <cstring>
#include "cxqd14.10.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker* lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";

        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':   lolas[ct] = new Waiter;
            break;
        case 's':   lolas[ct] = new Singer;
            break;
        case 't':   lolas[ct] = new SingingWaiter;
            break;
        }

        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
        delete lolas[i];

    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单14.15 使用类模板，使用模板生成string栈
//链接cxqd14.14.cpp
#if 0
#include "cxqd14.13.h"
#include <string>
#include <cctype>

using std::cin;
using std::cout;

int main()
{                                          //模板的显式实例化
    Stack<std::string> st;   // create an empty stack 创建并用默认构造函数初始化一个空栈
                                           //***注***必须显式地提供所需的类型
    std::string po;

    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    char ch;
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;

        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }

        switch (ch)
        {
        case 'A':
        case 'a': 
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
                cout << "stack already full\n";
            else
                st.push(po);
            break;
        case 'P':
        case 'p':
            if (st.isempty())
            cout << "stack already empty\n";
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
             }
        }

        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单14.17 使用类模板，使用模板生成指针栈
//链接无
#if 1
#include <cstdlib>     // for rand(), srand()
#include <ctime>       // for time()
#include "cxqd14.16.h"

const int Num = 10;

int main()
{
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;
    // create an empty stack with stacksize slots
    Stack<const char*> st(stacksize);//创建一个动态内存分配的指针栈

    // in basket                                                   //生成指针数组
    const char* in[Num] = {
            " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
            " 3: Betty Rocker", " 4: Ian Flagranti",
            " 5: Wolfgang Kibble", " 6: Portia Koop",
            " 7: Joy Almondo", " 8: Xaverie Paprika",
            " 9: Juan Moore", "10: Misha Mache"
    };
    // out basket
    const char* out[Num];

    std::srand(std::time(0)); // randomize rand()
    int processed = 0;
    int nextin = 0;
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (std::rand() % 2 && nextin < Num)   // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }

    for (int i = 0; i < Num; i++)
        std::cout << out[i] << std::endl;

    std::cout << "Bye\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}

#endif
