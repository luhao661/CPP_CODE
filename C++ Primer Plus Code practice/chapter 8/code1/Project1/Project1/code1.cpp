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
    //宏不能按值传递，而是通过文本替换实现功能
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
                                        //创建指向rats的引用变量rodents
                                        //rodents作为rats变量的别名，两者都指向同一个值和内存单元
                                        //int &   :指向int类型变量的引用
    cout << "rats = " << rats;
    cout << ", rodents = " << rodents << endl;
    rodents++;//递增的不是地址值，而是rats的值
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
#if 0
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


//程序清单8.4 比较传递函数参数的三种方法
//1.按值传递，2.按指针传递，3.按引用传递
#if 0
void swapv(int a, int b);       // a, b are new variables
void swapp(int* p, int* q);   // p, q are addresses of ints
void swapr(int& a, int& b);   // a, b are aliases for ints

int main()
{
    using namespace std;
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Trying to use passing by value:\n";
    swapv(wallet1, wallet2);   // pass values of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using pointers to swap contents again:\n";
    swapp(&wallet1, &wallet2); // pass addresses of variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    cout << "Using references to swap contents:\n";
    swapr(wallet1, wallet2);   // pass variables
    cout << "wallet1 = $" << wallet1;
    cout << " wallet2 = $" << wallet2 << endl;

    // cin.get();
    return 0;
}

void swapv(int a, int b)        // try using values
{
    int temp;

    temp = a;      // use a, b for values of variables
    a = b;
    b = temp;
}

void swapp(int* p, int* q)    // use pointers
{
    int temp;

    temp = *p;      // use *p, *q for values of variables
    *p = *q;
    *q = temp;
}

void swapr(int& a, int& b)    // use references
{
    int temp;

    temp = a;       // use a, b for values of variables
    a = b;
    b = temp;
}
#endif


//程序清单8.5 声明时引用不带const和带const，对于实参有问题时的不同反应
#if 0
double cube(double a);
double refcube(double& ra);
double refcude_1(const double & ra);

int main()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;

    cout << refcube(x);
    //***注***若写成refcude(3)，则会报错：非常量引用的初始值必须是左值
    //因为字面量3，属于非左值，而且引用变量没有设为const，所以C++不会创建临时变量，而是直接报错
    cout << " = cube of " << x << endl;

    int a = 3;
    cout << refcude_1(a);
    cout << " = cube of " << a << endl;
    //***注***若函数声明时对引用不加const，则会报错：无法用int类型的值初始化double&类型的引用(非常量限定)

    // cin.get();
    return 0;
}

double cube(double a)           // x=3.0传入，返回值27.0传出
{
    a *= a * a;
    return a;
}

double refcube(double& ra)  // ra是x的别名，函数修改了x，x的值变为27.0
{
    ra *= ra * ra;
    return ra;
}                                               //***注***若想使用引用，但不对这些信息修改，则应该使用常量引用
                                                //double refcube(const double& ra)

double refcude_1(const double& ra)
{
    return ra * ra * ra;
}                                               //***注***由于实参传的是3，所以C++会创建一个匿名临时变量
#endif                        


//程序清单8.6 将引用用于结构
//返回引用和按值返回的不同之处
#if 0
#include <string>
struct free_throws
{
    std::string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
//返回值：指向结构的引用
free_throws &accumulate(free_throws& target, const free_throws& source);

int main()
{
    free_throws one = { "Ifelsa Branch", 13, 14 };
    free_throws two = { "Andor Knott", 10, 16 };
    free_throws three = { "Minnie Max", 7, 9 };
    free_throws four = { "Whily Looper", 5, 9 };
    free_throws five = { "Long Long", 6, 14 };
    free_throws team = { "Throwgoods", 0, 0 };
    free_throws dup;

    set_pc(one);
    display(one);
    accumulate(team, one);
    display(team);

    // use return value as argument 使用返回值作为参数
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    //***注***
    //函数的返回值必须是引用，若函数是按值返回，则后续的程序无法访问返回的值，此语句不能通过编译
    //而且按值返回的值(是临时值)不能作为赋值表达式语句的左值，只能作为右值
    display(team);

    // use return value in assignment 使用返回值作为赋值表达式的右值
    dup = accumulate(team, five);
    std::cout << "Displaying team:\n";
    display(team);
    std::cout << "Displaying dup after assignment:\n";
    display(dup);

    set_pc(four);
    // ill-advised assignment
    accumulate(dup, five) = four;
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
    // std::cin.get();
    return 0;
}

void set_pc(free_throws& ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    else
        ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}

void display(const free_throws& ft)
{
    using std::cout;
    cout << "Name: " << ft.name << '\n';
    cout << "  Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << '\n';
}
#endif


//程序清单8.7将引用用于类对象
#if 0
#include <string>
using namespace std;

string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);  // has side effect
const string& version3(string& s1, const string& s2);  // bad design

