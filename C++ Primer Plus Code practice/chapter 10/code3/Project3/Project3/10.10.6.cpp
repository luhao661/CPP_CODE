#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "10.10.6.h"
#include <iostream>

Move::Move(double a, double b )
{
	x = a;
	y = b;
}
void Move::showmove()const
{
	using std::cout;

	cout << "x = "<<x<<'\t'<<"y = "<<y<<std::endl;
}
Move Move::add(const Move& m)const
{
	Move temp;
	temp.x = m.x;
	temp.y = m.y;

	return temp;
}
void Move::rest(double a, double b)
{
	x = a;
	y = b;
}

#endif