#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <cstring>                 // string.h for some
#include "12.10.2.h"               // includes <iostream>
#include <cctype>
using std::cin;
using std::cout;

// initializing static class member 类声明之外对静态类数据成员初始化
int String::num_strings = 0;

// static method 静态成员函数只能访问静态数据成员
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char* s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];  // allot storage
    std::strcpy(str, s);             // initialize pointer
    num_strings++;               // set object count
}

String::String()                   // default constructor
{
    len = 0;

    //写法一：***注***使用此写法的话，析构函数的cout<<str
    //在打印出空指针指向的内容(实际上没有任何内容)后会强制停止运行
    //str = nullptr;
    //写法二：
    str = new char[1];//***注***此处为了与delete[]兼容
    str[0] = '\0';                 // default string

    num_strings++;
}

String::String(const String& st)//提供复制构造函数的定义，进行深复制
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char[len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    //cout << "\"" << str << "\" object deleted, ";
    --num_strings;                    // required
    //cout << num_strings << " left\n";
    delete[] str;                    // required
}

// overloaded operator methods    
// assign a String to a String
String& String::operator=(const String& st)
{
    if (this == &st)//1.检查是否是自我复制
        return *this;

    delete[] str;//2.释放str指向的原数据内容

    len = st.len;//3.为新字符串分配足够的内存空间
    str = new char[len + 1];
    std::strcpy(str, st.str);

    return *this;//4.实现连续赋值
}

// assign a C string to a String 
String& String::operator=(const char* s)
{
    delete[] str;

    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char& String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char& String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends
bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

// quick and dirty String input
istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];

    is.get(temp, String::CINLIM);//最多读入CINLIM-1个字符，并在字符末尾自动添加空字符

    if (is)//如果没有读取到空行
        st = temp;//调用构造函数

    while (is && is.get() != '\n')//如果没有读取到空行且cin.get()还没读到换行符
        continue;

    return is;//返回istream对象的值
}

String String::operator+(const String& s)const
{
    String temp;//会调用默认构造函数，num_strings的值加1

    temp.len = strlen(str) + strlen(s.str);
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, str);
    strcat(temp.str, s.str);

    return temp;//先调用复制构造函数，再调用析构函数
}

String operator+(const char* p, const String& s)
{
    String temp;//会调用默认构造函数，num_strings的值加1

    temp.len = strlen(p) + strlen(s.str);
    temp.str = new char[temp.len + 1];
    strcpy(temp.str, p);
    strcat(temp.str, s.str);

    return temp;//先调用复制构造函数，再调用析构函数
}

String operator+(const String& s, const char* p)
{
    return p + s;
}

void String::stringlow(void)
{
    char* temp = str;
    while (*temp)
    {
        if (isupper(*temp))
            *temp = tolower(*temp);
        temp++;
    }
}

void String::stringup(void)
{
//***注***
//错误写法：
    //while (*str)
    //{
    //    if (islower(*str))
    //        *str = toupper(*str);
    //    str++;
    //}
//正确写法：直接操作str指针的话函数结束时指针在字符串的'\0'处，所以选择不直接操作str指针
    char* temp = str;
    while (*temp)
    {
        if (islower(*temp))
            *temp = toupper(*temp);
        temp++;
    }
}

int String::has(const char ch) const
{
    int count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (*(str + i) == ch)
            count++;
    }

    return count;
}
#endif
