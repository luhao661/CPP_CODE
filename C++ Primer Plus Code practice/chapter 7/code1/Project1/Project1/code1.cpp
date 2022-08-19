#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单7.2 函数原型，函数调用，函数定义
#if 0
void cheers(int);       // prototype: no return value
double cube(double x);  // prototype: returns a double

int main()
{
    using namespace std;

    cheers(5);          // function call

    cout << "Give me a number: ";
    double side;
    cin >> side;

    double volume = cube(side);    // function call

    cout << "A " << side << "-foot cube has a volume of ";
    cout << volume << " cubic feet.\n";

    cheers(cube(2));    // prototype protection at work
    //C++能自动将传递的值转化为原型中指定的类型
    //2转化为2.0，cube函数返回8.0，8.0转化为8，进入cheers函数
    
    // cin.get();
    // cin.get();
    return 0;
}

void cheers(int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << "Cheers! ";
    cout << endl;
}
double cube(double x)
{
    return x * x * x;
}
#endif


//程序清单7.3 一般而言，被调函数中对数据的操作不会影响主调函数中的数据的值
//因为被调函数将创建一个新的变量(形参)并对其初始化为实参的值，相当于是实参的值的副本
#if 0
using namespace std;

void n_chars(char, int);

int main()
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    while (ch != 'q')        // q to quit
    {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times); // function with two arguments
        cout << "\nEnter another character or press the"
            " q-key to quit: ";
        cin >> ch;
    }
    cout << "The value of times is " << times << ".\n";
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}

void n_chars(char c, int n) // displays c n times
{
    while (n-- > 0)         // continue until n reaches 0
        cout << c;
}
#endif


//程序清单7.4 接受两个参数的函数的应用
#if 0
long double probability(unsigned numbers, unsigned picks);

int main()
{
    using namespace std;
    double total, choices;
    cout << "Enter the total number of choices on the game card and\n"
        "the number of picks allowed:\n";

    while ((cin >> total >> choices) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices);      // compute the odds
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks;            p > 0;         n--, p--)
        result = result * n / p;

    return result;
}
#endif


//程序清单7.5 使用指向数组的指针作为函数的形参
#if 0
const int ArSize = 8;

int sum_arr(int arr[], int n);        // prototype

int main()
{
    using namespace std;
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
    // some systems require preceding int with static to
    // enable array initialization

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}
#endif


//程序清单7.6 数组名代表数组的第一个元素的地址
//***注***
//&数组名得整个数组的地址，而不是单个元素的地址，见书P176
#if 0
const int ArSize = 8;

int sum_arr(int arr[], int n);

// use std:: instead of using directive
int main()
{
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

    std::cout<< "array address = " << cookies;
    //  some systems require a type cast: unsigned (cookies)

    std::cout << ", sizeof cookies = " << sizeof cookies<<std::endl;
                                              //sizeof cookies：指整个数组的长度(以字节为单位)
    int sum = sum_arr(cookies, ArSize);

    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(cookies, 3);        // a lie
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, 4);    // another lie
    //或写为
    //sum = sum_arr(&cookies[4], 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";
    // std::cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(int arr[], int n)
{
    int total = 0;
    std::cout << "arr = " << arr;
    // some systems require a type cast: unsigned (arr)

    std::cout << ", sizeof arr = " << sizeof arr<<std::endl;
                                    //***注***sizeof arr是指针变量的长度，而不是数组中的元素的长度
 
    for (int i = 0; i < n; i++)
        total = total + arr[i];

    return total;
}
#endif


//程序清单7.7 填充数组、保护和显示数组、修改数组的函数
//将数组起始处的指针作为一个参数，将数组长度作为第二个参数
#if 0
const int Max = 5;

// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[Max];

    int size = fill_array(properties, Max);

    show_array(properties, size);

    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number: ";
        }

        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;

        ar[i] = temp;
    }
    return i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}
#endif


//程序清单7.8 另一种给函数提供所需信息的方法
//一个指针标识数组的开头，一个指针标识数组结尾后面的一个位置
#if 0
const int ArSize = 8;

int sum_arr(const int* begin, const int* end);

int main()
{
    using namespace std;
    int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;

    sum = sum_arr(cookies, cookies + 3);        // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(cookies + 4, cookies + 8);    // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(const int* begin, const int* end)
{
    const int* pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}
#endif


//程序清单7.9 用函数处理字符串
#if 0
unsigned int c_in_str(const char* str, char ch);

int main()
{
    using namespace std;
    char mmm[15] = "minimum";    // string in an array
// some systems require preceding char with static to
// enable array initialization

    const char* wail = "ululate";    // wail points to string

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;
    // cin.get();
    return 0;
}

//不必将字符串长度作为参数传递给函数
unsigned int c_in_str(const char* str, char ch)
{
    unsigned int count = 0;

    while (*str)        // quit when *str is '\0'
    {
        if (*str == ch)
            count++;
        str++;        // move pointer to next char
    }
    return count;
}
#endif


//程序清单7.10 返回C风格字符串的函数
#if 0
char* buildstr(char c, int n);     // prototype

int main()
{
    using namespace std;
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char* ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;                   // free memory

    ps = buildstr('+', 20);         // reuse pointer
    cout << ps << "-DONE-" << ps << endl;
    delete[] ps;                   // free memory
    // cin.get();
    // cin.get();
    return 0;
}

// builds string made of n c characters
char* buildstr(char c, int n)
{
    char* pstr = new char[n + 1];

    while (n-- > 0)
        pstr[n] = c;        // fill rest of string

    pstr[n] = '\0';         // terminate string

    return pstr;//***注***此函数结束时，指针pstr所占的内存将被释放，
}                      //而new申请的动态分配的内存空间不会被释放,
                       //由于函数返回了指针pstr上存的地址，因此main()仍可以用ps来访问创建的字符串
#endif  


//程序清单7.11 传递并返回结构
#if 0
struct travel_time
{
    int hours;
    int mins;
};

const int Mins_per_hr = 60;

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main()
{
    using namespace std;
    travel_time day1 = { 5, 45 };    // 5 hrs, 45 min
    travel_time day2 = { 4, 55 };    // 4 hrs, 55 min

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3 = { 4, 32 };
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    // cin.get();

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = t1.hours + t2.hours +
        (t1.mins + t2.mins) / Mins_per_hr;
    return total;
}

void show_time(travel_time t)
{
    using namespace std;
    cout << t.hours << " hours, "
        << t.mins << " minutes\n";
}
#endif


//程序清单7.12 传递并返回结构  实际应用
#if 1
#include <cmath>//sqrt()、atan2()

// structure declarations
struct polar
{
    double distance;      // distance from origin
    double angle;         // direction from origin
};
struct rect
{
    double x;             // horizontal distance from origin
    double y;             // vertical distance from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)  // slick use of cin
    {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

// convert rectangular to polar coordinates
polar rect_to_polar(rect xypos)
{
    using namespace std;
    polar answer;

    answer.distance =
        sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle = atan2(xypos.y, xypos.x);
    return answer;      // returns a polar structure
}

// show polar coordinates, converting angle to degrees
void show_polar(polar dapos)
{
    using namespace std;
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degrees\n";
}
#endif
