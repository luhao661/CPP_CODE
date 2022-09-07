#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.4.h"
#include "cstring"
#include <iostream>

using namespace SALES;

Sales::Sales(const double ar[], int n)
{
	if (n > QUARTERS)
		n = QUARTERS;

	memcpy(this->sales, ar, n * sizeof(double));

	while (n != QUARTERS)//若n为1，则索引1，2，3对应的元素值赋为0
		sales[n++] = 0;

	double sum = 0, max, min;
	max = min = sales[0];

	for (int i = 0; i < n; i++)
	{
		sum += sales[i];

		sales[i] > max ? max = sales[i] : max;

		if (sales[i] < min)
			min = sales[i];
	}

	m_average = sum / n;
	m_max = max;
	m_min = min;
}

Sales::Sales()
{
	using std::cout;
	using std::cin;

	cout << "请输入4个销售值：";

	for (int i = 0; i < QUARTERS; i++)
		while (!(cin >> sales[i]))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}

	cin.get();
	double sum = 0, max, min;
	max = min = sales[0];

	for (int i = 0; i < QUARTERS; i++)
	{
		sum += sales[i];

		if (sales[i] > max)
			max = sales[i];
		if (sales[i] < min)
			min = sales[i];
	}

	m_average = sum / QUARTERS;
	m_max = max;
	m_min = min;
}

void Sales::ShowSales()const
{
	using std::cout;
	using std::endl;

	cout << "sales: ";
	for (int i = 0; i < QUARTERS; i++)
		cout << sales[i] << "  ";

	cout.put('\n');
	cout << "average: " << m_average << endl;
	cout << "max: " << m_max << endl;
	cout << "min: " << m_min << endl;
}
#endif