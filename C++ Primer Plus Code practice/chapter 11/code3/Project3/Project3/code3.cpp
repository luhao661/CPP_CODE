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


//11.9.5.
//链接11.9.5.cpp
#if 1
#include "11.9.5.h"
using std::cout;

void display(const Stonewt& st, int n);

int main()
{
    //初始化写法一：
    //显式调用构造函数，也叫显式强制类型转换
    //Stonewt p1 = Stonewt (275); // uses constructor to initialize

    //初始化写法二：
    //隐式调用构造函数 
    //Stonewt p1(275);

    //初始化写法三：
    //自动类型转换，也叫隐式类型转换
    //使用构造函数作为转换函数，首先将275转换为275.0，
    //然后使用Stonewt(double pds)构造函数来初始化对象p1
    //将int类型的值转化为Stonewt类型
    Stonewt p1 = 275; // uses constructor to initialize

    //赋值写法：
    //Stonewt p1;
    //p1 = 275;

    Stonewt p2(285.7);    // same as Stonewt wolfe = 285.7;

    //此处理解：C++自动将传递的值转换为原型中指定的类型，
    //条件是两者都是算术类型(引用除外)
    //8被自动转换成8.0后再传入构造函数
    Stonewt p3(21, 8);

    cout << "The p1 weighed ";
    p1.show_stn();
    cout << "The p2 weighed ";
    p2.show_stn();
    cout << "The p3 weighed ";
    p3.show_pds();

    p1 = 276.8;          // uses constructor for conversion
    p3 = 325;             // same as p3 = Stonewt(325);

    cout << "After dinner, the p1 weighed ";
    p1.show_stn();

    cout << "After dinner, the p3 weighed ";
    p3.show_pds();

    display(p3, 2);

    cout << "The wrestler weighed even more.\n";
    //***注***
    //422转换为422.0，然后使用Stonewt(double pds)构造函数
    //生成一个临时Stonewt对象，传入display()
    display(422, 2);

    //cout << "No stone left unearned\n";//没有什么是不劳而获的
    // std::cin.get();
    return 0;
}

void display(const Stonewt& st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}
#endif