#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//14.7 编程练习
//1.
//链接14.7.1.cpp
#if 0
#include "14.7.1.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	
	cout << "Enter number of years:";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);// store label,years,give arrays yrs elements
	holding.GetBottles();// solicit input for year,bottle count
	holding.Show(); // display object contents

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };

	// create new object,initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	
	cout << "Total bottles for" << more.Label()// use Label()method
	<< ": " << more.sum() << endl; // use sum () method
	cout << "Bye\n";
	return 0;
}
#endif


//2.
//链接14.7.2.cpp
#if 0
#include "14.7.2.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);

	cout << "Enter number of years:";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);// store label,years,give arrays yrs elements
	holding.GetBottles();// solicit input for year,bottle count
	holding.Show(); // display object contents

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };

	// create new object,initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for" << more.Label()// use Label()method
		<< ": " << more.sum() << endl; // use sum () method
	cout << "Bye\n";
	return 0;
}
#endif


//3.
//链接14.7.3.cpp
#if 0
#include <cstring>
#include "14.7.3.h"
const int SIZE = 3;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	//***注***原来的方法是用指针数组存指向Worker的指针，
	//现在仅需声明一个指针，并用指针队列来存
	Worker* lolas=(Worker* )0x00;
	QueueTp<Worker*>lolas_stack;

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{

		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";

		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':  lolas = new Waiter;
			break;
		case 's':   lolas = new Singer;
			break;
		case 't':   lolas = new SingingWaiter;
			break;
		}

		cin.get();
		lolas->Set();
		lolas_stack.enqueue(lolas);
	}


	Worker* lolas_1=(Worker *)0x01;
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas_stack.dequeue((lolas_1));
		lolas_1->Show();
	}

	//for (i = 0; i < ct; i++)
	//	delete lolas[i];

	cout << "Bye.\n";
	// cin.get();
	// cin.get();
	return 0;
}
#endif


//4.
//链接14.7.4.cpp
#if 1
#include <cstring>
#include "14.7.4.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Person* lolas[SIZE];

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "g: Gunslinger  p: PokerPlayer  "
			<< "b: BadDude q: quit\n";

		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'g':   lolas[ct] = new Gunslinger;
			break;
		case 'p':   lolas[ct] = new PokerPlayer;
			break;
		case 'b':   lolas[ct] = new BadDude;
			break;
		}

		cin.get();
		lolas[ct]->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}

	for (i = 0; i < ct; i++)
		delete lolas[i];

	cout << "Bye.\n";
	// cin.get();
	// cin.get();
	return 0;
}
#endif