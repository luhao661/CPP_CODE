#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "13.11.4.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br)+1];
	strcpy(brand, br);

	strncpy(style,st,19);
	style[19]='\0';

	bottles = b;
}

Port::Port(const Port& p)// copy constructor
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand,p.brand);

	strcpy(style,p.style);

	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return *this;

	delete[]brand;

	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);

	strcpy(style, p.style);

	bottles = p.bottles;

	return *this;
}

Port& Port::operator+=(int b) // adds b to bottles
{
	bottles += b;

	return *this;
}

Port& Port::operator-=(int b) // subtracts b from bottles,if 	available
{
	if (b > bottles)
	{
		std::cout << "不能减去大于"<<bottles<<"的数字！\n";
		return *this;
	}

	bottles -= b;

	return *this;
}

void Port::Show() const
{
	using std::cout;
	using std::endl;

	cout << "Brand: "<<brand<<endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: "<<bottles<<endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", "<<p.bottles;

	return os;
}

/**************************************************************************************/

VintagePort::VintagePort():Port()//使用基类自动提供的的默认构造函数
{
	nickname = new char[1];
	nickname[0] = '\0';

	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn
	, int y):Port(br,"vintage",b)
{
	nickname = new char[strlen(nn)+1];
	strcpy(nickname,nn);

	year = y;
}

VintagePort::VintagePort(const VintagePort& vp):Port(vp)
{//***注***此处用成员初始化列表，是基于动态联编的向上强制转换
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);

	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;

	Port::operator=(vp);

	delete[]nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();

	std::cout << "Nickname: " << nickname << endl;
	std::cout << "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp;
	std::cout <<", "<< vp.nickname << ", " << vp.year;

	return os;
}

#endif