#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//14.6 复习题
//4.
#if 0
//题目问生成的类声明
//所以生成
class Stack  <Worker*>                      
{
private:
    enum { MAX = 10 };  // constant specific to class 明示常量
    Worker* items[MAX];     // holds stack items
    int top;                      // index for top stack item

public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Worker*& item); // add item to stack
    bool pop(Worker*& item);        // pop top into item
};
#endif


//5.
//链接无
#if 1
#include <string>
#include <valarray>
#include "14.6.5.h"

int main()
{
	std::valarray<std::string>s_shuzu;

    //错误：这样生成的是指针栈
	/*double a[20] = {};
	Stack<double *>s1;*/
    //改正：
    //cxqd14.17.h中有ArrayTP类模板
    //Stack< ArrayTP<double,100> >  stack;

	//Worker* p_w = Worker w1;//报错：不允许创建抽象基类的对象
	Worker* p_w;//此时未生成Worker类对象P473
	Stack<Worker*>s2[20];

    //或：
    //ArrayTP<Stack<Worker*>, 100>arr_stk;

	return 0;
}
#endif