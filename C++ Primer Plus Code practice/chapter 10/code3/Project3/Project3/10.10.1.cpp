#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
#include "10.10.1.h"
#include <cstring>

Account::Account(const char* name, const char* identification, double savings)
{
	strncpy(m_name, name, LEN - 1);//最多拷贝LEN-1个字符(即拷贝的是LEN-1个字符和空字符)
	m_name[LEN - 1] = '\0';
	memcpy(m_identification, identification, strlen(identification) * sizeof(char) + 1);//把最后的空字符也拷贝进来
	m_savings = savings;
}
Account::Account()
{
	strcpy(m_name, "no name");
	strcpy(m_identification, "no ID");
	m_savings = 0.0;
}
Account::~Account()
{}
void Account::show() const
{
	using std::cout;
	using std::endl;

	cout << "储户姓名："<<m_name<<endl;
	cout << "账号："<<m_identification<<endl;
	cout << "存款："<<m_savings<<endl<<endl;
}
void  Account::deposit(double savings)//***注***写成inline void  Account::deposit(double savings) 会报错
{
	m_savings += savings;
}
void  Account::draw(double savings)
{
	m_savings -=savings;
}

#endif