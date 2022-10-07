#define _CRT_SECURE_NO_WARNINGS 1

// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// 基类
// Base Class Using DMA
class baseDMA
{
private:
    char* label;
    int rating;

public:
    baseDMA(const char* l = "null", int r = 0);//构造函数
    baseDMA(const baseDMA& rs);//复制构造函数
    virtual ~baseDMA();//虚析构函数
    baseDMA& operator=(const baseDMA& rs);//赋值运算符重载函数
    friend std::ostream& operator<<(std::ostream& os,
        const baseDMA& rs);
};

// 派生类的实现不使用new的情况
// derived class without DMA 
// 不显式声明析构函数(使用默认的析构函数和自动使用基类的析构函数)
// no destructor needed
// 使用默认的复制构造函数和和在默认的复制构造函数的函数头显式使用基类的复制构造函数
// uses implicit copy constructor 
// 使用默认的赋值运算符重载函数和自动使用基类的赋值运算符重载函数
// uses implicit assignment operator
class lacksDMA :public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char* l = "null",
        int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& os,
        const lacksDMA& rs);
};

// 派生类的实现使用new的情况
// derived class with DMA
class hasDMA :public baseDMA
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);//构造函数
    hasDMA(const char* s, const baseDMA& rs);//构造函数
    ~hasDMA();//定义显式的析构函数
    hasDMA(const hasDMA& hs);//定义显式的复制构造函数
    hasDMA& operator=(const hasDMA& rs);//定义显式的赋值运算符重载函数
    friend std::ostream& operator<<(std::ostream& os,
        const hasDMA& rs);
};

#endif
