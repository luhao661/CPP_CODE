#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//13.11 编程练习
//1.
//链接13.11.1.cpp
#if 0
#include "13.11.1.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd & disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
	disk.Report();
}
#endif


//2.
//链接13.11.2.cpp
#if 0
#include "13.11.2.h"
using namespace std;
void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);

	cout << "Using object directly:\n";
	c1.Report();// use Cd method
	c2.Report(); ;// use Classic method
	cout << endl;

	cout << "Using type cd * pointer to objects:\n";
	Cd* pcd = &c1;
	pcd->Report();// use Cd method for cd object
	pcd = &c2;
	pcd->Report();// use Classic method for classic object
	cout << endl;

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << endl;

	cout << "Testing assignment: \n";
	Classic copy;
	copy.Report();
	copy = c2;
	copy.Report();

	return 0;
}
void Bravo(const Cd& disk)//可以进行动态联编(程序将使用对象所属的类的方法)
{												//配合virtual虚函数
	disk.Report();
}
#endif


//3.
//链接13.11.3.cpp
#if 0
#include "13.11.3.h"

const int SIZE = 3;
char* getlabel(void);        //对字符串所占的内存进行动态分配

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    DmaABC* p_dma[SIZE];//声明一个数组，每个元素都是指向抽象基类的指针
    char* p_label_data;
    int rating;
    char kind;
    char color_data[40];
    char style[40];

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter the label name: ";
        p_label_data = getlabel();
        cout << "Enter the number of rating: ";
        cin >> rating;
        
        cout << "Enter 1 for baseDMA or "
            << "2 for lacksDMA or "<<"3 for hasDMA:";

        while (!(cin >> kind) || (kind != '1' && kind != '2'&&kind!='3'))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter 1 or 2 or 3 : ";
        }

        //while (cin>>kind&&(kind != '1' && kind != '2'))
        //    cout << "Enter either 1 or 2: ";

        cin.get();//消耗掉换行符

        if (kind == '1')
            p_dma[i] = new baseDMA(p_label_data,rating);
        else if(kind=='2')
        {
            cout << "Enter the color: ";
            cin.getline(color_data,40);
            p_dma[i] = new lacksDMA(color_data, p_label_data, rating);
        }
        else
        {
            cout << "Enter the style: ";
            cin.getline(style, 40);
            p_dma[i] = new hasDMA(style, p_label_data, rating);
        }

        delete p_label_data;
        //while (cin.get() != '\n')//消耗掉换行符，否则getline()将读取不到第二次及之后的输入
        //    continue;//不需要，因为getline会把换行符替换成'\0'
    }

    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        p_dma[i]->View();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete p_dma[i];  // free memory
    }
    cout << "Done.\n";
    /* code to keep window open
      if (!cin)
         cin.clear();
      while (cin.get() != '\n')
         continue;
   */
    return 0;
}

char* getlabel(void)        // return pointer to new string
{
    using std::cout;
    using std::cin;

    char temp[80];      // temporary storage 块作用域，无链接，自动存储期

    cin >> temp;        //temp数组暂存输入的内容

    char* pn = new char[strlen(temp) + 1];//计算输入的字符数量并动态分配一个内存空间

    strcpy(pn, temp); // copy string into smaller space 
                                 //***注***strcpy()检测到temp中的'\0'后把'\0'也拷贝入pn指向的内存空间的相应位置，然后停止拷贝
    return pn;          // temp lost when function ends
}//函数结束时，pn会销毁，但其指向的内存区域(堆)不会销毁

#endif


//4.
//链接13.11.4.cpp
#if 1
int main()
{


    return 0;
}
#endif