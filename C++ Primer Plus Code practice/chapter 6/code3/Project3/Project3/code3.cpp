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
		if (isdigit(ch))
			continue;

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

	while (index<10 && cin >> donation[index])//输入非数字时cin返回false
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

	/*老方法：
	while(ch!='c'&&ch!='p'&&ch!='t'&&ch!='g')
	{
			cin.get();
			cout << "请输入c、p、t或g : " ;
			cin.get(ch);
	}
	*/

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
#if 0
#include <cstring>
#include <cctype>

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
//***注***C99和C11为结构提供了指定初始化器（designated initializer）1，其语法与数组的指定初始化器类似。
//但是，结构的指定初始化器使用点运算符和成员名（而不是方括号和下标）标识特定的元素。
//但是，C++不支持。
	struct bop BopStructure[5] = {
		{"Wimp Macho","Programmer","MIPS",0},
		{"Raki Rhodes", "Junior Programmer","\0",1},
		{"Celia Laiter","\0","MIPS",2},
		{"Hoppy Hipman","Analyst Trainee","\0",1 },
		{"Pat Hand","\0","LOOPY",2}
	
	};

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
	{
		//更完善的写法：
		/*if (strlen((p_BopStructure + i)->fullname) == 0)
			continue;
		else*/
			cout << (p_BopStructure + i)->fullname << endl;
	}
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
//法二：
//在main函数外声明结构数组，并对其初始化
//这样的话，各被调函数的形参都可以是void
#endif


//5.
#if 0
int main(void)
{
	using namespace std;

	cout << "请输入您的收入：";
	long income;
	double tax=0;

	while (cin >> income && income >= 0)
	{
		if (income <= 5000)
			tax = 0;
		else if (income > 5000 && income <= 15000)
			tax = 0 + (income - 5000) * 0.1;
		else if (income > 15000 && income <= 35000)
			tax = (15000 - 5000) * 0.1 + (income - 15000) * 0.15;
		else
			tax = (15000 - 5000) * 0.1 + (35000 - 15000) * 0.15 + (income - 35000) * 0.2;
	
		cout << "您应缴纳税款："<<tax<<endl;
	}

	return 0;
}
#endif


//6.
#if 0
#include <string>//getline()

typedef struct
{
	std::string name;
	double donation;
}PeopleTypedef;

int main(void)
{
	using namespace std;
	cout << "请输入捐献者人数：";
	long num=0;
	while (!(cin >> num))//输入非规定的数据时cin返回false
	{
		cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

		while (cin.get() != '\n')
			continue;    //消耗掉错误的输入

		cout << "Please enter a number: ";//提示用户再输入
	}
	cin.get();

	PeopleTypedef* p_PeopleTypedef = new PeopleTypedef [num];

	for (int i = 0; i < num; i++)
	{
		cout << "请输入姓名：";
		getline(cin, (p_PeopleTypedef + i)->name);

		cout << "请输入捐款额：";
		while (!(cin >> (p_PeopleTypedef + i) ->donation ))//输入非规定的数据时cin返回false
		{
			cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

			while (cin.get() != '\n')
				continue;    //消耗掉错误的输入

			cout << "Please enter a number: ";//提示用户再输入
		}

		cin.get();
	}

	int biaoji1, biaoji2;
	biaoji1 = biaoji2 = 0;

	cout << "\nGrand Patrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation > 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji1 = 1;
		}	
	}
	if (!biaoji1)
		cout << "none\n";

	cout << "\nPatrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation <= 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji2 = 1;
		}
	}
	if (!biaoji2)
		cout << "none\n";

	return 0;
}
#endif


//7.
#if 0
#include <cstring>//strcmp()
#include<cctype>//isupper()

void string_tolower(char *p);
void delete_punctuation(char *p);

