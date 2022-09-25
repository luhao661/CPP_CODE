#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>


//12.10 编程练习
//1.
//链接12.10.1.cpp
#if 0
#include "12.10.1.h"

int main()
{
	using namespace std;

	Cow cow1;
	cow1.ShowCow();

	Cow cow2("abc","programming",70);//调用构造函数
	cow2.ShowCow();

	Cow cow3("def","relaxing",60);
	cow3.ShowCow();

	cow1 = cow2 = cow3;//调用赋值运算符重载函数
	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();

	Cow cow4 = cow3;//调用复制构造函数
	cow4.ShowCow();

	return 0;
}
#endif


//2.
//链接12.10.2.cpp
#if 0
using namespace std;
#include "12.10.2.h"

int main()
{
	String s2 = "Please enter your name: ";
	String s3;

	cout << s2; // overloaded << operator
	cin >> s3; // overloaded >> operator

	s2 = "My name is " + s3; // overloaded =,+ operators
	cout << s2 << ".\n";
	
	String s1(" and I am a C++ student.");
	s2 = s2 + s1;
	s2.stringup(); // converts string to uppercase

	cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
	<< " 'A' characters in it.\n";

	s1 = " red";  // String (const char *),
	String rgb[3] = { String(s1),String("green"),String("blue") };

	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow(); // converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again !\n";
	}
	cout << "Bye\n";
	return 0;
}
#endif


//3.
//链接12.10.3.cpp
#if 1
#include "12.10.3.h"

const int STKS = 4;
int main()
{
	{
		// create an array of initialized objects
		Stock stocks[STKS] =
		{
			Stock("NanoSmart", 12, 20.0),
			Stock("Boffo Objects", 200, 2.0),
			Stock("Monolithic Obelisks", 130, 3.25),
		};

		std::cout << "Stock holdings:\n";
		int i;
		for (i = 0; i < STKS; i++)
			std::cout<<stocks[i];

		// set pointer to first element 声明并初始化一个指向Stock类对象的指针top
		const Stock* top = &stocks[0];
		for (i = 1; i < STKS; i++)
			top = &(top->topval(stocks[i]));//指针也可以用->来访问对象的方法成员

		// now top points to the most valuable holding
		std::cout << "\nMost valuable holding:\n";
		std::cout<<*top;
	}

	// std::cin.get();
	return 0;
}
#endif