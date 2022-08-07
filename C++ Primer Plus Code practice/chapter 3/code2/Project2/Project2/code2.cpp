#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//3.6复习题
//5.
#if 0
int main(void)
{
	using namespace std;

	char grade1 = 65;
	char grade2 = 'A';

	cout << grade1 << endl;
	cout << grade2 << endl;			//说明上述两个语句通用

	return 0;
}
#endif


//6.
#if 0
int main(void)
{
	using namespace std;
	cout.put(88);//法一						或写为：cout.put((char)88);
	putchar('\n');
	cout << (char)88;//法二
	putchar('\n');
	char ch = 88;
	cout << ch;//法三

	return 0;
}
#endif


//7.
#if 0
#include <climits>
//有宏定义：
//#define LONG_MAX      2147483647L										即10位有效位，double类型的变量可以表示，且没有舍入误差
//#define LLONG_MAX     9223372036854775807i64				即19位有效位，存入double类型的变量会有舍入误差

int main(void)
{
	long int a = 123456789;
	//float b = a;//警告	C4244	“初始化” : 从“long”转换到“float”，可能丢失数据	

	//double b = a;//无警告
	double b = 123456789123456789LL;//警告	C4305	“初始化” : 从“__int64”到“double”截断

	return 0;
}
#endif


//9.
#if 0
int main(void)
{
	double x1 = 1.6;
	double x2 = 2.5;

	int a;
	a = (int)x1 + (int)x2;

	int b;
	b = x1 + x2;				//或：b=(int)(x1+x2);

	std::cout << a;
	putchar('\n');
	std::cout << b;
	
	return 0;
}
#endif