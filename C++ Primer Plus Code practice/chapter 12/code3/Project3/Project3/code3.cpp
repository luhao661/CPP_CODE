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

	Cow cow4 (cow3);//调用复制构造函数
	cow4.ShowCow();

	Cow cow5[2] = {{"ghj","aaa",50}};
	cow5[0].ShowCow();
	cow5[1].ShowCow();

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
#if 0
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


//4.
//链接12.10.4.cpp
#if 0
#include <cctype>  // or ctype.h
#include "12.10.4.h"

bool fill_data(Stack& s,Item &data);
void showdata(Item& item);

int main()
{
	using namespace std;

	Stack st(3);

	Item data;
	cout << "Please enter A to add a purchase order,"
		<< "P to delete, S to show, or Q to quit.\n";
	char ch;
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;

		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			if (!fill_data(st, data))
				cout << "stack already full\n";
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(data);//弹出栈的值会赋给data
				cout << "栈顶成员 ：" << data << " popped\n";
			}
			break;
		case 'S':
		case 's':
			st.traverse(showdata);
			break;
		}
		cout << "Please enter A to add a purchase order,"
			<< "P to delete, S to show, or Q to quit.\n";
	}

	cout << "使用复制构造函数："<<endl;
	Stack st1(st);
	cout << "st1的内容是：";
	st1.traverse(showdata);

	cout << "使用赋值运算符重载函数：" << endl;
	Stack st2;
	st2 = st;
	cout << "st2的内容是：";
	st2.traverse(showdata);

	cout << "Bye\n";
	return 0;
}

bool fill_data(Stack& s,Item &data)
{
	if (s.isfull())
		return false;

	using std::cout;
	using std::cin;

	cout << "Enter a number to add: ";
	while (!(cin >> data))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "请输入数字：";
	}
	s.push(data);
	return true;
}
void showdata(Item& item)
{
	using std::cout;
	using std::endl;

	cout << item<<"     ";
}
#endif


//5.
//链接12.10.5.cpp
#if 0
#include "12.10.5.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0));    //  random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);                 //创建对象并用构造函数初始化
											  // line queue holds up to qs people

	cout << "The number of simulation hours : 100小时\n";
	int hours = 100;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	cout << "Calculating the average number of customers per hour: \n......\n";
	double perhour=10;         //  average # of arrival per hour
	double min_per_cust;    //  average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间

	Item temp;              //  new customer data
	long turnaways = 0;     //  turned away by full queue
	long customers = 0;     //  joined the queue
	long served = 0;        //  served during the simulation
	long sum_line = 0;      //  cumulative line length
	int wait_time = 0;      //  time until autoteller is free
	long line_wait = 0;     //  cumulative time in line

do{
		perhour++;
		min_per_cust = MIN_PER_HR / perhour;
		//***注***每次模拟完成后，要对各参数归0
		turnaways = customers = served = sum_line\
			= wait_time = line_wait = 0;

		//***注***
		//错误：下次运行时队列的节点没有清空
		//改正：
		while (!line.isempty())
			line.dequeue(temp);

	// running the simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);    // cycle = time of arrival
					line.enqueue(temp); // add newcomer to line
				}
			}
			if (wait_time <= 0 && !line.isempty())//当队列空闲且有节点时
			{
				line.dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
				wait_time = temp.ptime(); //wait_time即进行交易所花的时间

				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}

} while (((double)line_wait / served )<= 1.0/*|| ((double)line_wait / served) >= 1.1*/);

	// reporting results
	if (customers > 0)
	{
		cout << "每小时到达的客户数："<< perhour<<endl;
		cout << "customers accepted: " << customers << endl;//加入队列的人数
		cout << "  customers served: " << served << endl;//已服务完的人数
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	cout << "Done!\n";
	// cin.get();
	// cin.get();
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}
#endif


