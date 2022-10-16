#define _CRT_SECURE_NO_WARNINGS 1

#if 0

// worker0.cpp -- working class methods
#include "cxqd14.7.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*********************************************************************/

// Worker methods
// must implement virtual destructor, even if pure
Worker::~Worker() {}

void Worker::Set()
{
    cout << "Enter worker's name: ";
    getline(cin, fullname);

    cout << "Enter worker's ID: ";
    cin >> id;

    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const
{
    cout << "Name: " << fullname << "\n";
    cout << "Employee ID: " << id << "\n";
}

/*********************************************************************/

// Waiter methods
void Waiter::Set()
{
    Worker::Set();
    cout << "Enter waiter's panache rating: ";
    cin >> panache;

    while (cin.get() != '\n')
        continue;
}

void Waiter::Show() const
{
    cout << "Category: waiter\n";
    Worker::Show();
    cout << "Panache rating: " << panache << "\n";
}

/*********************************************************************/

// Singer methods
/*char* Singer::pv[] = {"other", "alto", "contralto",
            "soprano", "bass", "baritone", "tenor" };   
*/      //报错：“const char *“ 类型的值不能用于初始化 “char *“ 类型的实体

//解决方法：使用强制类型转换
char* Singer::pv[] = {(char*)"other", (char*)"alto", (char*)"contralto",//创建一个让编译器计算元素个数的数组
    (char*)"soprano", (char*)"bass", (char*)"baritone", (char*)"tenor" };   //每个数组元素都是指向char类型的指针


void Singer::Set()
{
    Worker::Set();
    cout << "Enter number for singer's vocal range:\n";

    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;

    while (cin.get() != '\n')
        continue;
}

void Singer::Show() const
{
    cout << "Category: singer\n";
    Worker::Show();
    cout << "Vocal range: " << pv[voice] << endl;
}

#endif