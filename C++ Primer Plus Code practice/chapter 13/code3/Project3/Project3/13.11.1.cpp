#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include  "13.11.1.h"
#include <iostream>
//基类的方法

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strncpy(performers,s1,49);
	performers[49] = '\0';

	strncpy(label,s2,19);
	label[19] = '\0';

	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);

	strcpy(label, d.label);
	
	selections = d.selections;

	playtime = d.selections;
}

Cd::Cd()
{
	strcpy(performers,"no input");
	strcpy(label,"no input");
	selections = playtime = 0;
}

Cd::~Cd()
{}

void Cd::Report() const// reports all CD data
{
	using std::cout;
	using std::endl;

	cout << "Performers : "<<performers<<endl;
	cout << "Label : "<<label<<endl;
	cout << "Selections : "<<selections<<endl;
	cout << "Playtime : " << playtime<<endl;
}

Cd& Cd::operator= (const Cd& d)
{
	if (this == &d)
		return *this;

	strcpy(performers, d.performers);
	strcpy(label, d.label);

	selections = d.selections;
	playtime = d.selections;

	return *this;
}

//派生类的方法

Classic::Classic():Cd()
{
	strcpy(composition,"no input");
}

Classic::Classic(const char* s1, const char* s2, const char* s3,
	int n, double x):Cd(s1,s2,n,x)
{
	strncpy(composition,s3,19);
	composition[19] = '\0';
}

//***注***
//错误写法：
//Classic::~Classic()::~Cd()
//{}
//正确写法：
Classic::~Classic()
{}//执行顺序是先调用派生类的析构函数，再调用基类的析构函数(与构造函数的调用顺序正好相反)

void Classic::Report() const// reports all CD data
{
	Cd::Report();
	std::cout << "Composition : "<<composition<<std::endl;
}

#endif