int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);

    copy = input;

    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;
    result = version3(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
    // cin.get();
    // cin.get();
    return 0;
}

string version1(const string& s1, const string& s2)//***注***虽然实参是string和const *char，但由于const引用的特性，程序将创建一个正确类型的临时变量，s2是指向该临时变量的引用
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
    //***注***
    //不能返回指向temp的引用，因为temp是个自动变量，该函数执行完毕后，它将不再存在
}   //此处temp被复制到一个临时位置，主调函数的result可以访问这个临时位置

const string& version2(string& s1, const string& s2)   // has side effect
{
    s1 = s2 + s1 + s2;
    // safe to return reference passed to function
    return s1;
}

const string& version3(string& s1, const string& s2)   // bad design
{
    string temp;

    temp = s2 + s1 + s2;
    // unsafe to return reference to local variable
    return temp;
    //***注***
    //不能返回指向temp的引用，因为temp是个自动变量，该函数执行完毕后，它将不再存在
}   //对比version1()函数
#endif


//程序清单8.8 基类引用可以指向基类或派生类对象，而无需进行强制类型转换
#if 0
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);//形参：指向ostream对象的引用
const int LIMIT = 5;

int main()
{
    ofstream fout;//以输出方式打开文件，用于写文件
    const char* filename = "ep-data.txt";

    fout.open(filename);

    if (!fout.is_open())
    {
        cout << "Can't open " << filename << ". Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
        "telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
        << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++)
    {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);//向文件写入数据
    file_it(cout, objective, eps, LIMIT);//在显示屏上显示数据
    cout << "Done\n";
    // cin.get();
    // cin.get();
    return 0;
}

//形参：指向ostream对象的引用，物镜焦距fo，指向目镜焦距数组首元素的指针，数组长度
//***注***
//os可以指向ostream对象，也可以指向ofstream对象
void file_it(ostream& os, double fo, const double fe[], int n)
{
    ios_base::fmtflags initial;
    //fmtflags：存储格式化信息的数据类型
    //声明一个fmtflags类型的变量initial
    initial = os.setf(ios_base::fixed, ios_base::floatfield);
    //initial用来保存最初的格式化状态

    std::streamsize sz = os.precision(0);

    os << "Focal length of objective: " << fo << " mm\n";
    os.precision(1);
    os.width(12);//此设置仅在显示下一个值时有效
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for (int i = 0; i < n; i++)
    {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }

    os.setf(initial);
    // restore initial formatting state 将所有的格式化设置恢复到原来的值
    //方法setf()返回调用它之前有效的所有格式化设置(被存储在initial中)
    os.precision(sz);
}
#endif


//程序清单8.9 使用默认参数
#if 0
const int ArSize = 80;

char* left(const char* str, int n = 1);//n的默认值是1

