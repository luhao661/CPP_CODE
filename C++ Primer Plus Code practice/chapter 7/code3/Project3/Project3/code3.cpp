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
#if 1
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

//法一：递归的返回值不使用
 #if 0
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

/*
long long jiecheng(long long num)
{
	if (num == 0 || num == 1)
		return 1;
	else
	{
		temp = num * jiecheng(num--);//错误：这样会无限调用函数jiecheng()
		return temp;
	}
}
*/

//法二：
long long jiecheng(long long num)
{
	if (num == 0 || num == 1)
		return 1;
	if(num>1)
	{
		temp = num * jiecheng(num--);
		//***注***
		//若写成--num，则此语句先是把num递减，然后把*号左侧用num递减后的值代替，再进入调用的函数，所以得2!=1
		//若写成num--，则此语句先是把*号左侧用num的值代替，然后把num递减，再进入调用的函数，但是在第二次进入函数时(用监视器查看num值可知)num又变回了原值，导致程序无限循环
		// 理解：书P112：
		//此语句末尾是个顺序点，C++只能保证此语句后面，num的值会减少1，并不保证在此语句进行的某个时刻，使num值减1
		return temp;
	}
}
#endif


//6.对比程序清单5.9 反转数组的另一种方法
#if 0
void reverse_array(double* ar, int size)
{
	double temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = ar[i];
		arr[i] = ar[size-i-i];
		arr[size - i - 1] = temp;
	}
}
#endif


//7.
#if 0
const int Max = 5;

// function prototypes
double* fill_array(double ar[], double *);
void show_array(const double ar[], double*);  // don't change data
void revalue(double r, double ar[], double*);

int main()
{
	using namespace std;
	double properties[Max];

	double*end = fill_array(properties, properties+Max);

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

double* fill_array(double ar[], double *end)
{
	using namespace std;
	double temp;
	int i=0;
	double* the_end;

	for (  ; ar!=end; ar++)
	{
		cout << "Enter value #" << (++i ) << ": ";
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

		*ar = temp;
	}
	the_end = ar;

	return the_end;
}

 //the following function can use, but not alter,
 //the array whose address is ar
void show_array(const double ar[], double *end)
{
	using namespace std;
	for (int i = 0; i < end-ar; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}

//法二：
#if 0
void show_array(const double ar[], double* end)
{
	using namespace std;

	 int *p_num=new int[end - ar];
	 int index;
	 for (index = end - ar-1; index >=0; index--)
		 *(p_num + index) = index;

	 index = 0;
	for (; ar!=end; ar++,index++)
	{
		cout << "Property #" << *(p_num + index)+1 << ": $";
		cout << *ar << endl;
	}

	delete[]p_num;
}
#endif

// multiplies each element of ar[] by r
void revalue(double r, double ar[], double*end)
{
	for ( ;		ar<end; 	ar++)
		*ar *= r;
}
#endif


//8.a.
#if 0
const int Seasons = 4;

const char  * Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

void fill(double *p_num,int NumToFill);
void show(const double *p_num,int NumToShow);

int main()
{
	double expenses[Seasons];
							   
	fill(expenses,Seasons);
	show(expenses,Seasons);
	// std::cin.get();
	// std::cin.get();
	return 0;
}

void fill(double* p_num, int NumToFill)
{
	for (int i = 0; i < NumToFill; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> *(p_num+i);
	}
}

void show(const double* p_num, int NumToShow)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";

	for (int i = 0; i < NumToShow; i++)
	{
		std::cout << Snames[i] << ": $" << *(p_num+i) << '\n';
		total +=*(p_num+i);
	}

	std::cout << "Total: $" << total << '\n';
}
#endif


//8.b.
#if 0
const int Seasons = 4;

const char* Snames[Seasons] =
{ "Spring", "Summer", "Fall", "Winter" };

typedef struct
{
	double expenses[Seasons];
}Expenses_Typedef;

void fill(Expenses_Typedef* p_structure, int NumToFill);
void show(const Expenses_Typedef* p_structure, int NumToShow);

int main()
{
	Expenses_Typedef Expenses_structure;

	fill(&Expenses_structure, Seasons);
	show(&Expenses_structure, Seasons);
	// std::cin.get();
	// std::cin.get();
	return 0;
}

void fill(Expenses_Typedef* p_structure, int NumToFill)
{
	for (int i = 0; i < NumToFill; i++)
	{
		std::cout << "Enter " << Snames[i] << " expenses: ";
		std::cin >> p_structure->expenses[i];
	}
}

void show(const Expenses_Typedef* p_structure, int NumToShow)
{
	double total = 0.0;
	std::cout << "\nEXPENSES\n";

	for (int i = 0; i < NumToShow; i++)
	{
		std::cout << Snames[i] << ": $" << *(p_structure->expenses+i) << '\n';
		total += * (p_structure->expenses + i);
	}
	//***注***
	/*
	p_structure->expenses[0] = 0;
	*/
	//此语句不被允许，因为把Expenses_Typedef布局的结构变量声明为了const
	//即结构变量中的值都不可以改变
	std::cout << "Total: $" << total << '\n';
}
#endif


//9.
#if 0
#include <cstring>//strlen()，memcpy()
using namespace std;

const int SLEN = 30;

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(struct student *p_structure,int num);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[],int n);

