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
#if 0
#include "10.10.3.h"
int main()
{
	Golf golf1("Xiao min",1);
	golf1.showgolf();
	golf1.handicap(0);
	golf1.showgolf();

	Golf golf2;
	golf2.showgolf();

	return 0;
}
#endif


//4.
//链接10.10.4.cpp
#if 0
#include "10.10.4.h"
int main()
{
	using namespace SALES;

	double data[1] = {1.1};
	Sales sales1(data,1);
	sales1.ShowSales();

	Sales sales2;
	sales2.ShowSales();

	return 0;
}
#endif


//5.
//链接10.10.5.cpp
#if 1
#include "10.10.5.h"
#include <cctype>
using namespace std;

void show_order(void);
char get_choice(void);
void fill_stack(Stack& st);
void delete_item(Stack& st);

int main() 
{
	Stack stack;

	show_order();
	char ch=get_choice();

	while (ch != 'c')
	{
		switch (ch)
		{
		case 'a':
			fill_stack(stack);
			break;
		case 'b':
			delete_item(stack);
			break;
		}
		show_order();
		ch = get_choice();
	}

	return 0;
}
void show_order(void)
{
	cout << "请输入各项功能对应的字母：";
	cout << "\na) 添加顾客"<<'\t'<<"b) 删除顾客\n";
	cout << "c) 退出\n";
}
char get_choice(void)
{
	char answer;
	while (cin.get(answer))
	{
		while (cin.get() != '\n')
			continue;
		answer = tolower(answer);

		if (strchr("abc", answer) == NULL)
			cout << "\a请输a、b或c : ";
		else
			break;
	}
	return answer;
}
void fill_stack(Stack& st)
{
	if (st.isfull())
	{
		cout << "栈已满！";
		return;
	}

	Item item;
	cout << "请输入顾客的名字：";
	char temp[35];
	double money = 0.0;
	while (cin.get(temp, 34))//get()读取空行后会设置失效位   ***注***不能写成	while (cin.get(temp, 34).get())
	{
		cout << "请输入顾客付款额：";
		while (!(cin >> money))
		{
			cout << "Bad input. Please enter a number:  ";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		cin.get();

		strcpy(item.fullname,temp);
		item.payment = money;
		st.push(item);
		cout << "请输入顾客的名字：(只输入Enter以停止)";
	}

	cin.clear();//***注***此句必写
	cin.get();//消耗掉换行符
}
void delete_item(Stack& st)
{
	if(st.isempty())
	{
		cout << "栈为空！";
		return;
	}

	Item item;
	st.pop(item);

	cout << "栈顶成员 ：" << item.fullname<<'\t'
		<<item.payment<< " popped\n";

	static double sum = 0.0;
	sum += item.payment;

	cout << "共计"<<sum<<"元\n\n";
}
#endif