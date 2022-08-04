#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//使用以下划线开头的变量名的变量会发生什么
#if 0
int main(void)
{
	using namespace std;
	int _ceshi=1;

	cout << _ceshi<<endl;

	return 0;
}
#endif


//查看类型的长度
#if 1
#endif