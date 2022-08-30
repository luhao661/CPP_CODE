#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单9.1 使用头文件
#if 0
#include "CXQD9.1.h" // structure templates, function prototypes
using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)  // slick use of cin
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Bye!\n";
    // keep window open in MSVC++
    /*
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//程序清单9.4 自动变量只在包含它们的函数或代码块中可见
#if 0
void oil(int x);

int main()
{
    using namespace std;

    int texas = 31;
    int year = 2011;
    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;
    oil(texas);
    cout << "In main(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In main(), year = " << year << ", &year = ";
    cout << &year << endl;
    // cin.get();
    return 0;
}

void oil(int x)
{
    using namespace std;
    int texas = 5;

    cout << "In oil(), texas = " << texas << ", &texas = ";
    cout << &texas << endl;
    cout << "In oil(), x = " << x << ", &x = ";
    cout << &x << endl;

    {                               // start a block
        int texas = 113;
        cout << "In block, texas = " << texas;
        cout << ", &texas = " << &texas << endl;
        cout << "In block, x = " << x << ", &x = ";
        cout << &x << endl;
    }                               // end a block

    cout << "Post-block texas = " << texas;
    cout << ", &texas = " << &texas << endl;
}
#endif


//程序清单9.5 外部链接的静态变量
#if 0
// external variable
double warming = 0.3;       // warming defined

// function prototypes
void update(double dt);
void local();

int main()                  // uses global variable
{
    using namespace std;

    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);            // call function to change warming
    cout << "Global warming is " << warming << " degrees.\n";
    local();                // call function with local warming
    cout << "Global warming is " << warming << " degrees.\n";
    // cin.get();
    return 0;
}
#endif


//程序清单9.6 内部链接的静态变量可以隐藏(覆盖)外部链接的静态变量
#if 0
int tom = 3;            // external variable definition
int dick = 30;          // external variable definition
static int harry = 300; // static, internal linkage

// function prototype
void remote_access();

int main()
{
    using namespace std;

    cout << "main() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
    remote_access();

    // cin.get();
    return 0;
}
#endif


//程序清单9.9 使用无链接的静态变量
#if 0
// constants
const int ArSize = 10;

// function prototype
void strcount(const char* str);

int main()
{
    using namespace std;

    char input[ArSize];
    char next;

    cout << "Enter a line:\n";
    cin.get(input, ArSize);
    while (cin)
    {
        cin.get(next);          //读取换行符，或数据长度过长时读取余下的第一个字符
        while (next != '\n')    //丢弃余下字符
            cin.get(next);      

        strcount(input);

        cout << "Enter next line (empty line to quit):\n";//***注***当get()读取空行后将设置失效位
        cin.get(input, ArSize);
    }
    cout << "Bye\n";
    // code to keep window open for MSVC++
    /*
    cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}

void strcount(const char* str)
{
    using namespace std;

    static int total = 0;        // static local variable 只会在第一次调用函数时进行初始化

    cout << "\"" << str << "\" contains ";

    int count = 0;               // automatic local variable
    while (*str++)               // go to end of string
        count++;

    total += count;

    cout << count << " characters\n";
    cout << total << " characters total\n";
}
#endif


//程序清单9.10 new运算符的变体——定位new运算符
#if 1
#include <new> // for placement new 定位new运算符的原型

const int LSIZE = 512;
char buffer[LSIZE];      // chunk of memory 存储在一块用于存储静态变量的内存中

const int SIZE = 5;

int main()
{
    using namespace std;

    double* pd1, * pd2;
    int i;

    cout << "Calling new and placement new:\n";
    pd1 = new double[SIZE];                // use heap 
                                                              //从堆中分配到满足要求的内存块
    pd2 = new (buffer) double[SIZE];  // use buffer array 
                                                              //从buffer数组中分配空间给
                                                              //一个包含SIZE个元素的double数组
    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;

    cout << "Memory addresses:\n"
        << "(pd1)heap: " << pd1 << endl
        << "   buffer: " << (void*)buffer <<endl//强制类型转换，使cout显示地址而不是字符串
        <<"      pd2: "<<pd2
        << endl;

    cout << "Memory contents:\n";
    cout << "pd1指向的数组               pd2指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    cout << "\nCalling new and placement new a second time:\n";
    double* pd3, * pd4;
    pd3 = new double[SIZE];                // find new address
                                                              //从堆中分配到满足要求的新的内存块
    pd4 = new (buffer) double[SIZE];  // overwrite old data
                                                              //再次从buffer数组中分配空间给
                                                              //一个包含SIZE个元素的double数组
    for (i = 0; i < SIZE; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;

    cout << "Memory contents:\n";
    cout << "pd3指向的数组             pd4指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }

    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;                                    //释放pd1指向的内存块，但不会删除pd1指针本身
    pd1 = new double[SIZE];                //从堆中分配到满足要求的新的内存块
    pd2 = new (buffer + SIZE * sizeof(double)) double[SIZE];
                                                             //再次从buffer数组中分配空间给
                                                             //一个包含SIZE个元素的double数组
                                                             //***注***
                                                             //定位到从buffer开头位置算起，偏移量为SIZE * sizeof(double)的位置
                                                             //SIZE * sizeof(double)等于40字节，用十六进制表示是0x28
    
    for (i = 0; i < SIZE; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;

    cout << "Memory contents:\n";
    cout << "pd1指向的数组             pd2指向的数组：\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete[] pd1;
    delete[] pd3;

    //***注***
    //不能加上delete[] pd2; 或  delete[] pd4;
   //程序会崩溃

    return 0;
}
#endif