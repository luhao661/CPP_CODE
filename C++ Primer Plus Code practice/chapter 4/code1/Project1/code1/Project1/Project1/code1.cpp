#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单4.1 使用数组
#if 0
int main()
{
    using namespace std;
    int yams[3];    // creates array with three elements
    yams[0] = 7;   // assign value to first element                                             //数组的赋值
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = { 20, 30, 5 }; // create, initialize array                            //数组的初始化                                                                                                                                                                    
// NOTE: If your C++ compiler or translator can't initialize
// this array, use static int yamcosts[3] instead of int yamcosts[3]

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2] * yamcosts[2];
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof yams;
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0];
    cout << " bytes.\n";

    char petkind[2][2] = { '\0' };
    petkind[1][0] = 'a';
    printf("%s",petkind[1]);                                                                //证明petkind数组初始化后元素都为'\0'
                                                                                                           //原因：部分初始化，编译器把其他未显式地初始化的元素均设为0
    // cin.get();                                                                                    //而ASCII码0，对应的正好是空字符。
    return 0; 
}
#endif


//程序清单4.2 使用字符串数组
#if 0
#include <cstring>  // for the strlen() function
int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];                             // empty array(存的是垃圾值)
    char name2[Size] = "C++owboy";  // initialized array
    // NOTE: some implementations may require the static keyword
    // to initialize the array name2

    cout << "Howdy! I'm " << name2;
    cout << "! What's your name?\n";
    cin >> name1;
    cout << "Well, " << name1 << ", your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << " bytes.\n";
    cout << "Your initial is " << name1[0] << ".\n";
    name2[3] = '\0';                // set to null character
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.3 用cin获取字符数组的输入时只会读取一个单词
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.4 用cin.getline()读取一行字符输入
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize);  // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.5 用cin.get()读取一行字符输入
#if 0
int main()
{
    using namespace std;
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.get(name, ArSize);    // read string, newline
    cin.get();                                                                  //写法一

    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, ArSize).get();                                 //写法二

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.6 混合读入字符和数字
#if 0
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year;
    cin.get();//或：cin.get(ch);                  
                  //或将两个类成员函数拼接写：(cin>>year).get()                 目的是消耗掉输入缓冲区的换行符

    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}
#endif


//程序清单4.7 使用string类型的变量来存储字符串(每次读入一个单词)；string对象与字符数组之间异同
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;

    char char_arr1[20];                    // create an empty array
    char char_arr2[20] = "ceshi1"; // create an initialized array
    string str1;                                 // create an empty string object 创建一个string类型的变量str1          (创建一个string类的对象str1)
    string str2 = "ceshi2";              // create an initialized string 创建并初始化一个string类型的变量str2

    cout << "Enter a kind of feline: ";
    cin >> char_arr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;                                // use cin for input    ***注***使用类对象str1的好处是，str1的长度可根据输入自动调整
    cout << "Here are some felines:\n";
    cout << char_arr1 << " " << char_arr2 << " "
        << str1 << " " << str2         // use cout for output
        << endl;
    cout << "The third letter in " << char_arr2 << " is "
        << char_arr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
        << str2[2] << endl;              // use array notation 访问元素的方法也是用索引值

    return 0;
}
#endif


//程序清单4.8 string对象的新特性(相比于数组)
#if 0
#include <string>               // make string class available
int main()
{
    using namespace std;
    string s1{ "penguin" };//数组和string类对象均可使用列表初始化
    string s2, s3;

    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1;//通过使用string类对象，可以直接用=号拷贝字符串
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";//string类对象支持C风格的初始化方式
    cout << "s2: " << s2 << endl;

    cout << "You can concatenate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;//通过使用string类对象，可以直接用+号拼接字符串
    cout << "s3: " << s3 << endl;
    cout << "You can append strings.\n";
    s1 += s2;//通过使用string类对象，可以直接用+=号把s2字符串附加到s1字符串
    cout << "s1 += s2 yields s1 = " << s1 << endl;
    s2 += " for a day";//S2字符串还可以为自身附加一个字符串字面量
    cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

    //cin.get();
    return 0;
}
#endif


