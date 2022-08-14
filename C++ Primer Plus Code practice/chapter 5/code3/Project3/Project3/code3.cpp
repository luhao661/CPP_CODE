#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <array>
#include <string>
#include <cstring>//strcmp()
//
#if 1
#endif


//5.9编程练习
//1.
#if 0
int main(void)
{
	using namespace std;
	cout << "请输入两个整数：";
	
	int start, end;
	cin >> start;
	cin >> end;

	int sum = 0;
	for (int i = start; i <= end; i++)
		sum += i;

	cout << start << "~" << end << "之间所有整数的和为" << sum;

	return 0;
}
#endif


//2.
#if 0
const int ArSize = 100;      // example of external declaration

int main()
{
	std::array<long double, ArSize>factorials;

	factorials[1] = factorials[0] = 1.0L;//0!=1，1!=1

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;
	// std::cin.get();
	return 0;
}
#endif


//3.
#if 0
int main(void)
{
	using namespace std;

	cout << "请输入数字：";
	int num,sum=0;
	
	while (1)
	{
		cin >> num;
		sum += num;
		
		if (num != 0)
		{
			cout << "所有输入的累计和为" << sum << endl;
			cout << "请输入数字：";
		}
		else
			break;
	}
	//法二：
	/*do
	{
		cin >> num;
		sum += sum;
	} while (num!=0);
	cout << "所有输入的累计和为" << sum << endl;*/
	return 0;
}
#endif


//4.
#if 0
//#define JUST_CHECKING
int main(void)
{
	using namespace std;

	double benjin_dap = 100.0, benjin_cle = 100.0;
	const double lilv_dap = 0.1;
	const double lilv_cle = 0.05;

	double lixi_dap, lixi_cle;

	double money_dap = benjin_dap ;
	double money_cle= benjin_cle;
	int years=0;

	do
	{
		years++;

		lixi_dap = lilv_dap * benjin_dap;
		money_dap += lixi_dap;

#ifdef JUST_CHECKING//条件编译
		cout << "第" << years << "年：" << "Daphne " << money_dap<<"\t";
#endif

		lixi_cle = lilv_cle * money_cle;
		money_cle += lixi_cle;
#ifdef JUST_CHECKING
		cout << "第" << years << "年：" << "Cleo " << money_cle<<endl;
#endif

	} while (money_cle<= money_dap);

	cout << "第" << years << "年：" << "Daphne " << money_dap << "\t";
	cout << "Cleo " << money_cle << endl;

	return 0;
}
#endif


//5.
#if 0
int main(void)
{
	using namespace std;

	int xiaoshouliang[12];
	//错误：“const char *“ 类型的值不能用于初始化 “char *“ 类型的实体
	//char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	//***注***正确写法：
	const char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	//写法二：
	//const string yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };

	int sum = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << "请输入" << yuefen[i] << "的销售量：";
		cin >> xiaoshouliang[i];
		sum += xiaoshouliang[i];
	}

	cout << "这一年销售量为" << sum<<"本"<<endl;
	
	return 0;
}
#endif


//6.
#if 0
int main(void)
{
	using namespace std;

	int xiaoshouliang[3][12];
	//错误：“const char *“ 类型的值不能用于初始化 “char *“ 类型的实体
	//char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	//***注***正确写法：
	const char* nianfen[3] = { "1999年","2000年","2001年" };
	const char* yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	//写法二：
	//const string yuefen[12] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };

	int sum[3 + 1] = {};
	int i, j;
	
	for ( i = 0; i < 3; i++)
	{
		cout << nianfen[i] << "：" << endl;

		for ( j = 0; j < 12; j++)
		{
			cout << "请输入" << yuefen[j] << "的销售量：";
			cin >> xiaoshouliang[i][j];
			sum[i] += xiaoshouliang[i][j];
		}
	}

	cout.put('\n');
	for (int i = 0;i < 3; i++)
	{
		cout << nianfen[i] << "销售量为" << sum[i] << "本" << endl;
		sum[3] += sum[i];
	}
	cout << "总销售量为" << sum[3] << "本" << endl;

	return 0;
}
#endif


//7.
#if 0
struct car
{
	std::string manufacturer;
	int year;
};

int main(void)
{
	using namespace std;

	cout << "How many cars do you wish to catalog ?";
	int num;
	cin >> num;
	cin.get();//消耗掉换行符

	struct car* p_car = new car[num];

	for (int i = 0; i < num; i++)
	{
		cout << "Car #" << i +1<< "：" << endl;
		cout << "Please enter the make :";
		getline(cin, (p_car+i)->manufacturer);
		cout << "Please enter the year made :";
		cin >> (p_car + i)->year;
		cin.get();
	}

	if (num != 0)
	{
		cout << "Here is your collection :"<<endl;
			for (int i = 0; i < num; i++)
			{
				cout<< (p_car + i)->year<<" ";
				cout << (p_car + i)->manufacturer<<endl;
			}
	}
	else
		cout << "No data entered !";

	delete[]p_car;

	return 0;
}
#endif


//8.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter words (to stop, type the word done) :"<<endl;
	char shuju[20];
	int count = 0;

	/*do
	{
		cin >> shuju;
		++count;
	} while (strcmp(shuju, "done"));
	count -= 1;*/

	/*shuju[0] =0;
	for (; strcmp(shuju, "done"); ++count)
	{
		cin >> shuju;
	}
	count -= 1;*/

	while (1)
	{
		cin >> shuju;
		if (strcmp(shuju, "done"))
			++count;
		else
			break;
	}

	cout << "You entered a total of "<<count<<" words";

	return 0;
}
#endif


//9.
#if 0
int main(void)
{
	using namespace std;
	cout << "Enter words (to stop, type the word done) :" << endl;
	string shuju;
	int count = 0;	

	while (1)
	{
		cin >> shuju;
		if (shuju!= "done")
			++count;
		else
			break;
	}

	cout << "You entered a total of " << count << " words";

	return 0;
}
#endif


//10.
#if 0
int main(void)
{
	using namespace std;

	cout<<"Enter number of rows : ";
	int num;
	cin >> num;//***注***在输入缓冲区中还有'\n'

	int i, j,k;
	for (i = 1; i <= num; i++)//行号
	{
		for (j = 1; j <= num - i; j++)
			cout << ". ";
		for (k = 1; k <= i; k++)
			cout << "* ";
		cout << endl;
	}
	return 0;
}
#endif