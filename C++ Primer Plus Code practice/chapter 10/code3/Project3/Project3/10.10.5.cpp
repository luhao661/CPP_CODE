#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.5.h"

Stack::Stack()    // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item& item)
{
    if (top < MAX)
    {
        items[top++] = item;//***注***top代表索引值
        return true;                 //先从items[0]处存入数据
    }                                       //操作完成后top=1，代表的是元素个数
    else                                  //若再次调用push方法，top仍先作为索引值，再作为元素个数
        return false;
}

bool Stack::pop(Item& item)
{
    if (top > 0)                    //***注***top代表元素个数
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

#endif