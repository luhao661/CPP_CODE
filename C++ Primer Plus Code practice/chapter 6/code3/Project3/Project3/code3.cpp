#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//6.11编程练习
//1.
#if 0
#include <cctype>

int main(void)
{
	using namespace std;

	char ch;
	while (cin.get(ch) && ch != '@')
	{
		if (islower(ch))
			cout.put(toupper(ch));//***注***若写为cout<<toupper(ch);则打印的是字符对应的ASCII值
		else if (isupper(ch))
			cout.put(tolower(ch));
		else
			cout << ch;
	}
	cout << "再见！";

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;
	cout << "请输入最多10个值"<<endl;

	double donation[10];
	int index = 0;
	double sum = 0.0;

	while (index<10 && cin >> donation[index])
	{
		++index;
		sum += donation[index - 1];
	}
	//index退出循环后，代表元素个数

	double average = sum / index;
	int count = 0;
	for (int i = 0; i < index; i++)
	{
		if (donation[i] > average)
			count++;
	}

	cout << "输入了"<<index<<"个数字"<<endl;
	cout << "平均值："<<average<<endl;
	cout << "数组中有"<<count<<"个数字大于平均值"<<endl;

	return 0;
}
#endif


//3.
#if 0
#include <cstring>
void showmenu(void);
char get_choice(void);
using namespace std;

int main(void)
{
	showmenu();
	char choice = get_choice();

	switch (choice)
	{
	case 'c':
		cout << "ccccc\n";
		break;
	case 'p':
		cout << "ppppp\n";
		break;
	case 't':
		cout << "A maple is a tree.\n";
		break;
	case 'g':
		cout << "ggggg\n";
		break;
	defalut:
		cout << "Error !\n";
	}

	return 0;
}
void showmenu(void)
{
	cout << "Please enter one of the following choices :"<<endl;
	cout << "c) carnivore p) pianist"<<endl;
	cout << "t) tree g)game"<<endl;
}
char get_choice(void)
{
	char ch;

	while (cin.get(ch))
	{
		while (cin.get() != '\n')
			continue;
		ch = tolower(ch);

		if (strchr("cptg", ch) == NULL)
			cout << "请输入c、p、t或g : " ;
		else
			break;
	}

	return ch;
}
#endif


//4.
#if 1
#include <cstring>

const int strsize = 30;
void showmenu(void);
char get_choice(void);
void display_by_name(struct bop *p_BopStructure);
void display_by_title(struct bop* p_BopStructure);
void display_by_bopname(struct bop* p_BopStructure);
void display_by_preference(struct bop* p_BopStructure);

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

using namespace std;
int main(void)
{
	struct bop BopStructure[5] = { {'\0'}};

	showmenu();
	char choice;

	while ((choice = get_choice())&&choice!='q')
	{
		switch (choice)
		{
		case 'a':
			display_by_name(BopStructure);
			break;
		case 'b':
			display_by_title(BopStructure);
			break;
		case 'c':
			display_by_bopname(BopStructure);
			break;
		case 'd':
			display_by_preference(BopStructure);
			break;
		default:
			cout << "Error !";
			return 1;
		}
		cout << "Next choice : ";
	}

	cout << "Bye !";
	return 0;
}
void showmenu(void)
{
	cout << "Benevolent Order of Programmers Report" << endl;
	cout << "a. display by name         b. display by title" << endl;
	cout << "c. display by bopname  d. display by preference" << endl;
	cout << "q. quit"<<endl;
	cout << "Enter your choice : ";
}
char get_choice(void)
{
	char ch;

	while (cin.get(ch))
	{
		while (cin.get() != '\n')
			continue;
		ch = tolower(ch);

		if (strchr("abcdq", ch) == NULL)
			cout << "请输入a、b、c、d或q : ";
		else
			break;
	}

	return ch;
}
void display_by_name(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		cout << (p_BopStructure+i)->fullname<<endl;
}
void display_by_title(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		cout << (p_BopStructure + i)->title<< endl;
}
void display_by_bopname(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		cout << (p_BopStructure + i)->bopname << endl;
}
void display_by_preference(struct bop* p_BopStructure)
{
	for (int i = 0; i < 5; i++)
		switch ((p_BopStructure + i)->preference)
		{
		case 0:
			cout << (p_BopStructure + i)->fullname << endl;
			break;
		case 1:
			cout << (p_BopStructure + i)->title << endl;
			break;
		case 2:
			cout << (p_BopStructure + i)->bopname << endl;
			break;
		}
}
#endif
