#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "14.7.5.h"

using std::cin;
using std::cout;
using std::endl;

abstr_emp::abstr_emp()
	:fname("no data"),lname("no data"),job("no data")
{}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln,
	const std::string& j)
	: fname(fn), lname(ln), job(j)
{}

void abstr_emp::ShowAll()const// labels and shows all data
{
	cout << "姓名："<<lname<<" " << fname << endl;
	cout << "工作："<<job<<endl;
}

void abstr_emp::SetAll() // prompts user for values
{
	cout << "请输入姓：";
	cin >> lname;
	cout << "请输入名：";
	cin >> fname;
	cout << "请输入工作：";
	cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os<< "姓名：" << e.lname <<" " << e.fname;

	return os;
}

abstr_emp::~abstr_emp()//***注***必须在ABC的实现文件中定义纯虚析构函数
{}

/****************************************************************************/

employee::employee():abstr_emp()
{}

employee::employee(const std::string& fn, const std::string& ln,
	const std::string& j): abstr_emp(fn,ln,j)
{}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

/****************************************************************************/

manager::manager():abstr_emp(),inchargeof(0)
{}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j),inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)//使用abstr_emp类的默认复制构造函数
{}

manager::manager(const manager& m)
	: abstr_emp(m)//向上强制转换
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "工资："<<inchargeof<<endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入工资：";
	cin >> inchargeof;
}

/****************************************************************************/

fink::fink():abstr_emp(),reportsto("no data")
{}

fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	:abstr_emp(fn,ln,j),reportsto(rpo)
{}

fink::fink(const abstr_emp& e, const std::string& rpo)
	:abstr_emp(e), reportsto(rpo)
{}

fink::fink(const fink& e)
	:abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto : "<< reportsto<<endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入reportsto：";
	cin >> reportsto;
}

/****************************************************************************/

highfink::highfink()
	:manager(),fink(),abstr_emp()//或不写，则调用默认的构造函数
{}

highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo,int ico)
	:manager(fn,ln,j,ico),fink(fn,ln,j,rpo),abstr_emp(fn,ln,j)
{}

highfink::highfink(const abstr_emp& e, const std::string& rpo,
	int ico)
	:manager(e,ico),fink(e,rpo),abstr_emp(e)
{}

highfink::highfink(const fink& f, int ico)
	:manager(f,ico),fink(f),abstr_emp(f)
{}

highfink::highfink(const manager& m, const std::string& rpo)
	:manager(m), fink(m,rpo), abstr_emp(m)
{}

highfink::highfink(const highfink& h)
	: manager(h), fink(h), abstr_emp(h)
{}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "工资："<<manager::InChargeOf()<<endl;
	cout << "reportsto : " << ReportsTo()<<endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "请输入工资：";
	cin >> InChargeOf();
	cout << "请输入reportsto：";
	cin >> ReportsTo();
}

#endif