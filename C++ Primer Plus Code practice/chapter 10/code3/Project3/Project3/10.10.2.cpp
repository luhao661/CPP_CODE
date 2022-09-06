#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.2.h"
#include <cstring>

Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strncpy(fname,fn,LIMIT-1);
	fname[LIMIT-1] = '\0';
}
void Person::Show()const
{
	using std::cout;
	using std::endl;

	cout << "Ãû£º"<<fname<<'\t'<<"ÐÕ£º"<<lname<<endl;
}
void Person::FormalShow()const
{
	using std::cout;
	using std::endl;

	cout << "ÐÕ£º" << lname<<'\t' << "Ãû£º" << fname << endl;
}

#endif