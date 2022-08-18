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


//程序清单7.7 填充数组、保护和显示数组、修改数组
#if 1
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