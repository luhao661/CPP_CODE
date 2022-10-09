#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX13_11_1_H 
#define BCLX13_11_1_H
// base class
class Cd
{// represents a CD disk
private:
	char performers[50];
	char label[20];
	int selections; // number of selections
	double playtime;// playing time in minutes

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;// reports all CD data
	Cd& operator= (const Cd& d);
};

class Classic :public Cd
{
private:
	char composition[20];

public:
	Classic();
	Classic(const char *s1, const char* s2, const char* s3, 
		int n, double x);
	virtual ~Classic();
	virtual void Report() const;// reports all CD data
	//Classic& operator=(const Classic&d);
	//***注***若使用派生类默认的赋值运算符重载函数Classic & operator=(const Classic&);
	//也没有关系，因为派生类没有用new进行动态内存分配，也就不需要再重新定义析构函数、赋值运算符重载函数了
};

#endif