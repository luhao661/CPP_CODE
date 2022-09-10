#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include<iostream>
#include "10.10.3.h"

//非交互版本(构造函数)
Golf::Golf(const char *p_data,const int hc)
{
	strcpy(golf_structure.fullname,p_data);
	this->golf_structure.handicap = hc;
}

//默认构造函数
Golf::Golf()
{
	using std::cout;
	using std::cin;

	int biaoji = 1;

	cout << "请输入姓名(输入Enter以结束输入)：";
	char temp[Len];
	cin.getline(temp, Len);

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

	//Golf(temp, handicap);//错误：构造函数被用来创建对象，而不能通过对象和方法来调用
	strcpy(this->golf_structure.fullname,temp);
	this->golf_structure.handicap = handicap;

	return;
}

//析构函数
Golf::~Golf()
{}

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

#endif