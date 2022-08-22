#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 0
int main(void)
{
	using namespace std;

	return 0;
}
#endif


//7.13 编程练习
//1.
#if 0
double harmonic_average_fun(double a,double b);

int main(void)
{
	using namespace std;

	cout <<"请输入两个数字：";

	double a, b;
	double harmonic_average;
	while (cin >> a >> b && a != 0 && b != 0)
	{
		harmonic_average = harmonic_average_fun(a,b);
		cout << "数字"<<a<<"和"<<b<<"的调和平均数是："<<harmonic_average<<endl;
		cout << "请输入两个数字：";
	}

	return 0;
}
double harmonic_average_fun(double a, double b)
{
	double result = 2.0 * a * b / (a+b);

		return result;
}
#endif


//2.
#if 0
int fill_array(double *p_num);
void show(const double *p_num,int);
double average(const double *p_num,int);

using namespace std;


int main(void)
{	
	cout << "请输入最多10个高尔夫成绩(输入0以结束输入)：";
	double scores[10];
	int count = fill_array(scores);

	show(scores,count);

	double averagenum = average(scores,count);
	cout << "平均成绩："<<averagenum<<endl;

	return 0;
}
int fill_array(double* p_num)
{
	int count = 0;
	double temp;

	for (int i = 0; i < 10; i++)
	{
		while (!(cin >>temp))
		{
			cin.clear();

			while (cin.get() != '\n')
				continue;    //消耗掉错误的输入

			cout << "请输入数字！" << endl;
		}

		if (temp != 0)
		{
			p_num[i] = temp;
			count++;
		}
		else
			break;
	}

	return count;
}
void show(const double* p_num,int num)
{
	cout.put('\n')<<"输入的成绩为：";
	for (int i = 0; i < num; i++)
		cout << *(p_num + i) << "  ";
	cout << endl;
}
double average(const double* p_num, int num)
{
	double sum = 0.0;
	for (int i = 0; i < num; i++)
		sum+=*(p_num + i);

	return (double)(sum / num);
}
#endif


//4.
#if 0
long double probability(unsigned numbers, unsigned picks,
	unsigned numbers1, unsigned picks1);

int main()
{
	using namespace std;
	double total, choices;
	double total1, choices1;
	cout << "请输入普通数字的区间(1~X)和允许选择的号码个数\n";

	while ((cin >> total>> choices) && choices <= total)
	{
		cout << "请输入特选数字的区间(1~X)和允许选择的号码个数\n";
		cin >> total1 >> choices1;

		cout << "You have one chance in ";
		cout << probability(total, choices,total1,choices1);      // compute the odds
		cout << " of winning.\n";
		cout << "请输入普通数字的区间(1~X)和允许选择的号码个数\n";
	}
	cout << "Bye\n";
	// cin.get();
	// cin.get();
	return 0;
}
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
long double probability(unsigned numbers, unsigned picks,
	unsigned numbers1, unsigned picks1)
{
	long double result = 1.0, result1 = 1.0; // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	for (n = numbers1, p = picks1; p > 0; n--, p--)
		result1 = result1 * n / p;

	return result*result1;
}
#endif


//5.
#if 0
long long temp = 1;
long long jiecheng(long long num);

int main(void)
{
	using namespace std;

	cout << "请输入要阶乘的整数：";
	long long num,result;
	while (cin >> num)
	{
		result = jiecheng(num);
		cout << num << "! = "<<result<<endl;
		temp = 1;
		cout << "请输入要阶乘的整数：";
	}

	return 0;
}
long long jiecheng(long long num)
{
	if (num == 0 || num == 1)
		return 1;
	else
	{
		temp *= num;
		jiecheng(--num);
	}

	return temp;
}
#endif


//7.
#if 0
const int Max = 5;

// function prototypes
double* fill_array(double ar[], int limit);
void show_array(const double ar[], double*);  // don't change data
void revalue(double r, double ar[], double*);

int main()
{
	using namespace std;
	double properties[Max];

	double*end = fill_array(properties, Max);

	show_array(properties, end);

	if (end-properties > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))    // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}

		revalue(factor, properties, end);
		show_array(properties, end);
	}
	cout << "Done.\n";
	// cin.get();
	// cin.get();
	return 0;
}

double* fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	double* end;

	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)    // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)     // signal to terminate
			break;

		ar[i] = temp;
	}
	end = ar + i;

	return end;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], double *end)
{
	using namespace std;
	for (int i = 0; i < end-ar; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double*end)
{
	for ( ;		ar<end; 	ar++)
		*ar *= r;
}
#endif


//8.a.
#if 1
#include <array>//array类
#include <string>//string类

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//声明一个const array对象，该对象包含4个string对象

//******************注***********************
/*法二
//const char *Snames[Seasons] =
//{ "Spring", "Summer", "Fall", "Winter" };
*/
/*法三
const char Snames[Seasons][20] =
{ "Spring", "Summer", "Fall", "Winter" };
*/

void fill(std::array<double, Seasons>* pa);//形参：指向array对象的指针
void show(std::array<double, Seasons> da);//形参：array对象

int main()
{
	std::array<double, Seasons> expenses;//声明一个array对象，包含4个double类型的值

							   //***注***
	fill(&expenses);//实参：array整个对象的地址，而不是&array[0]
	show(expenses);
	// std::cin.get();
	// std::cin.get();
	return 0;
}

void fill(std::array<double, Seasons>* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> (*pa)[i];//此处写法唯一
		//std::cin >> *(pa + i);//***注***错误：每次+1都增加1个array对象所占的字节数
	}
}

void show(std::array<double, Seasons> da)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";

	for (int i = 0; i < Seasons; i++)
	{
		std::cout << Snames[i] << ": $" << da[i] << '\n';
		total += da[i];
	}

	std::cout << "Total: $" << total << '\n';
}
#endif

