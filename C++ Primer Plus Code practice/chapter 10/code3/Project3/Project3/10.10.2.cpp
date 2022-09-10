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

	/*if (lname == "" && fname[0] == '\0')
		cout << "无姓名！\n";
	else*/
	cout << "名："<<fname<<'\t'<<"姓："<<lname<<endl;
}
void Person::FormalShow()const
{
	using std::cout;
	using std::endl;

	cout << "姓：" << lname<<'\t' << "名：" << fname << endl;
}

#endif