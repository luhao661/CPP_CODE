#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//6.10∏¥œ∞Ã‚
//3.
#if 0
using namespace std;
int main()
{
	char ch;
	int ct1, ct2;

	ct1 = ct2 = 0;
	while ((ch = cin.get()) != '$')
	{
		cout << ch;
		ct1++;
		if (ch = '$')
			ct2++;
		cout << ch;
	}
	cout << "ct1= "<<ct1<<", ct2="<<ct2<<endl;

	return 0;
}
/* ‰»Î£∫
Hi!
Send $10 or $20 now!
*/
#endif


//4.
#if 0
weight>=115&&weight<125
ch=='q'||ch=='Q'
x%2==0&&x!=26
x%2==0&&x%26!=0
(donation>=1000&&donation<=2000)||guest==1
(ch>='a'&&ch<='z')||(ch >= 'A' && ch <= 'Z')
#endif


//6.
#if 0
x>0?x:-x
#endif


//7.
#if 0
switch (ch)
{
case 'A':
	a_grade++;
	break;
case 'B':
	b_grade++;
	break;
case 'C':
	c_grade++;
	break;
case 'D':
	d_grade++;
	break;
default:
	f_grade++;
}
#endif


//9.
#if 0
int main (void)
{
	using namespace std;

	int line = 0;
	char ch;
	while (cin.get(ch)&&ch!='Q')
	{
		if (ch == '\n')
			line++;

		//cout << ch;
	}
}
#endif
