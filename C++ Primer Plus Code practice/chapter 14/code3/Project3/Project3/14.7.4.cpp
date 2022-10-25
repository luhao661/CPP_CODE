#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
#include "14.7.4.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using std::cout;
using std::endl;

Person::Person(const string& s1, const string& s2):fname(s1),lname()
{}//书P393

Person::Person():fname("no data"),lname("no data")
{}

Person::~Person()
{}

void Person::Show(void) const
{
	cout << "姓名："<<lname<<" "<<fname<<endl;
}

Gunslinger::Gunslinger(double tim, int tra)
{
	time = tim;
	trace = tra;
}

Gunslinger::Gunslinger()
{
	time = Gunslinger::Draw();
	trace = 10;
}

double Gunslinger::Draw(void) 
{
	std::srand(std::time(0));
	return std::rand() % 52 + 1;
}

void Gunslinger::show(void)const
{
	Person::Show();
	cout << "拔枪时间："<<time<<endl;
	cout << "枪上的刻痕数："<<trace<<endl;
}

#endif