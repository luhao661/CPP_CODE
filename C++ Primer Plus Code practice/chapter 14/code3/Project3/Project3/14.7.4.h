#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_14_7_4_H
#define BCLX_14_7_4_H

#include <string>
using std::string;

class Person
{
private:
	string lname;
	string fname;

public:
	Person(const string&s1,const string&s2);
	Person();
	virtual ~Person();
	virtual void Show(void) const = 0;//使Person作为ABC(ABC中实现)
	virtual void Set() = 0;//要求派生类必须要有此接口(ABC中不实现)
									   //Set()实际上是为了更多地进行代码重用

protected:
	virtual void Get();
	virtual void Data()const=0;//要求派生类必须要有此接口(ABC中不实现)
};

class Gunslinger:virtual public Person
{
private:
	double time;
	int trace;

public:
	Gunslinger(const string& s1, const string& s2,double tim,int tra);
	Gunslinger();
	virtual double Draw(void) ;
	virtual void Show(void)const;

	virtual void Set();

protected:
	void Data()const;
	void Get();
	double r_time(void)const;
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
	int poker;

public:
	PokerPlayer(const string& s1, const string& s2,int num);
	PokerPlayer();
	~PokerPlayer();
	virtual double Draw(void);
	virtual void Show(void) const;

	virtual void Set();

protected:
	void Data()const;
	void Get();
	int r_poker(void)const;
};

class BadDude:public Gunslinger,public PokerPlayer
{
public:
	BadDude(const string& s1, const string& s2,
		double tim, int tra, int num);
	BadDude();

	double Gdraw()const;
	double Cdraw()const;
	virtual void Show(void)const;

	virtual void Set();

protected:
	void Data()const;
	void Get();
};

#endif