#define _CRT_SECURE_NO_WARNINGS 1
//
#if 1
#endif


//程序清单2.1 初见C++程序
//法一：使用std::前缀
#if 0
#include <iostream>
int main()
{
	std::cout << "感受一下C++程序。";
	std::cout << std::endl;
	std::cout << "你不会后悔的！" << std::endl;

	return 0;
}
#endif
//法二：使用using编译指令
#if 0
#include <iostream>
int main()
{
	using namespace std;//名称空间编译指令		声明std名称空间中的所有名称都可用
	cout << "感受一下C++程序。";
	cout << endl;
	cout << "你不会后悔的！" << endl;

	return 0;
}
#endif
//法二(改进)：使用using编译指令
#if 0
#include <iostream>//C++风格的头文件，包含名称空间std，定义着cout,endl
int main()
{
	using std::cout;//using声明只使所需的名称可用		使用名称空间std中的预定义对象cout，cout表示输出流，读为 "c out"即标准输出
	using std::endl;//使用名称空间std中的控制符endl

	cout << "感受一下C++程序。";
	cout << endl;
	cout << "你不会后悔的！" << endl;

	return 0;
}
#endif


//程序清单2.2 声明并使用变量，使用cout打印变量的值
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	carrots = 25;

	cout << "I have ";
	cout << carrots;
	cout << " carrots\n";

	carrots -= 1;
	cout << "吃了1根，现在我还有" << carrots << "根胡萝卜(carrots)" << endl;

	return 0;
}
#endif


//程序清单2.3 使用cin
#if 0
#include <iostream>
int main()
{
	using namespace std;

	int carrots;

	cout << "您有多少根胡萝卜？ ";
	cin>> carrots;
	//写法1：
	//cout << "吃了1根，现在我还有" << carrots-1 << "根胡萝卜(carrots)" << endl;
	//写法2：(适用于长代码行)
	cout << "吃了1根，现在我还有" 
			<< carrots - 1 
			<< "根胡萝卜(carrots)" 
			<< endl;

	return 0;
}
#endif


//程序清单2.4 调用C库中的函数
#if 0
#include <iostream>
#include <cmath>

int main (void)
{
	using namespace std;

	double area;
	cout << "请输入一个大于0的小数：";
	cin >> area;

	double side;
	side = sqrt(area);
	cout << "该数的算数平方根是";
	cout << side<< endl;

	return 0;
}
#endif


//程序清单2.5 调用用户自定义的函数(1)
#if 0
#include <iostream>
void function(int);
//或写为：
//using namespace std;//这样写的话，两个函数都能访问名称空间std

int main(void)
{
	using namespace std;

	function(3);

	cout << "请输入数字：";
	int n;										//***注***变量名不能和函数名相同，否则编译器不知道应该用变量还是该调用函数
	cin >> n;									//不能在同一个函数中同时将cout用作对象名和变量名，否则编译器也会糊涂
	function(n);
													//关键字(如int return等)不能做他用
	return 0;
}
void function(int n)
{
	using namespace std;

	cout << "显示：";
	cout << n<<endl;
}
#endif


//程序清单2.6 调用用户自定义的函数(2)
#if 0
#include <iostream>
int function(int);

int main(void)
{
	using namespace std;

	cout << "请输入数字：";
	int n;										
	cin >> n;									
	n=function(n);
	cout << "扩大2倍后，得到" << n << endl;

	return 0;
}
int function(int n)
{
	n *= 2;

	return n;//或：return n*=2;
}
#endif