int main(void)
{
	using namespace std;
	cout << "Enter words (q to quit) : "<<endl;
	char words[30];
	int length = 0;
	int index,jishu=0;
	int vowels=0, consonants=0,others=0;

	while (cin >> words && strcmp(words, "q"))//每次读入两端或一端为空白的字符
	{
		//将两端或一端为空白的字符，若是大写字母，则转化为小写
		string_tolower(words);
		//将两端或一端为空白的字符,其中的标点符号用'\0'替换
		delete_punctuation(words);

		//判断两端或一端为空白的字符是否是单词
		length=strlen(words);
		for (index = 0; index < length; index++)
		{
			if (isalpha(words[index]))
				++jishu;
		}

		//若是单词
		if (jishu == length)
		{
			switch (words[0])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowels++;
				break;
			/*default:
				consonants++;*/			//下面if语句的替代写法
			}

			if (strchr("bcdfghjklmnpqrstvwxyz", words[0]))
				consonants++;
		}
		else//若不是单词
			others++;

		jishu = 0;
	}

	cout << "\n"<<vowels<<" words beginning with vowels"<<endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;

	return 0;
}
void string_tolower(char* p)
{
	int length = strlen(p);
	for (int index = 0; index < length; index++)
	{
		if (isupper(*(p+index)))
			*(p + index)=tolower(*(p + index));
	}

	return;
}
void delete_punctuation(char* p)
{
	int length = strlen(p);
	for (int index = 0; index < length; index++)
	{
		if (ispunct(*(p + index)))
			*(p + index) = '\0';
	}

	return;
}
/*测试数据：
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
*/
#endif


//8.
#if 0
#include <fstream>                  // file I/O support
													//1.包含头文件fstream(其中定义了ifstream类)
#include <cstdlib>                   //exit()

const int SIZE = 60;

int main(void)
{
	using namespace std;

	ifstream inFile;                       // object for handling file input
													//2.声明一个ifstream对象                                                   

// ifstream默认以输入方式打开文件，用于读文件
//	ofstream默认以输出方式打开文件，用于写文件

	cout << "Enter name of data file: ";
	char filename[SIZE];
	cin.getline(filename, SIZE);

	inFile.open(filename);           // associate inFile with a file
													//3.将该对象与一个文件关联起来

	//检查文件是否被成功打开
	if (!inFile.is_open())//failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		// cin.get();    //keep window open
		exit(EXIT_FAILURE);
	}

	char ch;
	int count = 0;                       

	inFile >> ch;                     // get first value
												   //4.像使用cin那样使用该ifstream对象

	while (inFile.good())   // while input good and not at EOF
	{
		++count;                
		inFile >> ch;  
	}

	//确定循环终止的原因
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else//inFile.bad()为true
		cout << "Input terminated for unknown reason.\n";

	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "该文件包含 " << count <<"个字符"<< endl;
	}

	//5.使用完文件后，用close()将其关闭
	inFile.close();         // finished with the file

	return 0;
}
//6.11.8.txt
#endif


//9.
#if 0
#include <string>//getline()
#include <fstream>
#include <cstdlib> 

typedef struct
{
	std::string name;
	double donation;
}PeopleTypedef;

int main(void)
{
	using namespace std;

	ifstream inFile;

	inFile.open("6.11.9.txt");

	//cout << "请输入捐献者人数：";

	//检查文件是否被成功打开
	if (!inFile.is_open())//failed to open file
	{
		cout << "Could not open the file " << "6.11.9.txt" << endl;
		cout << "Program terminating.\n";
		// cin.get();    //keep window open
		exit(EXIT_FAILURE);
	}

	long num = 0;
	while (!(inFile >> num))//输入非规定的数据时cin返回false
	{
		cin.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

		while (cin.get() != '\n')
			continue;    //消耗掉错误的输入

		cout << "Please enter a number: ";//提示用户再输入
	}
	inFile.get();

	PeopleTypedef* p_PeopleTypedef = new PeopleTypedef[num];

	for (int i = 0; i < num; i++)
	{
		//cout << "请输入姓名：";
		getline(inFile, (p_PeopleTypedef + i)->name);

		//cout << "请输入捐款额：";
		while (!(inFile >> (p_PeopleTypedef + i)->donation))//输入非规定的数据时inFile返回false
		{
			inFile.clear();     //用clear()方法重置错误输入标记，程序才能继续读取输入

			while (inFile.get() != '\n')
				continue;    //消耗掉错误的输入

			cout << "Please enter a number: ";//提示用户再输入
		}

		inFile.get();
	}

	int biaoji1, biaoji2;
	biaoji1 = biaoji2 = 0;

	cout << "\nGrand Patrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation > 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji1 = 1;
		}
	}
	if (!biaoji1)
		cout << "none\n";

	cout << "\nPatrons : \n";
	for (int i = 0; i < num; i++)
	{
		if ((p_PeopleTypedef + i)->donation <= 10000)
		{
			cout << (p_PeopleTypedef + i)->name << "\t";
			cout << (p_PeopleTypedef + i)->donation << endl;
			biaoji2 = 1;
		}
	}
	if (!biaoji2)
		cout << "none\n";

	inFile.close();

	return 0;
}
#endif
