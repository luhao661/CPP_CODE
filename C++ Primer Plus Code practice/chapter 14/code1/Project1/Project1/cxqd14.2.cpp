#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// studentc.cpp -- Student class using containment
#include "cxqd14.1.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;


// private method
ostream& Student::arr_out(ostream& os) const
{
    int i;
    int lim = scores.size();

    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
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


//public methods
double Student::Average() const
{
    if (scores.size() > 0)                          //类方法中可以通过被包含对象
        return scores.sum() / scores.size();//来调用其所属的类的方法
    else
        return 0;
}

const string& Student::Name() const
{
    return name;
}

double& Student::operator[](int i)//用于修改数据
{
    return scores[i];         // use valarray<double>::operator[]()
}

double Student::operator[](int i) const//用于显示数据
{
    return scores[i];
}


// friends
// 使用string类的方法的operator>>()版本
// use string version of operator>>()
istream& operator>>(istream& is, Student& stu)
{
    is >> stu.name;//使用string类的方法将输入存储到string对象中
    return is;
}

// use string friend getline(ostream &, const string &)
istream& getline(istream& is, Student& stu)
{
    getline(is, stu.name);
    return is;
}

// use string version of operator<<()
ostream& operator<<(ostream& os, const Student& stu)
{
    os << "Scores for " << stu.name << ":\n";//调用operator<<(ostream&, const string& )
    stu.arr_out(os);  // use private method for scores
    return os;           //***注***
}                              //此处调用stu.arr_out()方法的原因是valarray类没有提供
                               //显示数组内容的方法，所以必须自己定义方法来实现显示数组中的数据
#endif                    //不在此友元函数中进行定义的原因是可以把零乱的细节放在私有部分，使友元函数的编写更整洁