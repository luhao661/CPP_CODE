#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "14.7.1.h"

using std::cout;
using std::cin;
using std::endl;

//法一：
//Wine::Wine(const char* l, int y, const int yr[], const int bot[])
//	:name(l),year_and_bottles(yr,bot,y)//***注***如果函数声明是Pair(int* aval, int* bval,int y)，则这里要用强制类型转换
//{
//	number_of_years = y;
//}
//
//Wine::Wine(const char* l, int y):name(l),year_and_bottles(y,y)
//{
//	number_of_years = y;
//}

//法二：
#if 1
Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:name(l),year_and_bottles(ArrayInt(yr,y),ArrayInt(bot,y))//调用ArrayInt的复制构造函数
{
	number_of_years = y;
}

Wine::Wine(const char* l, int y):name(l), year_and_bottles(ArrayInt(y), ArrayInt(y))
{
	number_of_years = y;
}
#endif

void Wine::GetBottles(void)
{
	cout << "Enter "<<name<<" data for "<<number_of_years<<" year(s) : "<<endl;

	//***注***
	//valarray类还有方法resize()能重置数组的大小
	//可以这样使用：
	/*year_and_bottles.first().resize(number_of_years);
	year_and_bottles.second().resize(number_of_years);*/

	for (int i = 0; i < number_of_years; i++)
	{
		cout << "Enter year : ";
		cin >> (year_and_bottles.first())[i];
		cout << "Enter bottles for that year: ";
		cin >> (year_and_bottles.second())[i];
	}
}

void Wine::Show(void) const
{
	cout << "Wine : "<<name<<endl;
	cout << "Year\t"<<"Bottles\n";
	
	for (int i = 0; i < number_of_years; i++)
	{
		cout << year_and_bottles.first()[i] << "\t" << year_and_bottles.second()[i]<<endl;
	}
}

const std::string& Wine::Label(void)const
{
	return name;
}

int Wine::sum(void)const
{
	return year_and_bottles.second().sum();
}

#endif