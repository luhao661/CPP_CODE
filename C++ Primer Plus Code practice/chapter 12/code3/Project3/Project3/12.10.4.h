#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_4_H
#define BCLX12_10_4_H

typedef unsigned long Item;

class Stack
{
private:
    //***注***
    //const int MAX = 10;//可通过编译(特性：C++11类内初始化)
    //但是不能作为符号常量，因为此语句相当于在构造函数用成员初始化列表来初始化MAX
    //所以在类中相当于还没创建MAX
    enum { MAX = 10 };    // constant specific to class 创建符号常量
    Item *pitems;    // holds stack items
    int size;             //数组的元素个数
    int top;             //输入的数据个数
public:
    Stack(int n=MAX);            //声明一个构造函数
                            //(也可作为默认构造函数，也可作为类型转换)
    Stack(const Stack& st);    //声明一个复制构造函数
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item& item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item& item);          // pop top into item

    Stack& operator=(const Stack & st);//赋值运算符重载函数

    void traverse(void(*pf)(Item&))const;
};

#endif /*BCLX12_10_4_H*/
