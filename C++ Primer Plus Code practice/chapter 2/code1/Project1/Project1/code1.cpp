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
#if 1
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