//程序清单4.9 对比用于字符数组的技术和用于string对象的技术
#if 0
#include <string>               // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // assignment for string objects and character arrays  (assignment：赋值这里理解为拷贝)
    str1 = str2;                        // copy str2 to str1
    strcpy(charr1, charr2);     // copy charr2 to charr1

    // appending for string objects and character arrays
    str1 += " paste";             // add paste to end of str1
    strcat(charr1, " juice");   // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();         // obtain length of str1                            //格式：   类对象名.类方法
    int len2 = strlen(charr1);  // obtain length of charr1

    cout << "The string " << str1 << " contains "
        << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains "
        << len2 << " characters.\n";
    // cin.get();

    return 0;
}
#endif


//程序清单4.10 使用string类型的变量来存储字符串(每次读入一行)
#if 0                                       //对比程序清单4.7 使用string类型的变量来存储字符串(每次读入一个单词)
#include <string>                // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr[20];
    string str;

    cout << "Length of string in charr before input: "
        << strlen(charr) << endl;//***注***未初始化的数组的内容是未定义的(垃圾值)，strlen()检测空字符，所以空字符出现的位置是随机的
    cout << "Length of string in str before input: "
        << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20); // indicate maximum length     //可参考程序清单4.4 用cin.getline()读取一行字符输入
    cout << "You entered: " << charr << endl;                //***注***cin.getline()是处理字符串数组的函数

    cout << "Enter another line of text:\n";
    getline(cin, str);          // cin now an argument; no length specifier   //getline()不是类方法
    cout << "You entered: " << str << endl;                    //***注***getline(cin,str)是处理string类对象的函数
    
    cout << "Length of string in charr after input: "
        << strlen(charr) << endl;
    cout << "Length of string in str after input: "
        << str.size() << endl;
    // cin.get();

    return 0;
}
#endif


//使用C++新增类型：原始字符串
#if 0
int main(void)
{
    using namespace std;

    cout << R"(不使用转义序列输出""     \n   "\n")"<<endl<<'\n';

    cout << "使用转义序列输出"<<"\"\"   \\n  \"\\n\"\n\n";

    return 0;
}
#endif


//程序清单4.11 使用结构
#if 0
#include <string>
struct inflatable   // structure declaration 声明一个标记为inflatable的结构布局(结构模板)
{
    char name[20];
    float volume;
    double price;
};

struct ceshi
{
    std::string name;//string类对象也可以作为结构成员   前提条件：添加#include <string>；必须提供一条using编译指令，或者用std::string来引用它
    float volumn;
};

