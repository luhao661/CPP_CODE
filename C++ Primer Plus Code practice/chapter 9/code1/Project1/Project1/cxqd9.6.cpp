#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include <iostream>
extern int tom;         // tom defined elsewhere
static int dick = 10;   // overrides external dick 
                                   //定义式声明并初始化一个内部链接的静态变量
                                   //***注1***这样写可以隐藏外部链接的静态变量
                                   //***注2***不能写成int dick=10;

int harry = 200;        // external variable definition,
                                  // no conflict with twofile1 harry

void remote_access()
{
    using namespace std;

    cout << "remote_access() reports the following addresses:\n";
    cout << &tom << " = &tom, " << &dick << " = &dick, ";
    cout << &harry << " = &harry\n";
}
#endif