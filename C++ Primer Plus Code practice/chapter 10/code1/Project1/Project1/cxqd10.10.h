#define _CRT_SECURE_NO_WARNINGS 1

// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    //const int MAX = 10;//报错：非静态成员引用必须与特定对象相对
    enum { MAX = 10 };    // constant specific to class 创建符号常量
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();            //声明一个默认构造函数
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item& item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item& item);          // pop top into item
};
#endif

