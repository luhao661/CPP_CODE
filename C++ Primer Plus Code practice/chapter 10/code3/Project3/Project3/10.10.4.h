#define _CRT_SECURE_NO_WARNINGS 1

#ifndef N_S
#define N_S

namespace SALES
{
	class Sales
	{
		enum {QUARTERS=4};
		double sales[QUARTERS];
		double m_average;
		double m_max;
		double m_min;
	public:
		//从ar[]中拷贝n个数据到结构体中的sales数组中，
		//计算并存储其它三个成员的值,
		//sales数组若有空闲的空间，则空闲空间的元素赋值为0
		Sales(const double ar[], int n);
		//交互式地存入4个slaes的值，并存入结构体中的sales数组中，
		//计算并存储其它三个成员的值。
		Sales();
		//显示对象的私有数据部分中存储的所有信息
		void ShowSales()const;
	};
}

#endif  /*N_S*/