#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//程序清单8.1 C++通常用内联函数代替C语言的类函数宏
#if 0
// an inline function definition
inline double square(double x) { return x * x; }//内联函数一般把函数原型省略，将整个定义放在头文件中

int main()
{
    using namespace std;
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);   // can pass expressions

    cout << "a = " << a << ", b = " << b << "\n";
    cout << "c = " << c;
    cout << ", c squared = " << square(c++) << "\n";
    //***注***
    //此语句末尾是个顺序点，C++只能保证此语句后面，c的值会增加1
   //传入square()的是递增前的c的值
    //宏不能按值传递，是通过文本替换实现功能
    //内联函数能按值传递
    cout << "Now c = " << c << "\n";

    // cin.get();
    return 0;
}
#endif


//程序清单8.2 创建引用变量
#if 0
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   // rodents is a reference
                                        //创建指向rats的引用
                                        //rodents作为rats变量的别名，两者都指向同一个值和内存单元
                                        //int &   :指向int变量的引用
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    // some implementations require type casting the following
    // addresses to type unsigned
    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单8.3 引用一旦在声明时被初始化后，就一直绑定了该变量
#if 1
int main()
{
    using namespace std;
    int rats = 101;
    int& rodents = rats;   //声明并初始化引用，rodents引用rats

    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "rats address = " << &rats;
    cout << ", rodents address = " << &rodents << endl;

    int bunnies = 50;
    rodents = bunnies;       // can we change the reference?
                                           //可以改变rodents引用的变量吗？
    cout << "bunnies = " << bunnies;
    cout << ", rats = " << rats;
    cout << ", rodents = " << rodents << endl;

    cout << "bunnies address = " << &bunnies;
    cout << ", rodents address = " << &rodents << endl;//rodents的地址仍与rats的地址相同
    // cin.get();
    return 0;
}
#endif
