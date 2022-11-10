#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_4_H
#define BCLX_15_8_4_H
// sales.h  -- exceptions and inheritance
#include <stdexcept>//声明了logic_error异常类系列和runtime_error异常类系列
#include <string>

class Sales
{
public:
    enum { MONTHS = 12 };   // could be a static const
    //也可放在private中
private:
    int year;
    double gross[MONTHS];

public:
    //嵌套类
    /**************************************************************************/
    class bad_index : public std::logic_error//逻辑错误中的索引值错误
    {
    private:
        int bi;  // bad index value

    public:
        explicit bad_index(int ix,//***注***仅限显式初始化，目的是防止出现隐式类型转换
            const std::string& s = "Index error in Sales object\n");
        int bi_val() const
        {
            return bi;
        }
        //virtual ~bad_index() throw() {} //C++98的功能：异常规范
        //或写为：(C++11已不使用异常规范)
        virtual ~bad_index()
        {}
    };
    /**************************************************************************/

    explicit Sales(int yy = 0);//构造函数，默认构造函数
    Sales(int yy, const double* gr, int n);

    int Year() const
    {
        return year;
    }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
    virtual ~Sales()
    {}
};

class LabeledSales : public Sales
{
private:
    std::string label;
public:
    /**************************************************************************/
    class nbad_index : public Sales::bad_index//对嵌套类进行继承
    {
    private:
        std::string lbl;
    public:
        nbad_index(const std::string& lb, int ix,
            const std::string& s = "Index error in LabeledSales object\n");
        const std::string& label_val() const
        {
            return lbl;
        }
        virtual ~nbad_index()
        {}
    };
    /**************************************************************************/

    explicit LabeledSales(const std::string& lb = "none", int yy = 0);
    LabeledSales(const std::string& lb, int yy, const double* gr, int n);

    const std::string& Label() const
    {
        return label;
    }
    virtual double operator[](int i) const;
    virtual double& operator[](int i);
    virtual ~LabeledSales()
    {}
};

#endif 