int main()
{
    using namespace std;
    inflatable guest =                              //声明并初始化一个以inflatable结构布局的结构变量
    {
        "Glorious Gloria",  // name value
        1.88,               // volume value
        29.99               // price value
    };  // guest is a structure variable of type inflatable
        // It's initialized to the indicated values
    inflatable pal                                     //C++11支持将列表初始化用于结构，且=号可不写
    {
        "Audacious Arthur",
        3.12,
        32.99
    };  // pal is a second variable of type inflatable



    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    // pal.name is the name member of the pal variable
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.12 拷贝结构
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable bouquet =
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;

    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;  // assign one structure to another 拷贝结构
    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.13 使用结构数组
#if 0
struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    using namespace std;
    inflatable guests[2] =          // initializing an array of structs
    {
        {"Bambi", 0.5, 21.99},      // first structure in array
        {"Godzilla", 2000, 565.99}  // next structure in array
    };

    cout << "The guests " << guests[0].name << " and " << guests[1].name
        << "\nhave a combined volume of "
        << guests[0].volume + guests[1].volume << " cubic feet.\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.14 使用&运算符
#if 0
int main()
{
    using namespace std;
    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cups)
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.15 使用指针
#if 0
int main()
{
    using namespace std;
    int updates = 6;        // declare a variable
    int* p_updates;        // declare pointer to an int

    p_updates = &updates;   // assign address of int to pointer 对指针变量赋值

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value
    *p_updates = *p_updates + 1;
    cout << "Now updates = " << updates << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单4.16 初始化指针
#if 0
int main()
{
    using namespace std;
    int higgens = 5;
    int* pt = &higgens;

    cout << "Value of higgens = " << higgens
        << "; Address of higgens = " << &higgens << endl;
    cout << "Value of *pt = " << *pt
        << "; Value of pt = " << pt << endl;
    // cin.get();
    return 0;
}
#endif


//C++对于指针赋值操作更加严格
#if 0
int main(void)
{
    int* pt;
    //pt = 0x00b8;     //C允许，但C++不允许  报错：不能将整数赋给指向int类型的指针
    pt = (int*)0x00b8;//C++允许，因为赋值语句两边都是整数的地址
                                  //***注***指针pt本身的类型不一定是int
    return 0;
}
#endif


//程序清单4.17 使用C++的new和delete运算符
#if 0
int main()
{
    using namespace std;

    int nights = 1001;
    int* pt = new int;         // allocate space for an int
    *pt = 1001;                 // store a value there

    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double* pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    delete(pt);
    delete(pd);

    // cin.get();
    return 0;
}
#endif


//程序清单4.18 使用动态数组并访问数组中的元素
#if 0
int main()
{
    using namespace std;

    double* p3 = new double[3]; // space for 3 doubles
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";                          //或写作：*(p3+1)

    p3 = p3 + 1;                  // increment the pointer

    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 - 1;                  // point back to beginning

    delete[] p3;                 // free the memory
    // cin.get();
    return 0;
}
#endif


//程序清单4.19 指针算术
#if 0
int main()
{
    using namespace std;

    double wages[3] = { 10000.0, 20000.0, 30000.0 };
    short stacks[3] = { 3, 2, 1 };

    // Here are two ways to get the address of an array
    double* pw = wages;     // name of an array = address
    short* ps = &stacks[0]; // or use address operator with array element
   
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";//使用数组的索引值访问两个元素
    cout << "stacks[0] = " << stacks[0]
        << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";//使用指针表示法访问两个元素
    cout << "*stacks = " << *stacks
        << ", *(stacks + 1) =  " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";
    // cin.get();
    return 0;
}
#endif


//程序清单4.20 
#if 0
#include <cstring>              // declare strlen(), strcpy()
int main()
{
    using namespace std;
    char animal[20] = "bear";   // animal holds bear
    const char* bird = "wren"; // bird holds address of string
    char* ps;                  // uninitialized

    cout << animal << " and ";  // display bear
    cout << bird << "\n";       // display wren
    // cout << ps << "\n";      //may display garbage, may cause a crash

    //输入字符串
    cout << "Enter a kind of animal: ";
    cin >> animal;              // ok if input < 20 chars
    // cin >> ps; Too horrible a blunder to try; ps doesn't point to allocated space

    ps = animal;                // set ps to point to string
    cout << ps << "!\n";       // ok, same as using animal
    cout << "Before using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;//强制类型转换，目的是显示字符串的地址
    cout << ps << " at " << (int*)ps << endl;

    //获得字符串的副本
    ps = new char[strlen(animal) + 1];  // get new storage
    strcpy(ps, animal);         // copy string to new storage
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;                   //以上是使用C风格字符串，对比程序清单4.8和4.9，
                                                                                             //C++string类型更为简单
    delete[] ps;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.21 用new创建动态结构
#if 0
struct inflatable   // structure definition
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;

    inflatable* ps = new inflatable; // allot memory for structure

    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);            // method 1 for member access

    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;               // method 2 for member access

    cout << "Enter price: $";
    cin >> ps->price;

    cout << "Name: " << (*ps).name << endl;                        // method 2
    cout << "Volume: " << ps->volume << " cubic feet\n"; // method 1
    cout << "Price: $" << ps->price << endl;                        // method 1
    delete ps;                        // free memory used by structure
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单4.22 使用new和delete来存储通过键盘输入的字符串(使用动态分配的内存的应用)
#if 0
#include <cstring>      // or string.h

using namespace std;
char* getname(void);   // function prototype

int main()
{
    char* name;        // create pointer but no storage

    name = getname();   // assign address of string to name

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed

    name = getname();   // reuse freed memory

    cout << name << " at " << (int*)name << "\n";
    delete[] name;     // memory freed again
    // cin.get();
    // cin.get();
    return 0;
}

char* getname()        // return pointer to new string
{
    char temp[80];      // temporary storage 块作用域，无链接，自动存储期

    cout << "Enter last name: ";
    cin >> temp;        //temp数组暂存输入的内容

    char* pn = new char[strlen(temp) + 1];//计算输入的字符数量并动态分配一个内存空间

    strcpy(pn, temp); // copy string into smaller space 
                                 //***注***strcpy()检测到temp中的'\0'后把'\0'也拷贝入pn指向的内存空间的相应位置，然后停止拷贝
    return pn;          // temp lost when function ends
}
#endif


//程序清单4.23 使用数组、结构、指针
#if 0
struct antarctica_years_end
{
    int year;
    /* some really interesting data, etc. */
};

int main()
{
    //------------------------------------------------------------------------------
    antarctica_years_end jiegou_shuzu[3]; //声明一个数组，内含三个结构

    jiegou_shuzu[0].year = 2003;

    std::cout << jiegou_shuzu->year << std::endl;
    //------------------------------------------------------------------------------

    antarctica_years_end jiegou01, jiegou02, jiegou03;//声明三个结构

    jiegou01.year = 1998;

    antarctica_years_end* p = &jiegou02;//声明并初始化一个指向结构的指针
    p->year = 1999;


    const antarctica_years_end* zhizhen_shuzu[3] =\
    { &jiegou01, &jiegou02, &jiegou03 };//声明一个数组，内含三个指针
 
    std::cout << zhizhen_shuzu[1]->year << std::endl;
    //------------------------------------------------------------------------------

    const antarctica_years_end** p_zhizhen_shuzu_1 \
        = zhizhen_shuzu;//声明并初始化一个指向指针的指针

    auto p_zhizhen_shuzu_2 = zhizhen_shuzu; //***注***C++11的auto可以为声明一个类型提供方便
                                                                           //编译器知道zhizhen_shuzu的类型，所以能够推断出p_zhizhen_shuzu_2的类型
    //也可以声明为 const antarctica_years_end ** p_zhizhen_shuzu_2 = zhizhen_shuzu; 

    std::cout << (*p_zhizhen_shuzu_1)->year << std::endl;
    std::cout << (  *(p_zhizhen_shuzu_2 + 1)  )->year << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单4.25 比较数组、vector对象、array对象
#if 0
#include <vector>   // STL(Standard Template Library，STL) C++98
#include <array>    // C++0x
int main()
{
    using namespace std;
    //------------------------------------------------------------------------------

    // C, original C++
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    //------------------------------------------------------------------------------

    // C++98 STL
    vector<double> a2(4);   // create vector with 4 elements
    //vector<double> a2(4) = { 1.0 / 3.0 , 1.0 / 5.0 , 1.0 / 7.0 , 1.0 / 9.0 }; 
                                                //不能将列表初始化用于vector对象(C++11可以这样做)
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    //vector<double> a5(4);
    //a5 = a2;                              //可以将一个vector对象赋给另一个vector对象
    //------------------------------------------------------------------------------

    // C++11-- create and initialize array object
    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };//能将列表初始化用于array对象
    array<double, 4> a4;
    a4 = a3;                                //可以将一个array对象赋给另一个array对象
    //------------------------------------------------------------------------------
    
    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    //  cin.get();
    return 0;
}
#endif