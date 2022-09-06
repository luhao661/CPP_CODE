#define _CRT_SECURE_NO_WARNINGS 1

#ifndef class_Person
#define class_person

#include <iostream>
using std::string;

class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person()
	{
		lname = "";
		fname[0] = '\0';
	}
	Person(const string &ln, const char *fn="Heyyou");
	void Show()const;
	void FormalShow()const;
};

#endif   /*class_Person*/