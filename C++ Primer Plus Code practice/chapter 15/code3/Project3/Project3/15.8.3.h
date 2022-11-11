#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_3_H
#define BCLX_15_8_3_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

class bad_hmean :public std::logic_error//***注***必须要声明为公有继承，这样对象才能使用what()方法
{
private:
    double m_a;
    double m_b;

public:
    bad_hmean(double a,double b,
        const std::string& s = "计算调和平均数失败\n")
        :std::logic_error(s),m_a(a),m_b(b)
    {}
    //***注***以下写法不完整，报错：logic_error类不存在默认构造函数，所以必须对其使用显式初始化
    /*bad_hmean():m_a(0),m_b(0)
    {}*/
    bad_hmean():m_a(0),m_b(0), std::logic_error("none")
    {}
    void report(void)const
    {
        cout << "您输入了"<<m_a<<"和"<<m_b << endl;
        cout << "hmean()函数出现异常"<<endl;
    }
};

class bad_gmean :public std::logic_error
{
private:
    double m_a;
    double m_b;

public:
    bad_gmean(double a, double b, 
        const std::string& s = "计算几何平均数失败\n")
        :std::logic_error(s), m_a(a), m_b(b)
    {}
    bad_gmean() :m_a(0), m_b(0), std::logic_error("none")
    {}
    void report(void)const
    {
        cout << "您输入了" << m_a << "和" << m_b << endl;
        cout << "gmean()函数出现异常" << endl;
    }
};

#endif