#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.9.5.h"
#include <cstring>
Account::Account(const char* name, const char* identification, double savings)
{
	strncpy(m_name,name,LEN-1);//最多拷贝LEN-1个字符(即拷贝的是LEN-1个字符和空字符)
	m_name[LEN - 1] = '\0';
	memcpy(m_identification,identification,strlen(identification)*sizeof(char)+1);//把最后的空字符也拷贝进来
	m_savings = savings;
}
Account::Account()
{
	strcpy(m_name, "no name");
	strcpy(m_identification,"no ID");
	m_savings = 0.0;
}
Account::~Account()
{}


#endif