//6.
//链接12.10.6.cpp
#if 0
#include "12.10.6.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0));    //  random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Maximum size of queue: 10\n";
	//int qs;
	//cin >> qs;
	//Queue line(qs);                 //创建对象并用构造函数初始化
	//										  // line queue holds up to qs people
	Queue line[2];

	//***注***由于把赋值运算符重载函数放在了private，所以不能实现对象间赋值
	//line[0] = Queue(qs);

	cout << "The number of simulation hours : 100 小时\n";
	int hours = 100;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles

	cout << "Calculating the average number of customers per hour: \n......\n";
	double perhour = 10;         //  average # of arrival per hour
	double min_per_cust;    //  average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间


	Item temp;              //***注***客户是一个，不能放到结构体中

	typedef struct			//存储两个队列的排队情况
	{
		long turnaways ;     //  turned away by full queue
		long customers ;     //  joined the queue
		long served ;        //  served during the simulation
		long sum_line ;      //  cumulative line length
		int wait_time ;      //  time until autoteller is free
		long line_wait ;     //  cumulative time in line
	}x;

	x x_struct[2];//***注***无法使用C的初始化器

	double temp1,temp2,result;

	do 
	{
		perhour++;
		min_per_cust = MIN_PER_HR / perhour;
		//***注***每次模拟完成后，要对各参数归0
		for (int i = 0; i < 2; i++)
		{
			x_struct[i].customers = x_struct[i].line_wait = x_struct[i].served
				= x_struct[i].sum_line = x_struct[i].turnaways
				= x_struct[i].wait_time=0;
		}

		//***注***
		//错误：下次运行时队列的节点没有清空
		//改正：
		while (!line[0].isempty())
			line[0].dequeue(temp);

		while (!line[1].isempty())
			line[1].dequeue(temp);

		// running the simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line[0].isfull())
					x_struct[0].turnaways++;

				if (line[1].isfull())
					x_struct[1].turnaways++;

				if (!line[0].isfull() || !line[1].isfull())
				{
					if (line[0].queuecount() <= line[1].queuecount())
					{
						x_struct[0].customers++;
						temp.set(cycle);    // cycle = time of arrival
						line[0].enqueue(temp); // add newcomer to line
					}
					else
					{
						x_struct[1].customers++;
						temp.set(cycle);    // cycle = time of arrival
						line[1].enqueue(temp); // add newcomer to line
					}
				}
			}

			if (x_struct[0].wait_time <= 0 && (!line[0].isempty()))//当队列空闲且有节点时
			{
				line[0].dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
				x_struct[0].wait_time = temp.ptime(); //wait_time即进行交易所花的时间
				x_struct[0].line_wait += cycle - temp.when();
				x_struct[0].served++;
			}

			if (x_struct[1].wait_time <= 0 && (!line[1].isempty()))//当队列空闲且有节点时
			{
				line[1].dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
				x_struct[1].wait_time = temp.ptime(); //wait_time即进行交易所花的时间
				x_struct[1].line_wait += cycle - temp.when();
				x_struct[1].served++;
			}

			if (x_struct[0].wait_time > 0)
				x_struct[0].wait_time--;

			if (x_struct[1].wait_time > 0)
				x_struct[1].wait_time--;

			x_struct[0].sum_line += line[0].queuecount();
			x_struct[1].sum_line += line[1].queuecount();
		}

		temp1 = (double)x_struct[0].line_wait / x_struct[0].served;
		temp2 = (double)x_struct[1].line_wait / x_struct[1].served;

		result = (temp1 + temp2) / 2;

	} while (result<=1.0);
	//(((double)x_struct[0].line_wait / x_struct[0].served) <= 1.0
	//	|| ((double)x_struct[0].line_wait / x_struct[0].served) >= 1.1)
	//	|| (((double)x_struct[1].line_wait / x_struct[1].served) <= 1.0
	//		|| ((double)x_struct[1].line_wait / x_struct[1].served) >= 1.1)

	// reporting results
	cout << "每小时到达的客户数：" << perhour << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "customers accepted: " << x_struct[i].customers << endl;//加入队列的人数
		cout << "  customers served: " << x_struct[i].served << endl;//已服务完的人数
		cout << "         turnaways: " << x_struct[i].turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)x_struct[i].sum_line /cyclelimit << endl;
		cout << " average wait time: "
			<< (double)x_struct[i].line_wait / x_struct[i].served << " minutes\n";
	}

	cout << "Done!\n";
	// cin.get();
	// cin.get();
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}
#endif