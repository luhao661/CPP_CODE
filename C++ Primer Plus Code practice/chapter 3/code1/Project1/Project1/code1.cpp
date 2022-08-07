#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//使用以下划线开头的变量名的变量会发生什么
#if 0
int main(void)
{
	using namespace std;
	int _ceshi=1;

	cout << _ceshi<<endl;           //在本系统中运行无异常

	return 0;
}
#endif


//程序清单3.1 查看类型的长度
#if 1
#include <climits>              // use limits.h for older systems
int main()
{
    using namespace std;
    int n_int = INT_MAX;        // initialize n_int to max int value
    short n_short = SHRT_MAX;   // symbols defined in climits file
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    // sizeof operator yields size of type or of variable
    cout << "int is " << sizeof(int) << " bytes." << endl;
    cout << "short is " << sizeof n_short << " bytes." << endl;
    cout << "long is " << sizeof n_long << " bytes." << endl;
    cout << "long long is " << sizeof n_llong << " bytes." << endl;
    cout << endl;

    cout << "Maximum values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;
    // cin.get();
    return 0;
}
#endif


//C++11新增初始化变量的方式——{}方式，是一种通用初始化方式
#if 0
int main(void)
{
    using namespace std;

    int num1 = {};
    int num2{10};
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}
#endif


//程序清单3.2 变量超越类型的范围限制(产生上溢或下溢)时产生的后果
#if 0
#define ZERO 0        // makes ZERO symbol for 0 value
#include <climits>  // defines INT_MAX as largest int value
int main()
{
    using namespace std;
    short sam_money = SHRT_MAX;    // initialize a variable to max value
    unsigned short sue_money = sam_money;// okay if variable sam_money already defined

    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl
        << "Add $1 to each account." << endl << "Now ";
    sam_money = sam_money + 1;
    sue_money = sue_money + 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited.\nPoor Sam!" << endl;
    sam_money = ZERO;
    sue_money = ZERO;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl;
    cout << "Take $1 from each account." << endl << "Now ";
    sam_money = sam_money - 1;
    sue_money = sue_money - 1;
    cout << "Sam has " << sam_money << " dollars and Sue has " << sue_money;
    cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.3 三种整型字面值
#if 0
int main()
{
    using namespace std;
    int chest = 42;     // decimal integer literal
    int waist = 0x42;   // hexadecimal integer literal
    int inseam = 042;   // octal integer literal

    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << " (42 in decimal)\n";
    cout << "waist = " << waist << " (0x42 in hex)\n";
    cout << "inseam = " << inseam << " (042 in octal)\n";
    // cin.get();
    return 0;
}
#endif


//程序清单3.4 使用控制符dec、hex、oct修改cout的默认格式(即十进制)
#if 0
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;      // manipulator for changing number base
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;      // manipulator for changing number base
    cout << "inseam = " << inseam << " (octal for 42)" << endl<<endl;

    inseam = 042;//以八进制形式存储
    cout << "inseam = " << inseam << " (octal for 042)" << endl;
    cout << dec;
    cout << "inseam = " << inseam << " (decimal for 042)" << endl;//以十进制形式显示

    // cin.get();
    return 0;
}
#endif


//***注***使用using编译指令时，cout不能再用作变量名；但使用std::cout时，cout还可以用作变量名
#if 0
int main(void)
{
    std::cout << "测试" << std::endl;
    int cout = 1;
    std::cout << cout << std::endl;

    return 0;
}
#endif


//程序清单3.5 使用char型变量
#if 0
int main()
{
    using namespace std;
    char ch;        // declare a char variable

    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.6 使用cout.put()显示单个字符
#if 0
int main()
{
    using namespace std;
    char ch = 'M';   // assign ASCII code for M to ch
    int i = ch;          // store same code in an int
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one to the character code:" << endl;
    ch = ch + 1;          // change character code in ch
    i = ch;               // save new character code in i
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // using the cout.put() member function to display a char
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);                                                                                                //此语句可用来替换cout<<ch
    cout << endl<<ch;
    // using cout.put() to display a char constant
    cout.put('!');
    putchar('\n');

    char ch1;
    cin >> ch1;
    int cunchudezhi_ch1=ch1;

    cout << ch1 << "ASCII的值是"<<cunchudezhi_ch1<<endl;

    //打印字符常量
    cout << 'a';
    cout.put('a');

    // cin.get();
    return 0;
}
#endif


//程序清单3.7 使用转义序列
#if 0
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan Z3!\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//使用wchar_t(宽字符类型)表示扩展字符集，使用新类型char16_t，char32_t
#if 0
int main(void)
{
    using namespace std;
    wchar_t zifu = L'P';//P是一个宽字符常量
    wcout << L"kuanzifuchuan" << endl;

    char16_t ch1 = u'q';
    char32_t ch2 = U'\U0000222B';
   
    return 0;
}
#endif


