#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//2.7编程练习
//1.
#if 0
int main(void)
{
	using std::cout;
	cout << "测试";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "请输入一个以long为单位的距离：";
	int distance;
	cin >> distance;
	cout << "哈哈，这相当于" << distance * 220 << "码";

	return 0;
}
#endif


//3.
#if 0
using namespace std;
void function1(void);
void function2(void);

int main(void)
{
	function1();
	function1();
	function2();
	function2();

	return 0;
}
void function1(void)
{
	cout << "Three blind mice"<<endl;
}
void function2(void)
{
	cout << "See how they run\n";
}
#endif


//4.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter your age: ";
	int age;
	cin >> age;
	cout << "该年龄包含："<<age*12<<"个月";

	return 0;
}
#endif



//5.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "请输入摄氏温度值：";
	double temperature;
	cin >> temperature;
	cout << temperature <<"度相当于" << function(temperature) << "华氏度";

	return 0;
}
double function(double num)
{
	return num * 1.8 + 32.0;
}
#endif


//6.
#if 0
double function(double);

int main(void)
{
	using namespace std;
	cout << "请输入光年值：";
	double light_years;
	cin >> light_years;
	cout << light_years << "光年=" << function(light_years) << "天文单位";

	return 0;
}
double function(double num)
{
	return num * 63240;
}
#endif


//7.
#if 0
using namespace std;
void function(int a,int b);

int main(void)
{
	int a, b;
	cout << "Enter the number of hours: ";
	cin >> a;
	cout << "Enter the number of minutes: ";
	cin >> b;
	function(a,b);

	return 0;
}
void function(int a, int b)
{
	cout <<"Time : " << a << ":" << b;				//***注***无返回值的函数可以不使用return语句，这样函数会运行到最后一句，然后自动返回
	//return;
}
#endif
