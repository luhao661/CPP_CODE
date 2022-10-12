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
	DmaABC(const char*s="no data",int r=0);
    //错误理解：
    //DmaABC(const DmaABC& d); 抽象基类不需要复制构造函数，
    //因为抽象基类不创建该类的对象，不会出现将一个对象初始化为另一个对象的情况
    //正确理解：
    //DmaABC(const DmaABC& d);要写
    //因为派生类的构造函数baseDMA(const baseDMA& rs)的类实现会用
    //成员初始化列表调用抽象基类的复制构造函数
    //而且此类使用了new，所以必须显式地定义三大函数
    DmaABC(const DmaABC& d);
	virtual ~DmaABC();
    DmaABC& operator=(const DmaABC& d);
    //friend std::ostream& operator<<(std::ostream& os,
    //    const baseDMA& rs);//***注***不生成对象，可以不使用
	virtual void View()const=0;

protected://***注***由于派生类不能直接访问抽象基类的私有成员，
    char* See_label(void)const;//所以仅服务器可以通过protected成员来访问抽象基类的私有成员
    int See_rating(void)const;//若将这两个函数放入public的话，则客户和服务器都能访问了，
};                                     //所以使用protected更好

class baseDMA:public DmaABC
{
//可以没有private成员

public:
    baseDMA(const char* l = "null", int r = 0);//构造函数

    //由于派生类没有使用new，所以可以不显式地定义三大函数
    baseDMA(const baseDMA& rs);//复制构造函数
    virtual ~baseDMA();//虚析构函数
    baseDMA& operator=(const baseDMA& rs);//赋值运算符重载函数

    virtual void View(void)const;
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
    virtual void View(void)const;
};

class hasDMA :public DmaABC
{
private:
    char* style;
public:
    hasDMA(const char* s = "none", const char* l = "null",
        int r = 0);//构造函数
    hasDMA(const char* s, const baseDMA& rs);//构造函数
    hasDMA(const hasDMA& hs);//定义显式的复制构造函数
    ~hasDMA();//定义显式的析构函数
    hasDMA& operator=(const hasDMA& rs);//定义显式的赋值运算符重载函数
    virtual void View()const;
};

#endif
