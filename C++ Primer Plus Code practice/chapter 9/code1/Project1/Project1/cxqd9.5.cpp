#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
extern double warming;  // use warming from another file 引用式声明

// function prototypes
void update(double dt);
void local();

using std::cout;
void update(double dt)      // modifies global variable
{
    extern double warming;  // optional redeclaration 可选的引用式声明
    warming += dt;          // uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";
}

void local()                // uses local variable 使用自动变量，隐藏了文件开头的warming变量
{
    double warming = 0.8;   // new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
    // Access global variable with the
    // scope resolution operator
    cout << "But global warming = " << ::warming;//***注***
    cout << " degrees.\n";                                           // ::作用域解析运算符
}                                                                                    //表示使用该变量的全局版本
#endif