#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// studenti.cpp -- Student class using private inheritance
#include "cxqd14.4.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;


// private method
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}


// public methods
double Student::Average() const
{
    if (ArrayDb::size() > 0)             //使用类名和作用域解析运算符来调用基类的方法
        //return ArrayDb::sum() / ArrayDb::size();
        return sum() / valarray<double>::size();//P404派生类的方法可以访问基类的方法
    else                                           //而使用string::size()的原因是valarray类和string类都有size()方法
        return 0;                               //此处指明要用valarray类的size()方法
}

const string& Student::Name() const
{
    return (const string&)*this;//使用强制类型转换来访问基类的对象
}

double& Student::operator[](int i)
{
    return ArrayDb::operator[](i);         // use ArrayDb::operator[]()
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}


// friends
// use String version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
    is >> (string&)stu;
    return is;
}

// use string friend getline(ostream &, const string &)
istream& getline(istream& is, Student& stu)
{
    getline(is, (string&)stu);
    return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{                                         //使用强制类型转换来访问基类的友元函数
    os << "Scores for " << (const string&)stu << ":\n";
    stu.arr_out(os);  // use private method for scores
    return os;
}

#endif