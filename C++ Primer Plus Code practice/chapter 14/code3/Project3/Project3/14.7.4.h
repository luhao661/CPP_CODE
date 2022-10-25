#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_14_7_4_H
#define BCLX_14_7_4_H

#include <string>
using std::string;

class Person
{
private:
	string fname;
	string lname;
public:
	Person(const string&s1,const string&s2);
	Person();
	virtual ~Person();
	virtual void Show(void) const;
};

class Gunslinger:virtual public Person
{
private:
	double time;
	int trace;
public:
	Gunslinger(double tim,int tra);
	Gunslinger();
	virtual double Draw(void) ;
	virtual void show(void)const;
};

class PokerPlayer:virtual public Person
{
private:
	/*class Card
	{
	private :
		int huase;
		int mianzhi;
	public:
		Card(int a=0,int b=0):huase(a),mianzhi(b)
		{}
	};*/
public:
	PokerPlayer();
	~PokerPlayer();
	virtual double Draw(void);
	virtual void Show(void) const;
};

class BadDude:public Gunslinger,public PokerPlayer
{
public:
	BadDude();

	double Gdraw()const;
	double Cdraw()const;
	virtual void Show(void)const;
};

#endif