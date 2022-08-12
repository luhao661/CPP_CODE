#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <array>
//
#if 1
#endif


//5.9编程练习
//1.
#if 0
int main(void)
{
	using namespace std;
	cout << "请输入两个整数：";
	
	int start, end;
	cin >> start;
	cin >> end;

	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;

	cout << start << "~" << end << "之间所有整数的和为" << sum;

	return 0;
}
#endif


//2.
#if 0
const int ArSize = 100;      // example of external declaration

int main()
{
	std::array<long double, ArSize>factorials;

	factorials[1] = factorials[0] = 1.0L;//0!=1，1!=1

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;
	// std::cin.get();
	return 0;
}
#endif


//3.
#if 0
int main(void)
{
	using namespace std;

	cout << "请输入数字：";
	int num,sum=0;
	
	while (1)
	{
		cin >> num;
		sum += num;
		
		if (num != 0)
		{
			cout << "所有输入的累计和为" << sum << endl;
			cout << "请输入数字：";
		}
		else
			break;
	}

	return 0;
}
#endif


//4.
#if 1
int main(void)
{
	using namespace std;

	double benjin_dap = 100.0, benjin_cle = 100.0;
	const double lilv_dap = 0.1;
	const double lilv_cle = 0.05;

	double lixi_dap, lixi_cle;

	double money_dap = benjin_dap ;
	double money_cle= benjin_cle;
	int years=0;

	do
	{
		lixi_dap = lilv_dap * benjin_dap;
		money_dap += lixi_dap;

		lixi_cle = lilv_cle * money_cle;
		money_cle += lixi_cle;

		years++;
	} while (money_cle<= money_dap);



	return 0;
}
#endif