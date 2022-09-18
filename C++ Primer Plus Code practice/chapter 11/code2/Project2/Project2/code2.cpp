#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//11.8 复习题
//1.
//链接11.8.1.cpp
#if 0
#include "11.8.1.h"
int main()
{
	using std::cout;
	using std::endl;

	Stonewt w1(10,8);

	Stonewt w2 = 2*w1 ;

	cout << double(w2) <<"磅，相当于";//使用显式强制类型转换

	w2.show_stn();

	return 0;
}
#endif


//7.
//链接11.8.7.cpp
#if 0
#include "11.8.7.h"
int main()
{
	using namespace VECTOR;
	using namespace std;

	Vector v1(1,1);

	double length = double(v1);

	cout << length << endl;

	return 0;
}
#endif