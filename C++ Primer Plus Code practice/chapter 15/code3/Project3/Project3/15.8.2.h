#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_2_H
#define BCLX_15_8_2_H

#include <iostream>
#include <stdexcept>

class bad_hmean:public std::logic_error//***注***必须要声明为公有继承，这样对象才能使用what()方法
{
public:
    bad_hmean(const std::string& s = "计算调和平均数失败\n")
        :std::logic_error(s)
    {}
};

class bad_gmean:public std::logic_error
{
public:
    bad_gmean(const std::string& s = "计算几何平均数失败\n")
        :std::logic_error(s)
    {}
};

#endif