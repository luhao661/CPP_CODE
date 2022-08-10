#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>//STL vector类
#include <array>//STL array类
#include <string>//string类
//
#if 1
#endif


//4.12复习题
//1.
#if 0
int main(void)
{
	char actor[30];
	short betsie[100];
	float chuck[13];
	long double dipsea[64];

	return 0;
}
#endif


//2.
#if 0
int main(void)
{
	using namespace std;

	array<char, 30>actor;
	array<short, 100>betsie;
	array<float, 13>chuck;
	array<long double, 64>dipsea;

	return 0;
}
#endif


//3.
#if 0
int main(void)
{
	int shuju[5] = {1,3,5,7,9};

	return 0;
}
#endif


//4.
#if 0
int main(void)
{
	int shuju[5] = { 1,3,5,7,9 };
	int even;
	even = shuju[0] + shuju[4];
	//或：even = *(shuju)+ *(shuju+4);

	return 0;
}
#endif


//5.~7.
#if 0
int main(void)
{
	float ideas[10]{1,2};
	std::cout << ideas[1];

	char shuju[20]="cheeseburger";
	std::string str = "Waldorf Salad";
	
	return 0;
}
#endif


//8.~9.
#if 0
struct fish
{
	char pinzhong[20];
	int weight;
	double length;
};

int main(void)
{
	struct fish fish_canshu = {"鲈鱼",1,2.2};

	return 0;
}
#endif


//10.
#if 0
enum Response {No,Yes,Maybe};
#endif


//11.
#if 0
int main(void)
{
	double ted=1.1;
	double* p = &ted;

	std::cout << *p;

	return 0;
}
#endif


//12.
#if 0
int main(void)
{
	float treacle[10] = {1.0,2.0,3.0};
	treacle[9] = 10.0;

	float* p = treacle;

	std::cout << *(p) << std::endl;
	std::cout << *(p+9) << std::endl;

	return 0;
}
#endif


//13.
#if 1
int main(void)
{
	using namespace std;
	cout << "请输入要写入的整数数量：";
	int num;
	cin >> num;

	int* p = new int[num];
	//或：
	//vector<int>p(num);

	delete[]p;

	return 0;
}
#endif


//15.
#if 0
struct fish
{
	char pinzhong[20];
	int weight;
	double length;
};

int main(void)
{
	using namespace std;

	struct fish fish_canshu = { "鲈鱼",1,2.2 };
	//struct fish* p1 = &fish_canshu;

	struct fish* p = new fish;
	//或：fish* p = new fish;
	cin >> p->pinzhong ;
	cin >> p->weight ;
	cin >> p->length ;

	cout<< p->pinzhong<<endl;
	cout<< p->weight<<endl;
	cout<< p->length<<endl;

	return 0;
}
#endif


//17.
#if 0
int main(void)
{
	const int num = 10;//理解成	#define		num		 (10)
	std::vector<std::string>a_array(num);
	std::array<std::string,num>b_array;

	return 0;
}
#endif
