#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//11.9 编程练习
//1.
//链接11.9.1.cpp
#if 0
#include "11.9.1.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        cout << "Target Distance : " << target_distance
            << ", Step Size : " << step_size << endl;

        while (result.magval() < target_distance)
        {
            if (steps == 0)
                cout << "0 : (x,y) = (0,0)" << endl;

            steps++;
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
                                                 //所以临时对象赋给result对象后，result对象为RECT模式
            cout << steps << " : (x,y) = " << "(" << result.xval() << ","
                << result.yval() << ")" << endl;
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//2.
//链接11.9.2.cpp
#if 0
#include "11.9.2.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit): ";
    double target_distance;
    double step_size;
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        while (result.magval() < target_distance)
        {
            //设置向随机角度的方向行走
            direction = rand() % 360;

            //注，只写POL，编译器会报错
            //可写成VECTOR::Vector::POL, 或写成Vector::POL
            step.reset(step_size, direction, Vector::POL);

            result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                 //而构造函数的参数form的默认值为RECT
            steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
        }

        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;

        result.polar_mode();
        cout << " or\n" << result << endl;

        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;

        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}
#endif


//3.
//链接11.9.3.cpp
#if 0
#include "11.9.3.h"
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype

void show_average(double *,int );

int main()
{
    using namespace std;
    using VECTOR::Vector;//使用VECTOR名称空间的Vector类

    //记录每一步的矢量数据
    Vector step;
    //记录累计的矢量数据
    Vector result(0.0, 0.0, Vector::Mode(0));//***注***不能写成Vector result(0.0, 0.0,0); int类型不能自动转换为枚举类型

    /* 初始化种子 */
    srand(time(0));     // seed random-number generator 
    //声明方向变量
    double direction;
    //声明步数变量
    unsigned long steps = 0;

    cout << "请输入离目标的距离 (q to quit) :  ";
    double target_distance;
    double step_size;
    int num;
    double* p_data=(double *)0;//***注***此处必须先对指针初始化
                                                    //将指针设置为地址0    (书P335)
    while (cin >> target_distance)
    {
        cout << "请输入每一步的步长: ";
        if (!(cin >> step_size))
            break;

        cout << "请输入测试次数：";
        cin >> num;
        p_data = new double[num];//动态分配内存

        for (int i = 0; i < num; i++)
        {
            while (result.magval() < target_distance)
            {
                //设置向随机角度的方向行走
                direction = rand() % 360;

                //注，只写POL，编译器会报错
                //可写成VECTOR::Vector::POL, 或写成Vector::POL
                step.reset(step_size, direction, Vector::POL);

                result = result + step;//***注***由于运算符重载函数调用了构造函数，
                                                     //而构造函数的参数form的默认值为RECT
                steps++;                      //所以临时对象赋给result对象后，result对象为RECT模式
            }

            /*cout << "After " << steps << " steps, the subject "
                "has the following location:\n";
            cout << result << endl;

            result.polar_mode();
            cout << " or\n" << result << endl;*/

            *(p_data + i) = result.magval() / steps;
            cout << "Average outward distance per step = "
                << result.magval() / steps << endl<<endl;

            steps = 0;
            result.reset(0.0, 0.0);
        }

        show_average(p_data,num);
        cout << "Enter target distance (q to quit): ";
    }

    cout << "Bye!\n";

    delete[]p_data;
    /* keep window open
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cin.get();
    */
    return 0;
}

void show_average(double*p, int n)
{
    using std::cout;
    using std::endl;

    double min , max,sum=0.0;
    min = max = *p;

    for (int i = 0; i < n; i++)
    {
        *(p + i) > max ? max = *(p + i) : 1;
        *(p + i) < min ? min = *(p + i) : 1;
        sum += *(p+i);
    }

    cout.put('\n');
    cout << n << "次测试中：\n最高平均步数：" << max
        << "\n最低平均步数："<<min<<endl
        << n << "次测试的平均步数："<<sum/n<<endl<<endl;
}
#endif


//4.
//链接11.9.4.cpp
#if 0
#include "11.9.4.h"

