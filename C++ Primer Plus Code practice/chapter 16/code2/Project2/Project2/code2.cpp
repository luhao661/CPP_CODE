#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//16.9 复习题
//1.
//链接无
#if 0
#include "16.9.1.h"

int main()
{
	RQ1 st1;
	st1.show();

	RQ1 st2("abc");
	st2.show();

	RQ1 st3(st2);
	st3.show();

	RQ1 st4;
	st4 = st3;
	st4.show();

	return 0;
}
#endif


//3.
//链接无
#if 0
#include <string>
#include <cctype>
void alter(std::string&);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string st;

	cin >> st;
	alter(st);

	cout << st;

	return 0;
}
void alter(std::string& s)
{
	for (auto p = s.begin(); p != s.end(); p++)
	{
		if (islower(*p))
			*p = toupper(*p);
	}
}
#endif