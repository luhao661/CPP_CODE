#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// strngbad.cpp -- StringBad class methods
#include <cstring>                    // string.h for some
#include "cxqd12.1.h"

using std::cout;

//***注***
//1.不能在类声明中初始化不带const的静态成员变量，因为初始化了就意味着分配内存，
//而类只描述了如何分配内存，但并不分配内存
//2.初始化语句不用带static
// initializing static class member
int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char* s)
{
    len = std::strlen(s);             // set size

    str = new char[len + 1];          // allot storage

    std::strcpy(str, s);              // initialize pointer

    num_strings++;                    // set object count
    cout << num_strings << ": \"" << str
        << "\" object created\n";    // For Your Information
}

StringBad::StringBad()                // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");          // default string
    num_strings++;
    cout << num_strings << ": \"" << str
        << "\" default object created\n";  // FYI
}

StringBad::~StringBad()               // necessary destructor
{
    cout << "\"" << str << "\" object deleted, ";    // FYI
    --num_strings;                    // required
    cout << num_strings << " left\n"; // FYI
    delete[] str;                    // required
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
    os << st.str;
    return os;
}

#endif
