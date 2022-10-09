#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include  "13.11.2.h"
#include <iostream>
//基类的方法

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1)+1];
	strcpy(performers, s1);

	label = new char[strlen(s2)+1];
	strcpy(label, s2);
	
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);

	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);

	selections = d.selections;

	playtime = d.selections;
}

Cd::Cd()
{
	int len = strlen("no input")+1;
	performers = new char[len];
	label = new char[len];

	strcpy(performers, "no input");
	strcpy(label, "no input");
	selections = playtime = 0;
}

Cd::~Cd()
{
	delete[]performers;
	delete[]label;
}

void Cd::Report() const// reports all CD data
{
	using std::cout;
	using std::endl;

	cout << "Performers : " << performers << endl;
	cout << "Label : " << label << endl;
	cout << "Selections : " << selections << endl;
	cout << "Playtime : " << playtime << endl;
}

Cd& Cd::operator= (const Cd& d)
{
	if (this == &d)
		return *this;

	delete[]performers;
	delete[]label;

	performers = new char[strlen(d.performers)+1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label)+1];
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.selections;

	return *this;
}

//派生类的方法

Classic::Classic() :Cd()
{
	composition = new char[strlen("no input")+1];
	strcpy(composition, "no input");
}

Classic::Classic(const char* s1, const char* s2, const char* s3,
	int n, double x) : Cd(s1, s2, n, x)
{
	composition = new char[strlen(s3)+1];
	strcpy(composition, s3);
}

//***注***
//错误写法：
//Classic::~Classic()::~Cd()
//{}
//正确写法：
Classic::~Classic()
{
	delete[]composition;
}//执行顺序是先调用派生类的析构函数，再自动调用基类的析构函数(与构造函数的调用顺序正好相反)

void Classic::Report() const// reports all CD data
{
	Cd::Report();
	std::cout << "Composition : " << composition << std::endl;
}

Classic& Classic::operator=(const Classic& d)
{
	if (this == &d)
		return *this;

	Cd::operator=(d);
	delete[]composition;

	composition = new char[strlen(d.composition)+1];
	strcpy(composition,d.composition);
}

#endif