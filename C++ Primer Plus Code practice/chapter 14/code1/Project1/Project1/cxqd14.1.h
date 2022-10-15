#define _CRT_SECURE_NO_WARNINGS 1

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>    //使用string类
#include <valarray>//使用valarray类

class Student
{
private:
    typedef std::valarray<double> ArrayDb;//把包含double类型数据的
                                                                        //valarray类取别名为ArrayDb
    std::string name;       // contained object
    ArrayDb scores;         // contained object
    // private method for scores output
    std::ostream& arr_out(std::ostream& os) const;

public:
    Student(const std::string& s, int n)//构造函数
        : name(s), scores(n)//***注***在初始化列表中使用的是成员名
    {}
    Student(const std::string& s, const ArrayDb& a)
        : name(s), scores(a)
    {}
    Student(const char* str, const double* pd, int n)
        : name(str), scores(pd, n) 
    {}
    Student() : name("Null Student"), scores()//默认构造函数
    {}//使用了成员初始化列表，对name和scores初始化
       //其中调用了string类的构造函数和scores类的默认构造函数

    //使用了构造函数的类型转换特性，然而只允许显式类型转换
    explicit Student(const std::string& s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}

    ~Student() {}

    double Average() const;
    const std::string& Name() const;
    double& operator[](int i);
    double operator[](int i) const;
    // friends
    // input
    friend std::istream& operator>>(std::istream& is,
        Student& stu);  // 1 word
    friend std::istream& getline(std::istream& is,
        Student& stu);  // 1 line
    // output
    friend std::ostream& operator<<(std::ostream& os,
        const Student& stu);
};

#endif
