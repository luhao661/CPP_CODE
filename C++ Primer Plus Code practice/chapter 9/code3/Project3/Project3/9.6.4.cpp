#define _CRT_SECURE_NO_WARNINGS 1

#if 0
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

		double sum = 0,max,min;
		max = min = s.sales[0];

		for (int i = 0; i < n; i++)
		{
			sum += s.sales[i];

			s.sales[i] > max ? max = s.sales[i] : max;

			if (s.sales[i] < min)
				min = s.sales[i];
		}
		
		s.average = sum / n;
		s.max = max;
		s.min = min;
	}
	//交互式地存入4个slaes的值，并存入结构体中的sales数组中，
	//计算并存储其它三个成员的值。
	void setSales(Sales& s)
	{
		using std::cout;
		using std::cin;

		cout << "请输入4个销售值：";

		for (int i = 0; i < QUARTERS; i++)
			while (!(cin >> s.sales[i]))
			{
				cout << "Bad input. Please enter a number:  ";
				cin.clear();
				while (cin.get() != '\n')
					continue;
			}

		//法二：
		/* int i=0;
		    double ar[QUARTERS]={};
			do
			{
				cout << "请输入一个数字：";
				if (!(cin >> ar[i]))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "Bad input. Please enter a number:  ";
					cin >> ar[i];
				}
			i++;
			}while(i<QUAQUARTERS);*/

		cin.get();
		double sum = 0, max, min;
		max = min = s.sales[0];

		for (int i = 0; i < QUARTERS; i++)
		{
			sum += s.sales[i];

			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}

		s.average = sum / QUARTERS;
		s.max = max;
		s.min = min;
	}
	//显示结构中存储的所有信息
	void showSales(const Sales& s)
	{
		using std::cout;
		using std::endl;

		cout << "sales: ";
		for (int i = 0; i < QUARTERS; i++)
			cout << s.sales[i] << "  ";

		cout.put('\n');
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
};

//法二：
/*
using namespace SALES;

void setSales(Sales& s, const double ar[], int n)
{

}
..........

*/

#endif