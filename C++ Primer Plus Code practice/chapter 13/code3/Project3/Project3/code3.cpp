#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//13.11 编程练习
//1.
//链接13.11.1.cpp
#if 0
#include "13.11.1.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd & disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
	disk.Report();
}
#endif


//2.
//链接13.11.2.cpp
#if 0
#include "13.11.2.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd& disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
	disk.Report();
}
#endif


//3.
//链接13.11.3.cpp
#if 1
#include "cxqd13.7.h"
#include <string>

const int CLIENTS = 4;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    Brass* p_clients[CLIENTS];//声明一个数组，每个元素都是指向Brass类的指针
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";

        while (!(cin >> kind) || (kind != '1' && kind != '2'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        if (kind == '1')
            p_clients[i] = new Brass(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate "
                << "as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                tmax, trate);
        }
        while (cin.get() != '\n')//消耗掉换行符，否则getline()将读取不到第二次及之后的输入
            continue;
    }

    cout << endl;
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}
#endif