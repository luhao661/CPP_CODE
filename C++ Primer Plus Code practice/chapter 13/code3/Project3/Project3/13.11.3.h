#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX13_11_3_H 
#define BCLX13_11_3_H
#include <iostream>

class DmaABC
{
private:
	char* label;
	int rating;

public:
	DmaABC(const char*s="no data", int r=0);
    DmaABC(const DmaABC& d);
	virtual ~DmaABC();
	virtual void View()const=0;
};

class baseDMA:public DmaABC
{
private:

public:
    baseDMA(const char* l = "null", int r = 0);//构造函数
    baseDMA(const baseDMA& rs);//复制构造函数
    virtual ~baseDMA();//虚析构函数
    baseDMA& operator=(const baseDMA& rs);//赋值运算符重载函数
    friend std::ostream& operator<<(std::ostream& os,
        const baseDMA& rs);
    virtual void View()const;
};

class lacksDMA :public DmaABC
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
    virtual void View()const;
};

class hasDMA :public DmaABC
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
    virtual void View()const;
};

#endif
