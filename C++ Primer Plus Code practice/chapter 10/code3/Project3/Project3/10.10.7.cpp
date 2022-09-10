#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.7.h"
#include <cstring>
#include <iostream>

BetelPlorg::BetelPlorg(const char* data, int level)
{
	strncpy(m_name,data,19);
	m_name[19]='\0';
	m_level = level;
}
BetelPlorg::BetelPlorg()
{
	strcpy(m_name,"Plorga");
	/*const char* p = "Plorga";
	m_name = p;*/  // const不能赋给非const

	m_level = 50;
}
BetelPlorg::~BetelPlorg()
{}
void BetelPlorg::modification(int level)
{
	m_level = level;
}
void BetelPlorg::show()const
{
	using std::cout;
	using std::endl;

	cout << "name : "<<m_name<<'\t'<<"level : "<<m_level<<endl;
}

#endif