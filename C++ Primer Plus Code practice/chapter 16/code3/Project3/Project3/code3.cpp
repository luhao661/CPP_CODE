#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//16.10 编程练习
//1.
//链接无
#if 0
#include <string>
bool huiwen(std::string & st);

int main()
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	cout << "请输入字符串：";
	string st;
	cin >> st;
	bool bo = huiwen(st);

	if (bo)
		cout << "是回文\n";
	else
		cout << "不是回文\n";

	return 0;
}
bool huiwen(std::string& st)
{
	int length = st.size();//长度3，则索引0、1、2  索引只要0，长度5，索引只要0、1，长度7，索引只要0、1、2
	int local=0;				   //长度4，索引只要0、1，长度6，索引只要0、1、2，长度8，索引只要0、1、2、3

	//不需要分奇偶
	//if(length%2)//奇数个
		for (int i = 0; i < int(length/2); i++)
		{
			int j = length - i - 1;
			if (st[i] == st[j])
				continue;
			else
				return false;
		}
	//else//偶数个
	//	for (int i = 0; i < int(length / 2); i++)
	//	{
	//		int j = length - i - 1;

	//	}

	return true;
}
#endif


//2.
//链接无
#if 1
using std::string;
int main()
{
	using std::cin;
	using std::cout;

	string st="abcdefghijklmn";
	string::iterator si=st.begin();
	//st.erase(3,1);
	//或写成：
	st.erase(si+3, si+4);

	cout << st;

	return 0;
}
#endif