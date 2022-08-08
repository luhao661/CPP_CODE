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


//程序清单4.2 在数组中使用字符串
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


//程序清单4.3 用cin获取字符数组的输入时只读取一个单词
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
    s2 += " for a day";//S2字符串还可以附加一个字符串字面量
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
#if 1
int main(void)
{
    using namespace std;

    cout << R"(不使用转义序列输出""     \n   "\n")"<<endl<<'\n';

    cout << "使用转义序列输出"<<"\"\"   \\n  \"\\n\"\n\n";

    return 0;
}
#endif