int main()
{
    using namespace std;

    char sample[ArSize];
    cout << "Enter a string:\n";
    cin.get(sample, ArSize);

    char* ps = left(sample, 4);
    cout << ps << endl;
    delete[] ps;       // free old string

    ps = left(sample);
    cout << ps << endl;
    delete[] ps;       // free new string
    // cin.get();
    // cin.get();
    return 0;
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;
    char* p = new char[n + 1];//利用动态内存分配，使创建的数组在被调函数结束时仍存在

    //法二：
    /*
    int len = strlen(str);
    n = (n < len) ? n:len;

    char* p = new char[n + 1];
    */
    //法三：
    /*
    int m=0;
    while(m<n&&str[m])
    m++;

    char* p = new char[n + 1];
    */

    int i;
    for (i = 0;         i < n && str[i];         i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;//指针p属于自动变量，在返回给主调函数其所存的地址值后，p将不再存在
}
#endif


//程序清单8.10 使用函数重载
#if 0
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main()
{
    using namespace std;
    unsigned long n = 12345678; // test value
    const char* trip = "Hawaii!!";   // test value

    char* temp;

    for (int i = 1; i < 10; i++)
    {
        cout << left(n, i) << endl;

        temp = left(trip, i);
        cout << temp << endl;
        delete[] temp; // point to temporary storage
    }
    // cin.get();
    return 0;
}

// This function returns the first ct digits of the number num.
unsigned long left(unsigned long num, unsigned ct)
{
    unsigned digits = 1;
    unsigned long n = num;

    if (ct == 0 || num == 0)
        return 0;       // return 0 if no digits

    while (n /= 10)
        digits++;   //计算数字num有几位

    if (digits > ct)//若位数大于要保留的位数(从高位到低位保留)
    {
        ct = digits - ct;//计算要删除几位(从低位向高位删除)

        while (ct--)
            num /= 10;
        return num;         // return left ct digits
    }
    else //若位数小于或等于要保留的位数(从高位到低位保留)
        return num;     // return the whole number
}

// This function returns a pointer to a new string
// consisting of the first n characters in the str string.
char* left(const char* str, int n)
{
    if (n < 0)
        n = 0;

    char* p = new char[n + 1];

    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];  // copy characters

    while (i <= n)
        p[i++] = '\0';  // set rest of string to '\0'

    return p;
}
#endif


//程序清单8.11 使用函数模板
#if 0
// function template prototype 声明一个函数模板
template <typename T>  // or class T 或使用关键字class   将类型命名为T
void Swap(T& a, T& b);     

int main()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);  // generates void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "x, y = " << x << ", " << y << ".\n";
    cout << "Using compiler-generated double swapper:\n";
    Swap(x, y);  // generates void Swap(double &, double &)
    cout << "Now x, y = " << x << ", " << y << ".\n";
    // cin.get();
    return 0;
}

// function template definition 定义函数模板
template <typename T>  // or class T
void Swap(T& a, T& b)
{
    T temp;   // temp a variable of type T 创建一个T类型的变量temp
    temp = a;
    a = b;
    b = temp;
}
#endif


//程序清单8.12 使用重载的模板
#if 0
template <typename T>     // original template
void Swap(T& a, T& b);

template <typename T>     // new template
void Swap(T* a, T* b, int n);

const int Lim = 8;
void Show(int a[]);

int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);              // matches original template
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = { 0,7,0,4,1,7,7,6 };
    int d2[Lim] = { 0,7,2,0,1,9,6,9 };
    cout << "Original arrays:\n";
    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);        // matches new template
    cout << "Swapped arrays:\n";
    Show(d1);
    Show(d2);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[])
{
    using namespace std;
    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];
    cout << endl;
}
#endif


//程序清单8.13 使用显式具体化
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//声明一个常规模板，将类型命名为T
void Swap(T& a, T& b);

// explicit specialization 
template <> void Swap<job>(job& j1, job& j2);
//显式具体化
//不使用Swap()模板来生成函数定义，而使用专门为job类型显式地定义的函数定义
//或写成：
//template <> void Swap<>(job& j1, job& j2);
//template <> void Swap(job& j1, job& j2);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);    //隐式实例化，生成 void Swap(int &, int &)
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = { "Susan Yaffee", 73000.60, 7 };
    job sidney = { "Sidney Taffee", 78060.72, 9 };
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);

    cout << "After job swapping:\n";
    Swap(sue, sidney); // uses void Swap(job &, job &)
    Show(sue);
    Show(sidney);
    // cin.get();
    return 0;
}

