#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>//STL vector类
#include <array>//STL array类
#include <string>//string类
#include <cstring>//strcat()
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
	cout << "Age :" << age << endl;						//cout才能打印字符

	return 0;
}
#endif


//2.
#if 0
int main()
{
	using namespace std;

	const int ArSize = 20;
	string name;
	string dessert;

	cout << "Enter your name:\n";
	getline(cin, name);    
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
	// cin.get();
	return 0;
}
#endif


//3.
#if 0
int main(void)
{
	using namespace std;

	cout << "Enter your first name : ";
	char f_name[20];
	cin.getline(f_name,20);
	cout << "Enter your last name : ";
	char l_name[60];
	cin.getline(l_name, 20);

	char temp[3] = ", ";
	strcat(l_name,temp);
	strcat(l_name,f_name);

	cout << "Here's the information in a single string : ";
	cout << l_name;

	return 0;
}
#endif


//4.
#if 0
int main(void)
{
	using namespace std;

	cout << "Enter your first name : ";
	string f_name;
	getline(cin,f_name);
	cout << "Enter your last name : ";
	string l_name;
	getline(cin, l_name);

	string temp = ", ";
	l_name += temp;
	l_name += f_name;

	cout << "Here's the information in a single string : ";
	cout << l_name;

	return 0;
}
#endif


//5.
#if 0
struct CandyBar
{
	char brand[20];
	double weight;
	int calorie;
};

int main(void)
{
	using namespace std;
	CandyBar snack{"Mocha Munch",2.3,350};

	cout << snack.brand << endl;
	cout << snack.weight << endl;
	cout << snack.calorie<< endl;

	return 0;
}
#endif


//6.
#if 0
struct CandyBar
{
	char brand[20];
	double weight;
	int calorie;
};

int main(void)
{
	using namespace std;
	CandyBar snack[3]{
	{"Mocha Munch", 2.3, 350} ,
	 {"Aaa Bbb", 2.3, 350} ,
	 {"Ccc Ddd", 2.3, 350} };

	for (int i = 0; i < 3 ; i++)
	{
		cout << snack[i].brand << endl;
		cout << snack[i].weight << endl;
		cout << (snack+i)->calorie << endl;
	}

	return 0;
}
#endif


//7.
#if 0
const int SIZE = 20;

struct pizza
{
	char company[SIZE];
	double diameter;
	double weight;
};

int main(void)
{
	using namespace std;

	struct pizza xinxi;

	cout << "请输入披萨饼公司的名称：";
	cin.getline(xinxi.company,SIZE);
	cout << "请输入披萨饼的直径：";
	cin >> xinxi.diameter;
	cout << "请输入披萨饼的重量：";
	cin >> xinxi.weight;

	cout << xinxi.company << endl;
	cout << xinxi.diameter << endl;
	cout << xinxi.weight << endl;

	return 0;
}
#endif


//8.
#if 0
const int SIZE = 20;

struct pizza
{
	char company[SIZE];
	double diameter;
	double weight;
};

int main(void)
{
	using namespace std;

	struct pizza*p=new pizza;

	cout << "请输入披萨饼的直径：";
	cin >> p->diameter;
	cin.get();

	cout << "请输入披萨饼公司的名称：";
	cin.getline(p->company, SIZE);

	cout << "请输入披萨饼的重量：";
	cin >> p->weight;

	cout <<p->company << endl;
	cout <<p->diameter << endl;
	cout <<p->weight << endl;

	delete p;

	return 0;
}
#endif


//9.
#if 0
struct CandyBar
{
	char brand[20];
	double weight;
	int calorie;
};

int main(void)
{
	using namespace std;

	CandyBar* p = new CandyBar[3];
	*p = { "Mocha Munch", 2.3, 350 };
	*(p+1)= { "Aaa Bbb", 2.3, 350 };
	 *(p+2) ={ "Ccc Ddd", 2.3, 350 };

	for (int i = 0; i < 3; i++)
	{
		cout << p[i].brand << endl;
		cout << p[i].weight << endl;
		cout << (p + i)->calorie << endl;
		//或
		//cout << (* (p + i)).calorie << endl;
	}
	delete[]p;

	return 0;
}
#endif


//10.
#if 0
int main(void)
{                                                                      
	using namespace std;
	const int cishu = 3;

	array<double,cishu>chengji;

	cout << "请输入3次40米跑的成绩：";
	cin >> chengji[0];
	cin >> chengji[1];
	cin >> chengji[2];//每输入一个成绩就换行，或每输入一个成绩就用空格分开，均能正常运行

	cout << cishu << "次跑步的平均成绩是：" << (chengji[0] + chengji[1] + chengji[2]) / 3;

	return 0;
}
#endif