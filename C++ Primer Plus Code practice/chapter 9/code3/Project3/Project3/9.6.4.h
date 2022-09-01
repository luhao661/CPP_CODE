#define _CRT_SECURE_NO_WARNINGS 1

#ifndef A_9_6_4_H
#define A_9_6_4_H

namespace SALES
{
	const int QUARTERS = 4;

	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	//从ar[]中拷贝n个数据到结构体中的sales数组中，
	//计算并存储其它三个成员的值,
	//sales数组若有空闲的空间，则空闲空间的元素赋值为0
	void setSales(Sales& s, const double ar[],int n);
	//交互式地存入4个slaes的值，并存入结构体中的sales数组中，
	//计算并存储其它三个成员的值。
	void setSales(Sales &s);
	//显示结构中存储的所有信息
	void showSales(const Sales &s);
};

#endif   /*A_9_6_4_H*/