int main()
{
    using std::cout;
    using std::endl;

    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;

    //使用重载运算符函数operator+()
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    //使用重载运算符函数operator*()
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;

    //使用ostream类的operator<<()重载运算符函数
    cout << "10.0 * Tosca: "
        //使用Time类的operator*()友元函数，
        //然后使用Time类的operator<<()友元函数
        << 10.0 * tosca
        //使用ostream类的operator<<()重载运算符函数
        << endl;

    return 0;
}
#endif


//5.
//链接11.9.5.cpp
#if 0
#include "11.9.5.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
    //使用默认构造函数
    Stonewt p0;
    cout << "The p0 weighed ";
    cout << p0;

    //使用构造函数的类型转换功能；form为FLOAT_POUNDS
    Stonewt p1 = 100.1; 
    cout << "The p1 weighed ";
    cout << p1;

    //使用构造函数的类型转换功能；form为INTEGER_POUNDS
    Stonewt p2(200.6,Stonewt::INTEGER_POUNDS);//使用作用域为类的明示常量
    cout << "The p2 weighed ";
    cout << p2;

    //使用构造函数第二个版本；form为STONE
    //此处理解：C++自动将传递的值转换为原型中指定的类型，
    //条件是两者都是算术类型(引用除外)
    //8被自动转换成8.0后再传入构造函数
    Stonewt p3(21, 8);
    cout << "The p3 weighed ";
    cout << p3;

    //使用构造函数的类型转换和赋值功能
    p1 = 150.8;          // uses constructor for conversion
    cout << "After the change the p1 weighed ";
    cout << p1;

    Stonewt temp;
    temp = p1 + p2;
    cout << "p1+p2=" << temp;

    temp = p2 - p1;
    cout << "p2-p1=" << temp;

    temp = - p1;
    cout << "-p1=" << temp;

    temp = p1 * 2;
    cout << "p1*2=" << temp;

    temp = 2 * p1;
    cout << "2*p1="<<temp;

    cout << "The wrestler weighed even more.\n";
    //***注***
    //422转换为422.0，然后使用Stonewt(double pds,Mode form= FLOAT_POUNDS)构造函数
    //生成一个临时Stonewt对象，传入display()
    display(422, 2);

    //若输入的模式不正确
    Stonewt p4(1.5,Stonewt::STONE);
    cout << p4;
    Stonewt p5(1,5,Stonewt::FLOAT_POUNDS);
    cout << p5;

    return 0;
}

void display(const Stonewt& st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        cout << st;
    }
    cout.put('\n');
}
#endif


//6.
//链接11.9.6.cpp
#if 0
#include "11.9.6.h"

void show_report(const Stonewt *p,int num);

int main()
{
    //声明一个Stonewt类型的数组，并初始化前三个对象
    Stonewt array[6]
    {
    1.1,(2.2),Stonewt(3.3)
    };

    std::cout << "请输入第4~6个对象的pounds的值：";
    for (int index = 3; index < 6; index++)
    {
        while (!(std::cin >> array[index]))
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "错误的输入内容！\n";
        }
    }

    show_report(array,6);

    return 0;
}

void show_report(const Stonewt* p, int num)
{
    using std::cout;
    using std::endl;

    Stonewt stone11(11,0);//即154pounds
    int count = 0;

    Stonewt min, max;
    min = max = *p;

    for (int i = 0; i < num; i++)
    {
        if (*(p + i) > max)
            max = *(p+i);
        if (*(p + i) < min)
            min = *(p+i);
        if (*(p + i) >= stone11)
            count++;
    }

    cout << "\n最小重量：" << min << endl
        <<"最大重量："<<max<<endl
        <<"大于或等于11英石的数量："<<count<<endl;
}
#endif


//7.
//链接11.9.7.cpp
#if 0
using namespace std;
#include "11.9.7.h"
int main()
{
    Complex a(3.0, 4.0);// initialize to(3,4i)
    Complex c;
    cout << "Enter a complex number (q to quit) : \n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is" << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done ! \n";
    return 0;
}
#endif