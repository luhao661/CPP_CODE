#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_15_12_1_H
#define CXQD_15_12_1_H

#include <exception>

class bad_hmean :public std::exception
{
public:
	const char* what()
	{
		return "bad argument to hmean()\n";
	}
};

class bad_gmean :public std::exception
{
public:
	const char* what()
	{
		return "bad argument to gmean()\n";
	}
};
#endif