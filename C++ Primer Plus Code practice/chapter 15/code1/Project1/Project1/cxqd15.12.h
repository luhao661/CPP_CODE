#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_15_12_H
#define CXQD_15_12_H

#include <iostream>
#include <cmath> // or math.h, unix users may need -lm flag
#include <string>
#include "cxqd15.10.h"//包括bad_hmean类和bad_gmean类

class demo
{
private:
    std::string word;

public:
    demo(const std::string& str)
    {

        word = str;
        std::cout << "demo " << word << " created\n";
    }
    ~demo()
    {
        std::cout << "demo " << word << " destroyed\n";
    }
    void show() const
    {
        std::cout << "demo " << word << " lives!\n";
    }
};

#endif
