#define _CRT_SECURE_NO_WARNINGS 1

// string1.h -- fixed and augmented string class definition
#ifndef STRING1_H_
#define STRING1_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;             // pointer to string
    int len;                 // length of string
    static int num_strings; // number of objects 声明一个静态类数据成员
    static const int CINLIM = 80;  // cin input limit 作用域为类的常量
public:
    // static function 静态类成员函数
    static int HowMany();

    // constructors and other methods
    String(const char* s); // constructor
    String();               // default constructor
    String(const String&); //复制构造函数(注：复制构造函数不用于一般的赋值)
    ~String();              // destructor
    int length() const { return len; }//成员函数写成内联形式

    // overloaded operator methods    
    String& operator=(const String&);//赋值运算符重载函数
    String& operator=(const char*);//赋值运算符重载函数的重载
                                                    //作用：提高处理效率，不必再调用构造函数来进行类型转换后
                                                    //再调用赋值运算符重载函数进行赋值最后还要调用析构函数
    char& operator[](int i);
    const char& operator[](int i) const;//返回的是个不可修改的左值
    //或写成：char operator[](int i) const;

    // overloaded operator friends
    friend bool operator<(const String& st, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);
};
#endif
