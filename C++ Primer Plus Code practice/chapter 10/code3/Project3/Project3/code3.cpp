#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//10.10 编程练习
//1.
//链接10.10.1.cpp
#if 0
#include "10.10.1.h"
int main()
{
	using namespace std;

	cout << "声明并初始化account1(隐式调用默认构造函数)\n";
	Account account1;
	account1.show();

	cout << "声明并初始化account2(隐式调用构造函数)\n";
	Account account2("Xiao Min","123456789876");
	account2.show();

	cout << "小明存入10块钱后\n";
	account2.deposit(10);
	account2.show();

	cout << "小明取出5块钱后\n";
	account2.draw(5);
	account2.show();

	cout << "Done !\n";

	return 0;
}
#endif


//2.
//链接10.10.2.cpp
#if 0
#include "10.10.2.h"

int main()
{
	using namespace std;

	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy","Sam");

	one.Show();
	cout << endl;
	one.FormalShow();
	cout << endl;

	two.Show();
	cout << endl;
	two.FormalShow();
	cout << endl;

	three.Show();
	cout << endl;
	three.FormalShow();
	cout << endl;

	return 0;
}
#endif


//3.
//链接10.10.3.cpp
#if 1
int main()
{


	return 0;
}
#endif