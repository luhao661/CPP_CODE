#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "9.6.1.h"
#include <cstring>
//非交互版本
void setgolf(golf& g, const char* name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}
//交互版本
int setgolf(golf& g)
{
	using std::cout;
	using std::cin;

	int biaoji = 1;

	cout << "请输入姓名(输入Enter以结束输入)：";
	char temp[Len];
	cin.getline(temp,Len);

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

	setgolf(g,temp, handicap);

	return biaoji;
}
//重新设置handicap成员的值
void handicap(golf& g, int hc)
{
	g.handicap = hc;
}
//显示golf结构变量中的成员的内容
void showgolf(const golf& g)
{
	using std::cout;
	using std::endl;

	cout << "姓名："<<g.fullname<<endl;
	cout << "残疾等级："<<g.handicap<<endl;
}
#endif