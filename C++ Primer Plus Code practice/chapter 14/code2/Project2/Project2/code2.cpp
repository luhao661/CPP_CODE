#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//14.6 复习题
//5.
//链接无
#if 0
#include <string>
#include <valarray>
#include "14.6.5.h"

int main()
{
	std::valarray<std::string>s_shuzu;

	double a[20] = {};
	Stack<double *>s1;

	//Worker* p_w = Worker w1;//报错：不允许创建抽象基类的对象
	Worker* p_w;//此时未生成Worker类对象P473
	Stack<Worker*>s2[20];

	return 0;
}
#endif