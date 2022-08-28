#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//
#if 1
#endif


//8.7复习题
//2.
#if 0
void song(const char *name="O.My Papa", int times = 1);
#endif


//3.
#if 0
void iquote(int num);
void iquote(double num);
void iquote(std::string str);
#endif


//4.
#if 0
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show(box& r_box)
{
	using namespace std;
	cout << r_box.maker << endl;
	cout << r_box.height << endl;
	cout << r_box.width << endl;
	cout << r_box.length << endl;
	cout << r_box.volume << endl;
}
void fill_volume(box& r_box)
{
	r_box.volume = r_box.length * r_box.width * r_box.height;
}
#endif


//5.
#if 0
#include <array>//array类
#include <string>//string类

const int Seasons = 4;

const std::array<std::string, Seasons> Snames =
{ "Spring", "Summer", "Fall", "Winter" };//声明一个const array对象，该对象包含4个string对象

void fill(std::array<double, Seasons>& );//形参：指向array对象的引用
void show(const std::array<double, Seasons>& );//形参：指向array对象的引用

int main()
{
    std::array<double, Seasons> expenses;//声明一个array对象，包含4个double类型的值

    fill(expenses);//***注***实参不是数组首元素的地址，而是整个数组
    show(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill(std::array<double, Seasons>& r_a)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >>r_a[i];
    }
}

void show(const std::array<double, Seasons> &r_a)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";

    for (int i = 0; i < Seasons; i++)
    {
        std::cout << Snames[i] << ": $" << r_a[i] << '\n';
        total += r_a[i];
    }

    std::cout << "Total: $" << total << '\n';
}
#endif


//6.
#if 0
double mass(double density,double volume=1.0);

//void repeat(int num=5, const char*);//报错：默认实参不在形参列表的结尾

int average(int,int);
double average(double, double);

char mangle(char );
const char* mangle(char*);
#endif


//7.
#if 0
template <typename T1,typename T2>
auto bigger(T1 t1, T2 t2)->decltype(t1 > t2 ? t1 : t2)
{
    return (t1 > t2 ? t1 : t2);
}
#endif


//8.
#if 0
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

template <typename T>
T mass(T density, T volume = 1.0);

template <>box& mass(box& b1, box& b2);

template <typename T>
T mass(T density, T volume = 1.0)
{

}

template <>box& mass(box& b1, box& b2)
{
    if (b1.volume > b2.volume)
        return b1;
    else
        return b2;
}
#endif