int main(void)
{
	cout << "Enter class size : ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];

	int entered = getinfo(ptr_stu,class_size);
	cout << "\n学生信息如下\n";
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu,entered);

	delete[]ptr_stu;
	cout << "Done !\n";

	return 0;
}
int getinfo(struct student* p_structure, int num)
{
	int count = 0;
	char temp[SLEN];

	for (int i = 0; i < num; i++)
	{
		cout << "请填充第"<<i+1<<"个结构——"<<endl;
		cout << "请输入学生全名(按Enter以结束输入)：";
		cin.getline(temp,SLEN);
		if (temp[0] == '\0')
			break;
		else
			memcpy((p_structure + i)->fullname,temp,strlen(temp)*sizeof(char)+1);
		//***注***
		//若上述语句写为strlen(temp)*sizeof(char) 则无法拷贝空字符，造成后续打印的有意义的内容的后面是乱码
		cout << "请输入该学生的兴趣爱好：";
		cin.getline((p_structure + i)->hobby, SLEN);
		cout << "请输入该学生的面向对象编程的熟练等级：";
		while (!(cin >> (p_structure + i)->ooplevel))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "请输入整数数字！"<<endl;			
		}
		cin.get();

		count++;
	}

	return count;
}
void display1(student st)
{
	cout << "学生姓名："<<st.fullname<<endl;
	cout << "学生的爱好："<<st.hobby<<endl;
	cout << "学生的面向对象编程的熟练等级："<<st.ooplevel<<endl<<endl;
}
void display2(const student* ps)
{
	cout << "学生姓名：" << ps->fullname << endl;
	cout << "学生的爱好：" << ps->hobby << endl;
	cout << "学生的面向对象编程的熟练等级：" << ps->ooplevel << endl << endl;
}
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{	
		cout << "学生姓名：" << (pa+i)->fullname << endl;
		cout << "学生的爱好：" << (pa+i)->hobby << endl;
		cout << "学生的面向对象编程的熟练等级：" << (pa+i)->ooplevel << endl << endl;
	}
}
#endif


//10.
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x,double y);
int main(void)
{
	using namespace std;

	double result;

	cout << "请输入两个数字：";
	double a, b;
	while (cin >> a >> b)
	{
		result = calculate(a, b, add);
		cout <<a<<"+"<<b<< "结果为" << result << endl;

		result = calculate(a, b, sub);
		cout << a << "-" << b << "结果为" << result << endl;

		cout << "请输入两个数字(输入非数字以退出程序)：";
	}

	return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
	double result;

	result = p_fun(x,y);

	return result;
}

double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
#endif


//10.使用函数指针数组
#if 0
double calculate(double, double, double (*p_fun)(double, double));

double add(double x, double y);
double sub(double x, double y);
double mul(double,double);

int main(void)
{
	using namespace std;

	double (*pf[3])(double, double) = {add,sub,mul};//创建并初始化一个函数指针数组
	const char* p_string[3] = {"+","-","*"};

	double result;

	cout << "请输入两个数字：";
	double a, b;
	while (cin >> a >> b)
	{
		for (int i = 0; i < 3; i++)
		{
			result = calculate(a, b, pf[i]);
			cout << a << p_string[i] << b << "结果为" << result << endl;
		}
		cout << "请输入两个数字(输入非数字以退出程序)：";
	}

	return 0;
}
double calculate(double x, double y, double (*p_fun)(double, double))
{
	double result;

	result = p_fun(x, y);

	return result;
}

double add(double x, double y)
{
	return x + y;
}
double sub(double x, double y)
{
	return x - y;
}
double mul(double x, double y)
{
	return x * y;
}
#endif