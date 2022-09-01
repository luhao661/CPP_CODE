#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//9.6编程练习
//1.
#if 0
#include "9.6.1.h"
#include <new>
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "请输入要填充的结构数量：";
	int count;
	while (!(cin >> count))
	{
		cout << "Bad input. Please enter a number:  ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cin.get();
	//struct golf golf_structure[count];//错误：count不能是变量
	//解决法1：
	/*const int c_count = count;
	struct golf golf_structure[c_count];*/  //此方法不行，c_count还是视为变量

	//正确方法：
	struct golf* p_golfstructure =new golf[count];

	int biaoji = 1;
	int i;
	for(i=0;i<count;i++)
	{
		cout << "请输入第"<<i+1<<"个结构的内容"<<endl;
		biaoji=setgolf(*(p_golfstructure+i));

		if (!biaoji)
			break; 
	}
	//***重置count的值，用以代表结构数量的值***
	count = i;

	cout << "要修改结构数组中的handicap成员的值吗？(输入y或n)";
	char answer;
	while (cin.get(answer))
	{
		while (cin.get() != '\n')
			continue;
		answer = tolower(answer);

		if (strchr("yn", answer) == NULL)
			cout << "请输入y或n : ";
		else
			break;
	}

	if (answer == 'y')
	{
		cout << "请输入要修改的数组的索引值：";
		int num;
		while (!(cin >> num))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cout << "请输入要修改的数组的handicap的值：";
		int handicap_num;
		while (!(cin >> handicap_num))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cin.get();

		handicap(*(p_golfstructure+num), handicap_num);
		cout << "第"<< num+1 <<"个结构修改完成！"<<endl;
	}

	cout << "\n数据如下："<<endl;
	for (int i = 0; i < count; i++)
	{
		showgolf(*(p_golfstructure + i));
	}

	return 0;
}
#endif


//2.
#if 0
#include <string>
// constants
const int ArSize = 10;

// function prototype
void strcount(const std::string str);

int main()
{
	using namespace std;

	string input;
	char next;

	cout << "Enter a line:\n";
	getline(cin,input);

	while (input!="")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";//***注***当get()读取空行后将设置失效位
		getline(cin, input);
	}
	cout << "Bye\n";

	return 0;
}

void strcount(const std::string str)
{
	using namespace std;

	static int total = 0;        // static local variable 只会在第一次调用函数时进行初始化

	cout << "\"" << str << "\" contains ";

	int count = 0;               // automatic local variable
	while (str[count])               // go to end of string
		count++;

	total += count;

	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#endif


//3.
#if 0
#include <new>
#define SIZE 50
struct chaff
{
	char dross[20];
	int slag;
};

char buffer[SIZE];

int main()
{
	using std::cout;

	struct chaff* p = new (buffer)struct chaff[2];

	const char* data = "abcdefg";
	strcpy(p->dross, data);
	p->slag = 1;
	strcpy((p+1)->dross, data);
	(p + 1)->slag = 2;

	for (int i = 0; i < 2; i++)
	{
		cout << (p + i)->dross << "\t";
		cout << (p + i)->slag <<std::endl;
	}

	return 0;
}
#endif


//4.
#if 1

#endif
