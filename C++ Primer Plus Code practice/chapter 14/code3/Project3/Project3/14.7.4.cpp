#define _CRT_SECURE_NO_WARNINGS 1

#if 1

#include <iostream>
#include "14.7.4.h"
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using std::cin;
using std::cout;
using std::endl;

Person::Person(const string& s1, const string& s2):fname(s1),lname(s2)
{}//书P393

Person::Person():fname("no data"),lname("no data")
{}

Person::~Person()
{}

void Person::Show(void) const
{
	cout << "姓名："<<lname<<" "<<fname<<endl;
}

 void Person::Get()
{
	 cout << "请输入姓：";
	 cin >> lname;

	 cout << "请输入名：";
	 cin >> fname;

	 while (cin.get() != '\n')
		 continue;
}

/*****************************************************************************/

Gunslinger::Gunslinger(const string& s1, const string& s2,double tim, int tra)
	:Person(s1,s2)
{
	time = tim;
	trace = tra;
}

Gunslinger::Gunslinger():Person()
{
	time = Gunslinger::Draw();
	trace = 10;
}

double Gunslinger::Draw(void) 
{
	std::srand((double)std::time(0));

	double x= std::rand() * 2 / RAND_MAX;
	while(x<=0.2)
		x = std::rand() * 2 / RAND_MAX;

	return x;
}

void Gunslinger::Show(void)const
{
	Person::Show();
	/*cout << "拔枪时间："<<time<<endl;
	cout << "枪上的刻痕数："<<trace<<endl;*/
	Data();//实现代码重用
}

void Gunslinger::Set()
{
	Person::Get();
	Get();//相当于Gunslinger::Get();
}

void Gunslinger::Data()const
{
	cout << "拔枪时间：" << time << endl;
	cout << "枪上的刻痕数：" << trace << endl;
}

void Gunslinger::Get()
{
	cout << "请输入拔枪时间：";
	cin >> time;
	cout << "请输入枪上的刻痕数：";
	cin >> trace;

	while (cin.get() != '\n')
		continue;
}

double Gunslinger::r_time(void)const
{
	return time;
}

/*****************************************************************************/

PokerPlayer::PokerPlayer(const string& s1, const string& s2, int num)
	:Person(s1,s2)
{
	poker = num;
}

PokerPlayer::PokerPlayer():Person()
{
	poker = 1;
}

PokerPlayer::~PokerPlayer()
{}

 double PokerPlayer::Draw(void)
{
	 std::srand(std::time(0));

	 return (std::rand() %52+1);
}

 void PokerPlayer::Show(void) const
 {
	 Person::Show();
	 Data();
 }

 void PokerPlayer::Set()
 {
	 Person::Get();
	 Get();
 }

 void PokerPlayer::Data()const
 {
	 cout << "扑克牌的值："<<poker<<endl;
 }

 void PokerPlayer::Get()
 {
	 cout << "请输入扑克牌的值：";
	 cin >> poker;

	 while (cin.get() != '\n')
		 continue;
 }

 int PokerPlayer::r_poker(void)const
 {
	 return poker;
 }

 /*****************************************************************************/

 BadDude::BadDude(const string& s1, const string& s2,
	 double tim, int tra, int num)
	 :Person(s1,s2),Gunslinger(s1,s2,tim,tra),PokerPlayer(s1,s2,num)
 {}

 BadDude::BadDude():Person(),Gunslinger(),PokerPlayer()
 {}

 double BadDude::Gdraw()const
 {
	 return Gunslinger::r_time();
 }

 double BadDude::Cdraw()const
 {
	 return PokerPlayer::r_poker();
 }

 void BadDude::Show(void)const
 {
	 Person::Show();
	 Gunslinger::Data();
	 PokerPlayer::Data();
 }

 void BadDude::Set()
 {
	 Person::Get();
	 Gunslinger::Get();
	 PokerPlayer::Get();
 }

 void BadDude::Data()const
 {}

 void BadDude::Get()
 {}

#endif