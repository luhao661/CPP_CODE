#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_3_1_H
#define BCLX_15_8_3_1_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

class unexpected_mean :public std::logic_error//***注***必须要声明为公有继承，这样对象才能使用what()方法
{
private:
    double m_a;
    double m_b;

public:
    unexpected_mean(double a=0, double b=0,//构造函数和默认构造函数
        const std::string& s = "计算平均数时出错\n")
        :m_a(a), m_b(b), logic_error(s)
    {}
    virtual ~unexpected_mean()
    {}

    virtual void message(void)const = 0//纯虚函数，
    {                                                   //unexpected_mean类可作为ABC
        cout << "您输入了" << m_a << "和" << m_b << endl;
    }                                                    
};

class bad_hmean :public unexpected_mean
{
public:
    bad_hmean(double a, double b,
        const std::string& s = "计算调和平均数失败\n")
        :unexpected_mean(a,b,s)
    {}
    void message(void)const
    {
        cout << "hmean()函数出现异常" << endl;
        cout << what();
        unexpected_mean::message();
    }
};

class bad_gmean :public unexpected_mean
{
public:
    bad_gmean(double a, double b,
        const std::string& s = "计算几何平均数失败\n")
        :unexpected_mean(a, b, s)
    {}
    void message(void)const
    {
        cout << "gmean()函数出现异常" << endl;
        cout << what();
        unexpected_mean::message();
    }
};

#endif