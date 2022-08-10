#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>//STL vector类
#include <array>//STL array类
#include <string>//string类
//
#if 1
#endif


//4.13编程练习
//1.
#if 0
int main(void)
{
	using namespace std;
	const int SIZE = 20;

	cout << "What is your first name ? ";
	char f_name[SIZE];
	cin.getline(f_name,SIZE);

	cout << "What is your last name ? ";
	char l_name[SIZE];
	cin.getline(l_name, SIZE);

	cout << "What letter grade do you deserve ? ";
	char grade;
	cin >> grade;

	cout << "What is your age ? ";
	int age;
	cin >> age;

	cout << "Name :" << l_name << ", " << f_name << endl;
	cout << "Grade :" << char(grade + 1) << endl;//***注***grade+1，使结果数字的类型升级成int，要用强制类型转换，变成char
	cout << "Age :" << age << endl;

	return 0;
}
#endif