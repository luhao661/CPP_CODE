#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include <iostream>
#include "9.6.4.h"

namespace SALES
{
	//从ar[]中拷贝n个数据到结构体中的sales数组中，
	//计算并存储其它三个成员的值,
	//sales数组若有空闲的空间，则空闲空间的元素赋值为0
	void setSales(Sales& s, const double ar[], int n)
	{
		if (n > QUARTERS)
			n = QUARTERS;

		memcpy(s.sales,ar,n*sizeof(double));

		while (n != QUARTERS)//若n为1，则索引1，2，3对应的元素值赋为0
			s.sales[n++] = 0;


	}
	//交互式地存入4个slaes的值，并存入结构体中的sales数组中，
	//计算并存储其它三个成员的值。
	void setSales(Sales& s);
	//显示结构中存储的所有信息
	void showSales(const Sales& s);
};

#endif