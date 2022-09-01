#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//9.5∏¥œ∞Ã‚
//3.
#if 0
int main()
{
	double x;
	std::cout << "Enter value:  ";
	while (!(std::cin >> x))
	{
		std::cout << "Bad input. Please enter a number:  ";
		std::cin.clear();
		while (std::cin.get() != '\n')
			continue;
	}
	std::cout << "Value = " << x << std::endl;

	return 0;
}
#endif


//4.
#if 0
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x;
	cout << "Enter value:  ";
	while (!(cin >> x))
	{
		cout << "Bad input. Please enter a number:  ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cout << "Value = " << x << endl;

	return 0;
}
#endif