#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//16.9 复习题
//1.
//链接无
#if 0
#include "16.9.1.h"

int main()
{
	RQ1 st1;
	st1.show();

	RQ1 st2("abc");
	st2.show();

	RQ1 st3(st2);
	st3.show();

	RQ1 st4;
	st4 = st3;
	st4.show();

	return 0;
}
#endif


//3.
//链接无
#if 0
#include <string>
#include <cctype>
void alter(std::string&);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string st;

	cin >> st;
	alter(st);

	cout << st;

	return 0;
}
void alter(std::string& s)
{
	for (auto p = s.begin(); p != s.end(); p++)
	{
		if (islower(*p))
			*p = toupper(*p);
	}
}
#endif


//10.
//链接16.9.10.cpp
#if 0
#include "16.9.10.h"
#include <list>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()

int main()
{
    using namespace std;

    list<Review> books;

    Review temp;

    while (FillReview(temp))
        books.push_back(temp);

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        //可用于替换程序清单16.8中的for循环
        for_each(books.begin(), books.end(), ShowReview);
          
        //***注***
        //不能使用STL的非成员sort()
        //修改一：
        books.sort();
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //修改二：
        books.sort(worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用random_shuffle()进行随机排序，即打乱数组的元素
        //random_shuffle(books.begin(), books.end());
        
        //cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";

    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//11.
//链接无
#if 0
#include <list> //remove_if()
#include <iterator>
#include <algorithm> //for_each()

//函数对象(函数符)
//重载了()运算符的类对象，则可以像使用函数那样使用类对象
template<class T>  // functor class defines operator()()
class TooBig
{
private:
    T cutoff;

public:
    TooBig(const T& t) : cutoff(t)
    {}
    bool operator()(const T& v)
    {
        return v > cutoff;
    }
};

void outint(int n)
{
    std::cout << n << " ";
}

int main()
{
    using std::cout;
    using std::endl;

    using std::list;
    using std::for_each;
    using std::remove_if;

    int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    list<int> yadayada(vals, vals + 10); // range constructor
    list<int> etcetera(vals, vals + 10);

    //  C++0x can use the following instead
    //  list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    //  list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};

    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;

    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    //remove_if()成员将谓词(即返回bool值的一元函数)作为参数
    //由于类中定义了()运算符重载函数，所以可以把此类对象
    //当成函数名(或指向函数的指针)看待
    TooBig<int> f100(100); // limit = 100
    yadayada.remove_if(f100);               // use a named function object

                                //创建匿名的类对象
    etcetera.remove_if(TooBig<int>(200));   // construct a function object

    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    cout << endl;

    bool bo = TooBig<int>(10)(9);
    cout << bo<<endl;
    // std::cin.get();
    return 0;
}
#endif
