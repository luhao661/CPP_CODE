#define _CRT_SECURE_NO_WARNINGS 1

// worker0.h  -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker   // an abstract base class 抽象基类
{
private:
    std::string fullname;
    long id;

public:
    Worker(const std::string& s, long n)//构造函数
        : fullname(s), id(n)
    {}
    Worker() : fullname("no one"), id(0L)//默认构造函数
    {}
    virtual ~Worker() = 0;   // pure virtual destructor
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker
{
private:
    int panache;

public:
    Waiter(const std::string& s, long n, int p = 0)
        : Worker(s, n), panache(p) 
    {}
    Waiter(const Worker& wk, int p = 0)
        : Worker(wk), panache(p) 
    {}
    Waiter() : Worker(), panache(0) 
    {}
    void Set();
    void Show() const;
};

class Singer : public Worker
{
protected:
    enum {                                              //创建符号常量
        other, alto, contralto, soprano,
        bass, baritone, tenor
    };
    enum { Vtypes = 7 };

private:
    static char* pv[Vtypes];    // string equivs of voice types
    int voice;

public:
    Singer(const std::string& s, long n, int v = other)
        : Worker(s, n), voice(v) 
    {}
    Singer(const Worker& wk, int v = other)
        : Worker(wk), voice(v)//使用Worker类自动生成的复制构造函数
    {}
    Singer() : Worker(), voice(other) 
    {}
    void Set();
    void Show() const;
};

#endif
