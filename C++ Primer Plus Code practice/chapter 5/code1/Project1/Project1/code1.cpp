#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>//string 类
#include <cstring>// prototype for strcmp()
//
#if 1
#endif


//程序清单5.3 注意运算符优先级
#if 0
int main()
{
    using namespace std;
    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout.setf(ios_base::boolalpha);   //a newer C++ feature

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    /// cin.get();
    return 0;
}                                                           //口诀：算数移位关系，按位逻辑赋值
#endif


//程序清单5.4 用for循环实现阶乘(for循环与数组协同工作)
#if 0
const int ArSize = 16;      // example of external declaration
int main()
{
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;//0!=1，1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单5.5 修改步长
#if 0
int main()
{
    using std::cout;    // a using declaration
    using std::cin;
    using std::endl;

    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.6 用for循环访问字符串
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // display letters in reverse order
    for (int i = word.size() - 1; i >= 0; i--)
        cout << word[i];

    cout << "\nBye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.9 将数组中字符顺序反转
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // physically modify string object
    char temp;

    //法一：
    //for (int i = 0, j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //法二：
    int i, j;
    for (       i = 0, j = word.size() - 1;                i < j;           ++i,--j       )
    {                       // start block
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }                       // end block

    //***注***
    //for (int i = 0, int j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //报错：j未声明，原因：书P116

    cout << word << "\nDone\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.10 注意=与==运算符的区别
#if 0
int main()
{
    using namespace std;
    int quizscores[10] =
    { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is a 20\n";

    cout << "Doing it dangerously wrong:\n";
    for (i = 0; quizscores[i] = 20; i++)
        cout << "quiz " << i << " is a 20\n";

    // cin.get();
    return 0;
}
#endif


//程序清单5.11 for循环和strcmp()协同工作(使用的是C风格字符串)
#if 0
int main()
{
    using namespace std;
    char word[5] = "?ate";

    for (char ch = 'a'; strcmp(word, "mate"); ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单5.12 for循环和string类字符串的特性协同工作(使用的是string类字符串)
#if 0
int main()
{
    using namespace std;
    string word = "?ate";

    for (char ch = 'a'; word!= "mate"; ch++)
    {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单5.13 while循环
#if 0
const int ArSize = 20;
int main()
{
    using namespace std;
    char name[ArSize];

    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;                  // start at beginning of string
    while (name[i] != '\0')     // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif
//程序清单5.13 while循环(使用string类)
#if 0
const int ArSize = 20;
int main()
{
    using namespace std;
    string name;

    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    int i = 0;                  // start at beginning of string
    while (name[i] != '\0')     // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;                    // don't forget this step
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.14 编写延时循环，使用wait或使用clock()
#if 0
#include <ctime> // describes clock() function, clock_t type

int main()
{
    //方法1：
    long wait = 0;
    while (wait < 1000000000)
        wait++;


    //方法2：
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
                                                                           //CLOCKS_PER_SEC：每秒钟包含的系统时间单位数
    clock_t delay = secs * CLOCKS_PER_SEC;  // convert to clock ticks
                                                                          //将秒为单位的数转化为系统时间单位为单位的数
    cout << "starting\a\n";
    clock_t start = clock();

    while (clock() - start < delay)        // wait until time elapses
        ;                                   // note the semicolon

    cout << "done \a\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.15 do...while循环
#if 0
int main()
{
    using namespace std;
    int n;

    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do
    {
        cin >> n;       // execute body
    } while (n != 7);   // then test
    //或：
    //for (;;)
    //{
    //    cin >> n;
    //    if (n == 7)
    //        break;
    //}

    cout << "Yes, 7 is my favorite.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//基于范围的for循环(C++11)
#if 0
int main(void)
{
    //依次显示数组的元素
    double prices[5] = {4.99,10.99,6.87,7.99,8.49};
    for (double x : prices)
        std::cout << x << std::endl;

    putchar('\n');

    //依次修改数组的元素，并显示出来
    for (double& x : prices)
        x = x * 0.8;
    for (double x : prices)
    std::cout << x << std::endl;

    return 0;
}
#endif


//程序清单5.16 读取来自键盘的文本输入，利用哨兵字符'#' (cin不读入空白字符)
#if 0
int main()
{
    using namespace std;
    char ch;
    int count = 0;      // use basic input

    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;          // get a character

    while (ch != '#')   // test the character
    {
        cout << ch;     // echo the character
        ++count;        // count the character
        cin >> ch;      // get the next character
    }

    cout << endl << count << " characters read\n";
    // get rid of rest of line
         // while (cin.get() != '\n')
            // ;
    //cin.get();
    return 0;
}
#endif


//程序清单5.17 读取来自键盘的文本输入，利用哨兵字符'#' (cin.get()会读入空格字符)
#if 0
int main()
{
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);        // use the cin.get(ch) function

    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch);    // use it again
    }

    cout << endl << count << " characters read\n";
    // get rid of rest of line
        // while (cin.get() != '\n')
        //    ;
        //cin.get();
    return 0;
}
#endif


//程序清单5.18 读取来自键盘或文件的文本输入，通过cin的fail()来表示检测到EOF
#if 0
int main()
{
    using namespace std;

    char ch;
    int count = 0;

    cin.get(ch);        // attempt to read a char
    
    while (cin.fail() == false)  // test for EOF
    {
        cout << ch;     // echo character
        ++count;
        cin.get(ch);    // attempt to read another char
    }

    cout << endl << count << " characters read\n";

    return 0;
}
//***注***
//可以键盘输入^Z来模拟EOF让程序停止运行，也可以直接在命令行环境用<让程序读入一个文件
//命令行环境下输入cd D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 5\code1\Project1\x64\Debug
//再输入Project1.exe<5.18.txt
#endif


//读取来自键盘或文件的文本输入，通过C++的istream和ostream类中
//类似C语言的getchar()和putchar()功能的成员函数来检测EOF
#if 0
int main()
{
    using namespace std;

    char ch;
    int count = 0;

   ch= cin.get();        

    while (ch!=EOF) 
    {
        cout.put(ch) ; 

        if(ch!='\n')
        ++count;

        ch=cin.get();
    }
    //或：
    //while ((ch=cin.get()) != EOF)
    //{
    //    cout.put(ch);

    //    if (ch != '\n')
    //        ++count;
    //}

    cout << endl << count << " characters read\n";

    return 0;
}
//***注***此系统的char默认为有符号char，所以可以存EOF代表的-1，把ch声明为char没问题，
// 否则，要声明为int ch并且改为cout.put(char(ch))
#endif


//程序清单5.20 声明并初始化二维数组，显示二维数组的内容
#if 0
const int Cities = 5;
const int Years = 4;

int main()
{
    using namespace std;
    const char* cities[Cities] =   // array of pointers
    {                               // to 5 strings
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    //或法二：
    //const char cities[Cities][25] =   // array of pointers
    //{                               // to 5 strings
    //    "Gribble City",
    //    "Gribbletown",
    //    "New Gribble",
    //    "San Gribble",
    //    "Gribble Vista"
    //};
    //或法三：
    //const string cities[Cities] =   // array of pointers
    //{                               // to 5 strings
    //    "Gribble City",
    //    "Gribbletown",
    //    "New Gribble",
    //    "San Gribble",
    //    "Gribble Vista"
    //};

    int maxtemps[Years][Cities] =   // 2-D array
    {
        {96, 100, 87, 101, 105},   // values for maxtemps[0]
        {96, 98, 91, 107, 104},   // values for maxtemps[1]
        {97, 101, 93, 108, 107}, // values for maxtemps[2]
        {98, 103, 95, 109, 108}   // values for maxtemps[3]
    };

    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        cout << cities[city] << ":\t";

        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";

        cout << endl;
    }
    // cin.get();
    return 0;
}
#endif