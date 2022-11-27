#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_16_5_H
#define CXQD_16_5_H

#include <iostream>

class Report
{
private:
    std::string str;

public:
    Report(const std::string s) : str(s)
    {
        std::cout << "Object created!\n"; 
    }
    ~Report()
    {
        std::cout << "Object deleted!\n";
    }
    void comment() const 
    {
        std::cout << str << "\n";
    }

};

#endif /*CXQD_16_5_H*/