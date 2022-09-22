#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD12_8_H
#define CXQD12_8_H

#include <iostream>
using namespace std;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string& s = "Just Testing", int n = 0)
    {
        words = s;
        number = n; 
        cout << words << " constructed\n";
    }
    ~JustTesting() 
    {
        cout << words << " destroyed\n";
    }
    void Show() const
    {
        cout << words << ", " << number << endl; 
    }
};
#endif /*CXQD12_8_H*/