//程序清单3.8 float和double表示数字时在有效位数方面的差异
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point使用定点计数法

    float tub = 10.0 / 3.0;     // good to about 6 places   至少6位有效位
    double mint = 10.0 / 3.0;   // good to about 15 places   至少15位有效位
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;                     //证明float类型在该系统上能表示的有效位是前7位

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.9 float型数据运算时可能产生精度的下降
#if 0
int main()
{
    using namespace std;
    float a = 2.34E+22f;
    float b = a + 1.0f;                                             //float类型在该系统上能表示的有效位是前7位，因此修改第23位对这个值没有任何影响

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单3.10 使用算数运算符
#if 0
int main()
{
    using namespace std;
    float hats, heads;

    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    cout << "Enter a number: ";
    cin >> hats;
    cout << "Enter another number: ";
    cin >> heads;

    cout << "hats = " << hats << "; heads = " << heads << endl;
    cout << "hats + heads = " << hats + heads << endl;
    cout << "hats - heads = " << hats - heads << endl;
    cout << "hats * heads = " << hats * heads << endl;
    cout << "hats / heads = " << hats / heads << endl;

    cout << 10 / 3<<endl;                                                           //***注***若两个操作数都是整数，则结果为商的整数部分，小数部分被丢弃
    hats = 10 / 3;//得3，再转化成float型，在3后面添加小数点和0
    cout << hats<<endl;

    hats = 10.0 / 3;//得3.333333
    cout << hats << endl;

    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.11 除法运算
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Integer division: 9/5 = " << 9 / 5 << endl;
    cout << "Floating-point division: 9.0/5.0 = ";
    cout << 9.0 / 5.0 << endl;
    cout << "Mixed division: 9.0/5 = " << 9.0 / 5 << endl;
    cout << "double constants: 1e7/9.0 = ";
    cout << 1.e7 / 9.0 << endl;
    cout << "float constants: 1e7f/9.0f = ";
    cout << 1.e7f / 9.0f << endl;

    cout << 1.e7 / 9.0f << endl;//涉及两种类型的运算，两个值会被分别转换成两种类型的更高级别。

    // cin.get();
    return 0;
}
#endif


//程序清单3.12 求模运算符
#if 0
int main()
{
    using namespace std;
    const int Lbs_per_stn = 14;//1英石等于14磅
    int lbs;

    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;      // whole stone
    int pounds = lbs % Lbs_per_stn;     // remainder in pounds
    cout << lbs << " pounds are " << stone
        << " stone, " << pounds << " pound(s).\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单3.13 类型转换
#if 0
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3;     // int converted to float                            整型可以转化成浮点型
    int guess = 3.9832; // float converted to int
    int debt = 7.2E12;  // ***注***result not defined in C++   情况1：小数部分丢失，情况2：原来的值可能超出目标类型的取值范围，在这种情况下，结果将是不确定的

    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
    // cin.get();
    return 0;
}
#endif


//用{}方式初始化变量时的类型转换
#if 0
int main(void)
{
    using namespace std;
    //int a = {1.23};               //不允许缩窄
    //char a={128};               //不允许缩窄
     
    //int x = 66;
    //char a = {x};                 //编译器看来，x是个变量，其值可能很大，编译器判定为从int转换到char，不允许缩窄   (若改为char x=66，则可以)

    const int x = 66;          //***注***
    char a = {x};                 //此种情况允许，编译器认为只读变量x的值是66（可以理解为#define x 66），在char的范围内，可对a初始化      

    cout << a << endl;

    /*int x = 128;
    char a = x;
    cout << a << endl;*/              //若不使用{}方式初始化变量，则允许缩窄

    return 0;
}
#endif


//程序清单3.14 强制类型转换
#if 0
int main()
{
    using namespace std;
    int auks, bats, coots;// 海雀，蝙蝠，水鸟

    // the following statement adds the values as double,
    // then converts the result to int
    auks = 19.99 + 11.99;                  //19.99+11.99=31.98则auks=31

    // these statements add values as int
    bats = (int)19.99 + (int)11.99;   // old C syntax               C语法
    coots = int(19.99) + int(11.99);  // new C++ syntax       C++新语法
    cout << "auks = " << auks << ", bats = " << bats;
    cout << ", coots = " << coots << endl;

    char ch = 'Z';
    cout << "The code for " << ch << " is ";    // print as char
    cout << int(ch) << endl;                               // print as int
    cout << "Yes, the code is ";
    cout << static_cast<int>(ch) << endl;        // using static_cast

   // cin.get();
    return 0;
}
#endif