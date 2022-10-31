#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_14_7_2_H
#define BCLX_14_7_2_H

#include <string>
#include <valarray>
#include <iostream>

template <class T1, class T2 = int>//可以为类型参数提供默认值
class Pair
{
private:
    T1 a;      //T1被替换成valarray<int>
    T2 b;

public:
    //Pair(const T1& aval, const T2& bval) : a(aval), b(bval)//调用valarray类的复制构造函数
    //{}//***注***使用此构造函数的话，会报错：形参与实参类型不匹配
    //***注***法二见14.7.1.h

    Pair(int* aval, int* bval, int y) : a(aval, y), b(bval, y)
    {}
    Pair(int a, int b) : a(a), b(b)//生成一个含a个int类型值的数组，和一个含b个int类型值的数组
    {}
    Pair()
    {}
    T1& first();//用于修改a
    T2& second();
    T1 first() const //用于只读取a   ***注***两个同名函数虽然特征标相同
    {                       //但一个是const成员函数，一个不是
        return a;
    }
    T2 second() const
    {
        return b;
    }
    //PairArrayT1,T2>& operator=(PairArray<T1,T2>(T1 x, T2 y));
    //PairArray & operator=(PairArray(T1 x, T2 y));
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
    return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
    return b;
}


typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : std::string, PairArray//私有继承
{
private:
    int number_of_years;

public:
    Wine(const char* l, int y, const int yr[], const int bot[]);
    Wine(const char* l, int y);

    void GetBottles(void);
    void Show(void)const;
    const std::string& Label(void)const;
    int sum(void)const;
};

#endif