template <typename T>
void Swap(T& a, T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structure
template <> void Swap<job>(job& j1, job& j2)  // specialization
//写法二：
//template <> void Swap<>(job& j1, job& j2)  // specialization
//写法三：
//template <> void Swap(job& j1, job& j2)  // specialization
{
    double t1;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;

    int t2;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif
//程序清单8.13 改：
//调用函数时来创建显式实例化需要注意的点
#if 0
struct job
{
    char name[40];
    double salary;
    int floor;
};

template <typename T>//声明一个常规模板，将类型命名为T
void Swap( T& a,  T& b);

void Show(job& j);

int main()
{
    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10;
    double j = 20.2;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap<double>(i, j);    //显式实例化，根据模板，生成 void Swap(double &, double &)
    //***注***
    //虽然传入函数的都是double类型的值，但是主调函数中的 i 仍是int类型，所以不能产生指向int类型的 i 的引用
    cout << "Now i, j = " << i << ", " << j << ".\n";

   // cin.get();
    return 0;
}

template <typename T>
void Swap(const T& a, const T& b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;

    return;
}

 void Show(job& j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
#endif



//使用显式实例化
//法一：声明时创建显式实例化
#if 0
template <typename T>
T add(T a,T b);

template double add<double>(double, double);//使用add()模板生成一个使用double类型的实例(函数定义)

int main(void)
{
    using namespace std;

    double m = 6;
    double n = 10.2;

    cout << add(m, n) << endl;

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif
//法二：调用函数时来创建显式实例化
#if 0
template <typename T>
T add(T a, T b);

int main(void)
{
    using namespace std;

    int m = 6;
    double n = 10.2;

    cout <<add<double>(m,n)<<endl;//显示实例化，使用add()模板生成一个使用double类型的实例

    return 0;
}

template <typename T>
T add(T a, T b)
{
    return a + b;
}
#endif


//程序清单8.14 重载解析，演示部分排序规则
#if 0
template <typename T>            // template A 假设实参是数组名称，即指向数组首元素的指针
void ShowArray(T arr[], int n);

template <typename T>            // template B 假设实参是指向一个指针数组首元素的指针
//void ShowArray(T* arr[], int n);
//写法二：
void ShowArray(T** arr, int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
//************************************************************************
    int things[6] = { 13, 31, 103, 301, 310, 130 };
    cout << "Listing Mr. E's counts of things:\n";
    // things is an array of int
    ShowArray(things, 6);  // uses template A
//************************************************************************

    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };

    double* pd[3];//声明一个指针数组
    // set pointers to the amount members of the structures in mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;//对指针数组的每个元素(即每个指针)赋值，赋的是结构的成员amount的地址

    cout << "Listing Mr. E's debts:\n";
    // pd is an array of pointers to double
    ShowArray(pd, 3);      // uses template B (more specialized)
//************************************************************************

    // cin.get();
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;

    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << endl;
}

template <typename T>
void ShowArray(T** arr, int n)
{
    using namespace std;

    cout << "template B\n";
    for (int i = 0; i < n; i++)
        /*cout << *arr[i] << ' ';*/cout<<**(arr+i)<<' ';
    cout << endl;
}
#endif


//程序清单8.15 编写合适的函数调用，指示编译器使用用户所希望的函数或模板函数
#if 0
template<class T>
T lesser(T a, T b)         // #1
{
    return a < b ? a : b;
}

int lesser(int a, int b)  // #2
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a < b ? a : b;
}

int main()
{
    using namespace std;

    int m = 20;
    int n = -30;
    double x = 15.5;
    double y = 25.9;

    cout << lesser(m, n) << endl;       // use #2
    cout << lesser(x, y) << endl;       // use #1 with double
    cout << lesser<>(m, n) << endl;     // use #1 with int
    cout << lesser<int>(x, y) << endl; // use #1 with int

    // cin.get();
    return 0;
}
#endif


//C++11的关键字decltype 用于确定形参进行运算后得到的值的类型，以及确定函数的返回值的类型
#if 0
template <typename T1, typename T2>
auto add(T1 x,T2 y)->decltype(x+y);// ->decltype(x+y) 说明返回类型是x+y运算后的值的类型

int main(void)
{
    using namespace std;

    int a = 1;
    double b = 2.2;
    cout << add(a, b) << endl;

    return 0;
}
/*
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    decltype(x + y) sum = x + y;

    return sum;
}
*/
//也可以使用typedef，给类型增加一个方便使用的标签(取个别名)
template <typename T1, typename T2>
auto add(T1 x, T2 y)->decltype(x + y)
{
    typedef decltype(x + y)  LeiXin;
    LeiXin sum = x + y;

    return sum;
}
#endif
