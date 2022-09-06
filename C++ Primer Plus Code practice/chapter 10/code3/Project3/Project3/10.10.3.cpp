#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include "10.10.3.h"

Golf::Golf(const char *p_data,const int hc)
{
	strcpy(golf_structure.fullname,p_data);
	golf_structure.handicap = hc;
}
Golf::Golf()
{
	//golf_structure = (struct golf){"no name",0};  C++不支持此复合字面量
	struct golf temp = { "no name",0 };
	golf_structure = temp;
}
//交互版本
int Golf::setgolf()
{
	using std::cout;
	using std::cin;

	int biaoji = 1;

	cout << "请输入姓名(输入Enter以结束输入)：";
	char temp[Len];
	cin.getline(temp, Len);

	if (!strlen(temp))
	{
		biaoji = 0;
		return biaoji;
	}

	cout << "请输入等级：";
	int handicap;
	while (!(cin >> handicap))
	{
		cout << "Bad input. Please enter a number:  ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cin.get();

	Golf(temp, handicap);

	return biaoji;
}
void Golf::handicap(const int hc)
{
	golf_structure.handicap = hc;
}
void Golf::showgolf() const
{
	using std::cout;
	using std::endl;

	cout << "姓名：" << golf_structure.fullname << endl;
	cout << "残疾等级：" << golf_structure.handicap << endl;
}
