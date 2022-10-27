#define _CRT_SECURE_NO_WARNINGS 1

#if 1

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
	cout << "姓名："<<lname<<fname<<endl;
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
	os<< "姓名：" << e.lname << e.fname << endl;

	return os;
}

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

manager::manager():abstr_emp()
{}

manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico = 0)
	: abstr_emp(fn, ln, j),inchargeof(ico)
{}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(ico)//使用abstr_emp类的默认复制构造函数
{}

manager::manager(const manager& m)
	: abstr_emp(m)//向上强制转换
{}

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

#endif