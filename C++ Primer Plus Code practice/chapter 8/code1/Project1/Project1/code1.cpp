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


//程序清单8.8 
#if 1
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream& os, double fo, const double fe[], int n);//形参：指向ostream对象的引用
const int LIMIT = 5;

int main()
{
    ofstream fout;
    const char* fn = "ep-data.txt";

    fout.open(fn);

    if (!fout.is_open())
    {
        cout << "Can't open " << fn << ". Bye.\n";
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

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";
    // cin.get();
    // cin.get();
    return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
    // save initial formatting state
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize sz = os.precision(0);

    os << "Focal length of objective: " << fo << " mm\n";
    os.precision(1);
    os.width(12);
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
    // restore initial formatting state
    os.setf(initial, ios_base::floatfield);
    os.precision(sz);
}
#endif