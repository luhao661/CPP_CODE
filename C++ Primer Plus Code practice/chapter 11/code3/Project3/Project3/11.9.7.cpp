#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include "11.9.7.h"

Complex::Complex()
{
	m_real_part = m_imaginary_part = 0.0;
}

Complex::Complex(double real, double imaginary)
{
	m_real_part = real;
	m_imaginary_part = imaginary;
}
Complex::~Complex()
{}

std::istream& operator>>(std::istream& is, Complex& com)
{
	using std::cout;

	cout << "real : ";
	while (!(is >> com.m_real_part))
	{
		is.clear();
		while (is.get() != '\n')
			continue;
		cout << "错误的输入内容，请重新输入！\n";
	}
	cout << "imaginary : ";
	while (!(is >> com.m_imaginary_part))
	{
		is.clear();
		while (is.get() != '\n')
			continue;
		cout << "错误的输入内容，请重新输入！\n";
	}

	return is;
}
std::ostream& operator<<(std::ostream& os, const Complex& com)
{
	using std::endl;

	os << "(" << com.m_real_part << "," 
		<<com.m_imaginary_part<< "i)";

	return os;
}
Complex Complex::operator+(const Complex& com)const
{
	return Complex(m_real_part+com.m_real_part,m_imaginary_part+com.m_imaginary_part);
}

Complex Complex::operator-(const Complex& com)const
{
	return Complex(m_real_part - com.m_real_part, m_imaginary_part - com.m_imaginary_part);
}

Complex Complex::operator-()const
{
	return Complex(-m_real_part,-m_imaginary_part);
}

Complex Complex::operator~()const
{
	return Complex(m_real_part,-m_imaginary_part);
}

//两个复数相乘
//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
Complex Complex::operator*(const Complex& com)const
{
	return Complex(m_real_part*com.m_real_part-m_imaginary_part*com.m_imaginary_part
	,m_imaginary_part*com.m_real_part+m_real_part*com.m_imaginary_part);
}

//复数和实数相乘
Complex Complex::operator*(double x)const
{
	return Complex(m_real_part*x,m_imaginary_part*x);
}
Complex operator*(double x, const Complex& com)
{
	return com * x;
}

#endif