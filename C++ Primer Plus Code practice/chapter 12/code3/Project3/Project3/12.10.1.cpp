#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "12.10.1.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

Cow::Cow()
{
	strcpy(name,"no name");
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strncpy(name,nm,19);
	name[19] = '\0';
	hobby = new char[(strlen(ho) + 1)];
	strcpy(hobby,ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy(name, c.name);
	hobby = new char[(strlen(c.hobby) + 1)];
	strcpy(hobby, c.hobby);
	weight =c.weight;
}

Cow::~Cow()
{
	cout <<"已释放使用new分配的内存！" << endl;
	delete[]hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;

	strcpy(name,c.name);
	delete[]hobby;
	hobby = new char[(strlen(c.hobby) + 1)];
	strcpy(hobby, c.hobby);
	weight = c.weight;

	return *this;
}

void Cow::ShowCow()const
{
	cout << name << '\t' << hobby << "\t" << weight<<endl;
}
#endif