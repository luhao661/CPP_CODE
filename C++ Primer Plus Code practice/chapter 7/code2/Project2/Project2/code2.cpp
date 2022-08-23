#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//7.12复习题
//2.
#if 0
void igor(void);
float tofu(int);
double mpg(double, double);
long summation(long *p,int num);
double doctor(const char *string);
void ofcourse(struct boss bos);
char* plot(struct map *p_structure);
#endif


//3.
#if 0
void Array_Init(int *p_data,int num,int data);

void Array_Init(int* p_data, int num, int data)
{
	for (int i = 0; i < num; i++)
		*(p_data+i) = data;

	return;
}
#endif


//4.
#if 0
void fill_array(int* begin, int* end, int num)
{
	int* temp;
	for (temp = begin; temp != end; temp++)
		*temp = num;

	//法二：
	/*while (begin!=end)
	{
		*begin = num;
		begin++;
	}*/
}
#endif


//5.
#if 0
double FindMax(const double* p, int num)
{
	double max = *p;
	for (int i = 0; i < num-1; i++)
		(*(p + i)  >= *(p + i + 1)) ? (max = *(p + i)) : (max = *(p + i + 1));

	//法二：
	/*for (int i = 0; i < num; i++)
		if (*(p + i) > max)
			max = *(p+i);*/

		return max;
}
#endif


//8.
#if 0
int replace(char* str, char c1, char c2)
{
	int count = 0;

	while (str)
	{
		if (*str == c1)
		{
			*str = c2;
			count++;
		}
		str++;
	}
	
	return count;
}
#endif


//11.
#if 0
int judge(int (* p_fun) (const char* string));
#endif


//12.
#if 0
struct applicant
{
	char name[30];
	int credit_ratings[3];
};

struct applicant applicant_structure;

void show(struct applicant applicant_structure)
{
	std::cout << applicant_structure.name << "\n";
	for(int i=0;i<3;i++)
	std::cout << applicant_structure.credit_ratings[i] << std::endl;
}

void show(const struct applicant *p_applicant_structure)
{
	std::cout << p_applicant_structure->name << "\n";
	for (int i = 0; i < 3; i++)
	std::cout << p_applicant_structure->credit_ratings[i] << std::endl;
}
#endif


//13.
#if 0
struct applicant
{
	char name[30];
	int credit_ratings[3];
};

void f1(applicant *a);
const char* f2(const applicant *a1,const applicant * a2);

typedef void (*p_fun1)(applicant*);
typedef const char* (*p_fun2)(const applicant *,const applicant *);

int main(void)
{
	p_fun1 p1 = f1;
	p_fun2 p2 = f2;

	p_fun1 ap[5] = {f1,f1,f1,f1,f1};

	p_fun2 f2_array[10] = {f2,f2 ,f2 ,f2 ,f2  ,f2  ,f2  ,f2  ,f2  ,f2 };
	p_fun2(*pa)[10] = &f2_array;

	std::cout << "Done !";
	return 0;
}
void f1(applicant* a)
{}
const char* f2(const applicant* a1, const applicant* a2)
{
	return 0x00;
}
#endif