#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "12.10.4.h"
#include <cstring>//memcpy()
#include <iostream>

Stack::Stack(int n):size(n),top(0)//成员初始化列表
{
    pitems = new Item[n];
    /*//***注***若不对数组中的元素初始化，则
    //后续打印出的索引值为0上的数据是垃圾值
    for (int index = 0; index < n; index++)
        *(pitems+index)=-1;*/
    //可以不初始化，用top的值来判断是否打印，和打印几个数据
}

Stack::Stack(const Stack& st)
{
    pitems = new Item[st.size];
    Item* st_temp;
    int index;
    for (index = 0,st_temp = st.pitems; index <= st.top; index++)
    {
        *(pitems + index) = *(st_temp+index);
    }
    //或使用memcpy()
    //memcpy(pitems,st.pitems,st.size*sizeof(Item));
    size = st.size;
    top = st.top;
}

Stack::~Stack()
{
    delete[]pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;//***注***此处不写为top==size-1
}                                   //此处top代表索引

bool Stack::push(const Item& item)
{
    if (!isfull())
    {
        *(pitems+top) = item;//***注***进入函数体时top代表索引值
        ++top;
        return true;                 //先从items[0]处存入数据
    }                                       //操作完成后top=1，代表的是元素个数
    else                                  //若再次调用push方法，top仍先作为索引值，再作为元素个数
        return false;
}

bool Stack::pop(Item& item)
{
    if (!isempty())                    //***注***进入函数体时top代表索引
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack& Stack::operator=(const Stack& st)//赋值运算符重载函数
{
    if (this == &st)//1.检查是否是自我复制
        return *this;

    delete[] pitems;//2.释放pitems指向的原数据内容

    pitems = new Item [st.size];//3.为新字符串分配足够的内存空间
   
    memcpy(pitems, st.pitems, st.size * sizeof(Item));

    size = st.size;
    top = st.top;

    return *this;//4.实现连续赋值
}

void Stack::traverse(void(*pf)(Item&))const//***注***此处void(*pf)(Item&)为函数原型无妨
{
    int index;
    for(index=0;index<top;index++) //***注***此处top代表元素个数
    {
        if (index == 0)
            std::cout << "输入的内容为：";
        (*pf)(*(pitems+index));
    }
    if (!index)
        std::cout << "没有数据输入！";
//也可以先判断index==top，写 "没有数据输入！"语句，后编写输出数据内容的语句
    std::cout.put('\n');
}

#endif