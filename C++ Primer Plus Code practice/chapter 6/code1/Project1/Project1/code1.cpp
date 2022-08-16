#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单6.1 循环与分支语句配合使用
#if 0
int main()
{
    using std::cin;     // using declarations
    using std::cout;

    char ch;
    int spaces = 0;
    int total = 0;

    cin.get(ch);
    while (ch != '.')   // quit at end of sentence
    {
        if (ch == ' ')  // check if ch is a space
            ++spaces;

        ++total;        // done every time
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.2 分支语句：if...else...语句
#if 0
int main()
{
    char ch;

    std::cout << "Type, and I shall repeat.\n";

    std::cin.get(ch);
    while (ch != '.')
    {
        if (ch == '\n')
            std::cout << ch;        // done if newline
        else
            std::cout << ++ch;   // done otherwise

        std::cin.get(ch);
    }
    // try ch + 1 instead of ++ch for interesting effect
    //***细节比较***
    //++ch后ch类型仍为char
    //ch+1后ch类型升级为int

    std::cout << "\nPlease excuse the slight confusion.\n";
    // std::cin.get();
    // std::cin.get();
    return 0;
}
#endif


//程序清单6.3 if...else...if...else结构
#if 0
const int Fave = 27;

int main()
{
    using namespace std;
    int n;

    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: ";

    do
    {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again: ";
        else if (n > Fave)
            cout << "Too high -- guess again: ";
        else
            cout << Fave << " is right!\n";

    } while (n != Fave);
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.4 cin只读取一个字符，并用 if...else...if...else结构，||逻辑运算符
#if 0
int main()
{
    using namespace std;
    cout << "This program may reformat your hard disk\n"
        "and destroy all your data.\n"
        "Do you wish to continue? <y/n> ";//利用字符串的拼接特性

    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')             // y or Y
        cout << "You were warned!\a\a\n";
    else if (ch == 'n' || ch == 'N')        // n or N
        cout << "A wise choice ... bye\n";
    else
        cout << "That wasn't a y or n! Apparently you "
        "can't follow\ninstructions, so "
        "I'll trash your disk anyway.\a\a\a\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.5 循环、&&逻辑运算符、分支运算符的应用
#if 0
const int ArSize = 6;
int main()
{
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients) "
        << "of\nyour neighbors. Program terminates "
        << "when you make\n" << ArSize << " entries "
        << "or enter a negative value.\n";

    int i = 0;
    float temp;

    cout << "First value: ";
    cin >> temp;

    while (i < ArSize && temp >= 0) // 2 quitting criteria
    {
        naaq[i] = temp;
        ++i;// i可以指示输入了多少个值

        if (i < ArSize)             // room left in the array,
        {
            cout << "Next value: ";
            cin >> temp;            // so get next value
        }
    }

    if (i == 0)
        cout << "No data--bye\n";
    else
    {
        cout << "Enter your NAAQ: ";

        float you;
        cin >> you;

        int count = 0;

        for (int j = 0; j < i; j++)
            if (naaq[j] > you)
                ++count;

        cout << count;
        cout << " of your neighbors have greater awareness of\n"
            << "the New Age than you do.\n";
    }
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.6 使用一系列 if...else...if...else结构
#if 0
const char* qualify[4] =       // an array of pointers*/
{                               // to strings
    "10,000-meter race.\n",
    "mud tug-of-war.\n",
    "masters canoe jousting.\n",
    "pie-throwing festival.\n"
};

int main()
{
    using namespace std;

    int age;
    cout << "Enter your age in years: ";
    cin >> age;

    int index;

    if (age > 17 && age < 35)
        index = 0;
    else if (age >= 35 && age < 50)
        index = 1;
    else if (age >= 50 && age < 65)
        index = 2;
    else
        index = 3;

    cout << "You qualify for the " << qualify[index];
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.7 !逻辑运算符
#if 0
#include <climits>

bool is_int(double);

int main()
{
    using namespace std;
    double num;

    cout << "Yo, dude! Enter an integer value: ";
    cin >> num;
    while (!is_int(num))    // continue while num is not int-able
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }

    int val = int(num);    // type cast
    cout << "You've entered the integer " << val << "\nBye\n";
    // cin.get();
    // cin.get();
    return 0;
}

bool is_int(double x)//double 类型足以存储典型的int值，然后对输入的值进行逻辑判断
{
    if (x <= INT_MAX && x >= INT_MIN)   // use climits values
        return true;
    else
        return false;
}
#endif


//程序清单6.8 使用头文件cctype中提供的函数
#if 0
#include <cctype>              // prototypes for character functions

int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
        " to terminate input.\n";
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);                // get first character
    while (ch != '@')            // test for sentinel
    {
        if (isalpha(ch))         // is it an alphabetic character?
            chars++;
        else if (isspace(ch))    // is it a whitespace character?
            whitespace++;
        else if (isdigit(ch))    // is it a digit?
            digits++;
        else if (ispunct(ch))    // is it punctuation?
            punct++;
        else
            others++;
        cin.get(ch);            // get next character
    }

    cout << chars << " letters, "
        << whitespace << " whitespace, "
        << digits << " digits, "
        << punct << " punctuations, "
        << others << " others.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.9 条件运算符
#if 0
int main()
{
    using namespace std;

    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "The larger of " << a << " and " << b;

    int c = a > b ? a : b;   // c = a if a > b, else c = b

    cout << " is " << c << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.10 switch语句
#if 0
using namespace std;

void showmenu();   // function prototypes
void report();
void comfort();

int main()
{
    showmenu();

    int choice;
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:   cout << "\a\n";
            break;
        case 2:   report();
            break;
        case 3:   cout << "The boss was in all day.\n";
            break;
        case 4:   comfort();
            break;
        default:   cout << "That's not a choice.\n";
        }

        showmenu();
        cin >> choice;
    }
    //***注***
    //若输入字母，则会一直执行default标签对应的功能。

    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
        "1) alarm           2) report\n"
        "3) alibi           4) comfort\n"
        "5) quit\n";
}
void report()
{
    cout << "It's been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}
void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think\n"
        "you are the finest CEO in the industry.\n";
}
#endif


//程序清单6.11 将枚举量用作标签
#if 0
// create named constants for 0 - 6
enum { red, orange, yellow, green, blue, violet, indigo };
//只使用符号常量对应的枚举量，而不使用枚举类型的变量，则可以省略枚举类型的名称

int main()
{
    using namespace std;
    
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;

    while (code >= red && code <= indigo)
    {
        switch (code)
        {
        case red: cout << "Her lips were red.\n"; break;
        case orange: cout << "Her hair was orange.\n"; break;
        case yellow: cout << "Her shoes were yellow.\n"; break;
        case green: cout << "Her nails were green.\n"; break;
        case blue: cout << "Her sweatsuit was blue.\n"; break;
        case violet: cout << "Her eyes were violet.\n"; break;
        case indigo: cout << "Her mood was indigo.\n"; break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.12 continue语句，break语句
#if 0
const int ArSize = 80;

int main()
{
    using namespace std;

    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);

    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";

    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];    // display character

        if (line[i] == '.') // quit if it's a period
            break;
        if (line[i] != ' ') // skip rest of loop
            continue;

        spaces++;
    }
    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.13 读取数字的循环(当输入了非规定的数据时结束循环)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
        << " fish <q to terminate>.\n";
    cout << "fish #1: ";

    int i = 0;                                                      // i 是数组的索引值
    while (i < Max && cin >> fish[i]) {
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    }
                                                                        //退出循环后 i 的值相当于数组的元素数量
    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += fish[j];

    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of "
        << i << " fish\n";

    cout << "Done.\n";
    // code to keep VC execution window open if q is entered
    //	if (!cin)  // input terminated by non-numeric response
    //	{
    //	    cin.clear();  // reset input
    //	    cin.get();    // read q
    //	}
    //	cin.get();    // read end of line after last input
    //	cin.get();    // wait for user to press <Enter>
    return 0;
}
#endif


//程序清单6.14 读取数字的循环(当输入了非规定的数据时继续读取输入)
#if 0
const int Max = 5;

int main()
{
    using namespace std;

    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";

    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "round #" << i + 1 << ": ";

        while (!(cin >> golf[i]))//输入非规定的数据时cin返回false
        {
            cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

            while (cin.get() != '\n')
                continue;    //消耗掉错误的输入

            cout << "Please enter a number: ";//提示用户再输入
        }

    }

    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    // report results
    cout << total / Max << " = average score "
        << Max << " rounds\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.15 向文件输入内容
#if 0
#include <fstream>                  // for file I/O        
                                                    //1.包含头文件fstream(其中定义了ofstream类)
int main()
{
    using namespace std;

    ofstream outFile;                    // create object for output
                                                     //2.声明一个ofstream对象                                                   
    outFile.open("carinfo.txt");    // associate with a file
                                                     //3.将该对象与一个文件关联起来
    cout << "Enter the make and model of automobile: ";
    char automobile[50];
    cin.getline(automobile, 50);

    cout << "Enter the model year: ";
    int year;
    cin >> year;

    cout << "Enter the original asking price: ";
    double a_price;
    cin >> a_price;
    double d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using outFile instead of cout
    //4.像使用cout那样使用该ofstream对象
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;

    //5.使用完文件后，用close()将其关闭
    outFile.close();                // done with file

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单6.16 读取文件内容
#if 0
#include <fstream>                  // file I/O support
                                                    //1.包含头文件fstream(其中定义了ifstream类)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main()
{
    using namespace std;

    ifstream inFile;                       // object for handling file input
                                                    //2.声明一个ifstream对象                                                   
    cout << "Enter name of data file: ";
    char filename[SIZE];
    cin.getline(filename, SIZE);

    inFile.open(filename);           // associate inFile with a file
                                                    //3.将该对象与一个文件关联起来

    //检查文件是否被成功打开
    if (!inFile.is_open())//failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        // cin.get();    //keep window open
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;                         // number of items read

    inFile >> value;                     // get first value
                                                   //4.像使用cin那样使用该ifstream对象

    while (inFile.good())   // while input good and not at EOF
    {
        ++count;                // one more item read
        sum += value;       // calculate running total
        inFile >> value;     // get next value
    }

    //或写为：
    /*while (inFile >> value)   //inFile >> value返回inFile，执行bool转换后为true或false
    {
        ++count;                
        sum += value;
    }*/
    
    //确定循环终止的原因
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else//inFile.bad()为true
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    //5.使用完文件后，用close()将其关闭
    inFile.close();         // finished with the file
    // cin.get();
    return 0;
}
//***注***
//不使用命令行环境也能顺利读取文件
//scores.txt
#endif