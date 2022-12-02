#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//程序清单16.1 使用string类的7个构造函数
//链接无
#if 0
#include <string>
// using string constructors

int main()
{
    using namespace std;

    string one("Lottery Winner!");     // ctor #1
    cout << one << endl;               // overloaded <<

    string two(20, '$');               // ctor #2
    cout << two << endl;

    string three(one);                 // ctor #3
    cout << three << endl;

    one += " Oops!";                   // overloaded +=
    cout << one << endl;

    two = "Sorry! That was ";
    three[0] = 'P';
    string four;                       // ctor #4
    four = two + three;                // overloaded +, =
    cout << four << endl;

    char alls[] = "All's well that ends well";
    string five(alls, 50);              // ctor #5 
    cout << five << "!\n";//***注***若超过了C风格字符串的长度，则仍将复制请求数目的字符
                                        //而且C风格字符串的尾部的\0，并不会被复制到five
    string six(alls + 6, alls + 10);     // ctor #6  需要传入的是两个地址值
    cout << six << ", ";
    string seven(&five[6], &five[10]); // ctor #6 again
    cout << seven << "...\n";

    string eight(four, 7, 16);         // ctor #7
    cout << eight << " in motion!" << endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.2 使用string输入函数从文件中读取输入，使用指定分界符的getline()方法
//链接无
#if 0
#include <fstream>
#include <string>//getline()
#include <cstdlib>//EXIT_FAILURE

int main()
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    string item;
    int count = 0;

    getline(fin, item, ':');
    while (fin)  // while input is good
    {
        ++count;
        cout << count << ": " << item << endl;
        getline(fin, item, ':');
    }

    cout << "Done\n";
    fin.close();
    // std::cin.get();
    // std::cin.get();
    return 0;
}
//***注***
//用命令行环境运行的方法：
//1.找到该可执行程序所在的文件路径(如本程序名为Project1.exe，其所在路径为)
//D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\x64\Debug
//2.用VS自带的工具中的命令行工具
//键入cd和空格和路径名，以改变路径
//键入Project1.exe tobuy.txt

//法二：不使用命令行环境：
//在该路径下D:\CODE\CPP_CODE\C++ Primer Plus Code practice\chapter 16\code1\Project1\Project1
//创建tobuy.txt，程序也可正常运行
//fin.open("tobuy.txt");可以改成
//fin.open("D:\\CODE\\CPP_CODE\\C++ Primer Plus Code practice\\chapter 16\\code1\\Project1\\Project1\\tobuy.txt");
//其中\\是转义序列，相当于\

#endif


//程序清单16.3 使用find()方法实现拼字游戏
//链接无
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()

const int NUM = 26;
using std::string;
const string wordlist[NUM] = { "apiary", "beetle", "cereal",
    "danger", "ensign", "florid", "garage", "health", "insult",
    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
    "plaid", "quilt", "remote", "stolid", "train", "useful",
    "valid", "whence", "xenon", "yearn", "zippy" };

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = wordlist[std::rand() % NUM];

        int length = target.length();//或写为target.size();

        string attempt(length, '-');

        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;

        string badchars;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;

            if (badchars.find(letter) != string::npos//若尝试了相同的字母
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);//返回该字符首次出现的位置的索引值
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                //***注***当输入了一个正确的字符后，继续检查target数组，把其
                //把含有的所有该字符都拷贝到attempt数组的相应位置
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }

            cout << "Your word: " << attempt << endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }

        }

        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0;
}
#endif


//程序清单16.4 size()，capacity()，reserve()方法
//C++实现通常会分配一个比实际字符串大的内存块
//链接无
#if 0
#include <string>

int main()
{
    using namespace std;

    string empty;
    string small = "bit";
    string larger = "Elephants are a girl's best friend";

    cout << "Sizes:\n";
    cout << "\tempty: " << empty.size() << endl;
    cout << "\tsmall: " << small.size() << endl;
    cout << "\tlarger: " << larger.size() << endl;
    cout << "Capacities:\n";
    cout << "\tempty: " << empty.capacity() << endl;
    cout << "\tsmall: " << small.capacity() << endl;
    cout << "\tlarger: " << larger.capacity() << endl;

    empty.reserve(50);
    cout << "Capacity after empty.reserve(50): "//请求最小长度为50的内存空间
        << empty.capacity() << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单16.5 使用智能指针
//功能：当指针过期时，其所指向的内存能够自动释放
//链接无
#if 0
#include <string>
#include <memory>//智能指针模板类
#include "cxqd16.5.h"

int main()
{
    {   //double* p_to_d ＝1.5 可以改写成：

        //正确写法：
            //double替换掉模板的泛型名(类型参数)，new double返回的值
                                                                             //作为构造函数的实参
        std::auto_ptr<double>p_to_d(new double);
        *p_to_d = 1.5;
        std::cout <<*p_to_d<< std::endl;

        //错误写法：
        /*double num = 1.5;
        std::auto_ptr<double>p(&num);*/
        //原因：delete不能用于非堆内存
    }
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();   // use -> to invoke a member function
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    // std::cin.get();  
    return 0;
}
#endif


//程序清单16.6 不适合使用auto_ptr的情况
//比较auto_ptr，shared_ptr，unique_ptr
//链接无
#if 0
#include <string>
#include <memory>

#define use_auto_ptr     0
#define use_shared_ptr  1

int main()
{
    using namespace std;
#if use_auto_ptr==1
    auto_ptr<string> films[5] =
    {
        auto_ptr<string>(new string("Fowl Balls")),
        auto_ptr<string>(new string("Duck Walks")),
        auto_ptr<string>(new string("Chicken Runs")),
        auto_ptr<string>(new string("Turkey Errors")),
        auto_ptr<string>(new string("Goose Eggs"))
    };

    //***注***若使用auto_ptr，则会在程序运行阶段崩溃
    auto_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#elif use_shared_ptr==1

    shared_ptr<string> films[5] =
    {
        shared_ptr<string>(new string("Fowl Balls")),
        shared_ptr<string>(new string("Duck Walks")),
        shared_ptr<string>(new string("Chicken Runs")),
        shared_ptr<string>(new string("Turkey Errors")),
        shared_ptr<string>(new string("Goose Eggs"))
};

    //***注***shared_ptr支持共享所有权，即智能指针间的赋值
    shared_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership

    //***注***若使用unique_ptr，则会在编译阶段报错
    /*unique_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership   */
    //但unique_ptr允许unique_ptr类型的临时右值赋给unique_ptr指针
    //或使用move()将一个unique_ptr赋给另一个(智能指针间的赋值)

    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; i++)
        cout << *films[i] << endl;

    cout << "The winner is " << *pwin << "!\n";

#endif

    /*
    shared_ptr<double> pd;
    double* p_reg = new double;
    *p_reg = 1.1;
    pd = (shared_ptr<double>)p_reg;  //必须使用显式强制类型转换

    std::cout << *pd << endl;
    */

    // cin.get();
    return 0;
}
#endif
//使用move()，将一个unique_ptr赋给另一个
#if 0
#include <memory>
#include <string>
using std::string;
using std::unique_ptr;

unique_ptr <string> demo(const char* s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main()
{
    unique_ptr<string> ps1, ps2;
    ps1 = demo("123abc");
    ps2 = move(ps1);
    ps1 = demo("456def");
    std::cout << *ps2 << *ps1 << std::endl;

    return 0;
}
#endif

//程序清单16.7 泛型编程，使用vector模板类，创建vector模板对象
//链接无
#if 0
#include <vector>
#include <string>

const int NUM = 5;

int main()
{
    using std::vector;
    using std::string;
    using std::cin;
    using std::cout;
    using std::endl;

    vector<string> titles(NUM);
    vector<int> ratings(NUM);

    cout << "You will do exactly as told. You will enter\n"
        << NUM << " book titles and your ratings (0-10).\n";

    int i;
    for (i = 0; i < NUM; i++)
    {
        cout << "Enter title #" << i + 1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }

    cout << "Thank you. You entered the following:\n"
        << "Rating\tBook\n";

    for (i = 0; i < NUM; i++)
    {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }
    // cin.get();

    return 0;
}
#endif


//程序清单16.8 使用迭代器iterator 
//使用STL容器的方法：size()，begin()，end()，swap()
//部分STL容器才有的方法：push_back()，erase()，insert()
//链接cxqd16.8.cpp
#if 0
#include <string>
#include <vector>
#include "cxqd16.8.h"

int main()
{
    using std::cout;
    using std::vector;

    vector<Review> books;//创建一个vector类对象，元素类型为
                                             //Review结构布局
    Review temp;//创建一个Review结构模板的结构temp
    
    while (FillReview(temp))
        books.push_back(temp);//将元素添加到矢量数组末尾

    int num = books.size();

    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n"
            << "Rating\tBook\n";

        //遍历元素方法一：
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);

        cout << "Reprising:\n"
            << "Rating\tBook\n";

        //使用类名和作用域解析运算符，访问迭代器iterator
        //为vector的Review类型声明一个迭代器pr
        vector<Review>::iterator pr;

        //遍历元素方法二：
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);

        //遍历元素法三：使用for_each();

        //遍历元素法四：使用基于范围的for循环(还支持修改容器的内容)

        //更多详见：遍历容器方法总结

        vector <Review> oldlist(books);// copy constructor used

        if (num > 3)
        {
            // remove 2 items
            //***注***
            //删除索引值1和索引值2位置上的元素，即
            //删除第二个和第三个元素
            books.erase(books.begin() + 1, books.begin() + 3);

            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);

            // insert 1 item
            //在第一个元素前面插入oldlist的第二个元素
            books.insert(books.begin(), oldlist.begin() + 1,
                oldlist.begin() + 2);

            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }

        //books的元素与oldlist的元素进行交换
        //***注***使用的是vector成员函数而不是STL提供的非成员函数swap()
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        
        cout << "books数组的内容:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        cout << "oldlist数组的内容:\n";
        for (pr = oldlist.begin(); pr != oldlist.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.9 使用STL函数(非成员函数) for_each()，sort()，random_shuffle()
//链接cxqd16.9.cpp
#if 0
#include "cxqd16.9.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()

int main()
{
    using namespace std;

    vector<Review> books;

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

        //用sort()和内置的<operator()对vector数组的元素进行排序
        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用sort()和自定义的函数对vector数组的元素进行排序
        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        //用random_shuffle()进行随机排序，即打乱数组的元素
        random_shuffle(books.begin(), books.end());
        cout << "After shuffling:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n"; 
    // cin.get();
    return 0;
}
#endif


//使用基于范围的for循环，遍历容器方法总结
//链接无
#if 0
#include <vector>
#include <algorithm>//for_each()

void show(double);
void alter(double&);

int main()
{
    using std::vector;
    using std::cout;
    using std::endl;
    //using std::iterator;  错误：应使用容器类中定义的迭代器
    using std::for_each;

    vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    //遍历元素方法一：
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << '\t';
    }
    cout.put('\n');

    //遍历元素方法二：(使用迭代器)
    //写法一：
    /*vector<double>::iterator p;
    for (p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }*/
    //写法二：
    for (auto p = data.begin(); p != data.end(); p++)
    {
        cout << *p << '\t';
    }
    cout.put('\n');

    //遍历元素方法三：(使用STL函数)
    for_each(data.begin(),data.end(),show);
    cout.put('\n');

    //遍历元素方法四：(基于范围的for循环)
    //写法一：
    /*for (double x : data)
        show(x);*/
    //写法二：
    for (auto x : data)
        show(x);
    cout.put('\n');

    //使用遍历元素方法四修改元素的值：
    for (auto &x : data)
        alter(x);
    for (auto x : data)
        show(x);
    cout.put('\n');

    //遍历元素方法五：(将内容复制到输出流(使用输出迭代器输出))
#include <iterator>
    copy(data.begin(), data.end(),
        std::ostream_iterator<double, char>(cout, "\t"));

    return 0;
}
void show(double a)
{
    std::cout <<a<< '\t';
}
void alter(double &num)
{
    num++;
}
#endif


//程序清单16.10 使用copy()，输出迭代器，反向迭代器，sort()
//链接无
#if 0
#include <vector>
#include <iterator>//ostream_iterator模板，是个适配器，可以将
                                  //一些其他接口转换为STL使用的接口
#include <algorithm>//sort()

int main()
{
    using namespace std;

    int casts[10] = { 6, 7, 2, 9 ,4 , 11, 8, 7, 10, 5 };
    vector<int> dice(10);

    // create an ostream iterator
    //要将信息复制到显示器上，则要有一个输出迭代器
    //可以用ostream_iterator模板创建这种迭代器
    //把数据输出接口cout转换为STL使用的接口(即输出迭代器)
    //让输出流能使用迭代器接口
    ostream_iterator<int, char> out_iter(cout, " ");

    //将15赋给指针指向的位置，然后将指针加1
    *(out_iter++) = 15;
    cout.put('\n');

    // copy from array to vector
                                        //***注***最后一个参数应为输出迭代器
    cout << "将casts的内容复制到dice\n";
    copy(casts, casts + 10, dice.begin());
    cout << "完成！\n";

    // copy from vector to output
    //将dice容器的整个区间复制到输出流中，即显示容器的内容
    //写法一：
    //copy(dice.begin(), dice.end(), out_iter);
    //写法二：不创建命名的迭代器，而直接构建一个匿名迭代器
    cout << "在显示器上显示dice的内容\n";
    copy(dice.begin(), dice.end(),
        ostream_iterator<int, char>(cout, " "));
    cout << endl;

    cout << "Implicit use of reverse iterator.\n";
    //实参一：指向超尾的反向迭代器；实参二：指向第一个元素的反向迭代器
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;

    cout << "Explicit use of reverse iterator.\n";
    // vector<int>::reverse_iterator ri;  // use if auto doesn't work
    for (auto ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

    //使用STL函数sort
    sort(dice.begin(),dice.end());
    copy(dice.begin(), dice.end(),
        std::ostream_iterator<int, char>(cout, " "));

    cout << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单16.11 使用两种插入迭代器
//链接无
#if 0
#include <string>
#include <iterator>//back_insert_iterator、insert_iterator
#include <vector>
#include <algorithm>//copy()

void output(const std::string& s) 
{
    std::cout << s << " "; 
}

int main()
{
    using namespace std;

    string s1[4] = { "fine", "fish", "fashion", "fate" };
    string s2[2] = { "busy", "bats" };
    string s3[2] = { "silly", "singers" };

    //创建一个vector数组，其含4个元素，每个元素类型均为string
    vector<string> words(4);

    //***注***s1 + 4是超尾迭代器，标识超尾的位置
    copy(s1, s1 + 4, words.begin());
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous back_insert_iterator object
    //创建匿名的back_insert_iterator迭代器
    copy(s2, s2 + 2,
        back_insert_iterator<vector<string> >(words));
    for_each(words.begin(), words.end(), output);
    cout << endl;

    // construct anonymous insert_iterator object
    //创建匿名的insert_iterator迭代器
    copy(s3, s3 + 2, 
        insert_iterator<vector<string> >(words, words.begin()));
    copy(words.begin(), words.end(), 
        std::ostream_iterator<string, char>(cout, " "));//使用迭代器输出
    cout << endl;           //***注***
                                      //发送给输出流的数据类型：string
    // cin.get();               //输出流使用的字符类型：char
    return 0;
}
#endif


//程序清单16.12 使用list的insert()、remove()、splice()、
//unique()、sort()、merge()方法
//链接无
#if 0
#include <iterator>
#include <list>//成员函数insert()等
#include <algorithm>//STL函数(非成员函数)：for_each()

void outint(int n) 
{
    std::cout << n << " "; 
}

int main()
{
    using namespace std;

    //创建一个由5个int类型的值2组成的序列
    list<int> one(5, 2); // list of 5 2s

    cout << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //创建一个空序列
    list<int> two;

    //将整个stuff数组的内容插入到two的首元素前
    int stuff[5] = { 1,2,4,8, 6 };
    //法一：(使用insert()成员函数)
    two.insert(two.begin(), stuff, stuff + 5);
    //法二：(使用insert_iterator插入迭代器)
    /*copy(stuff,stuff+5,
        insert_iterator<list<int>>(two,two.end()));*/
    
    cout << endl << "List two: ";
    for_each(two.begin(), two.end(), outint);
    
    //调用复制构造函数进行类型复制
    list<int> three(two);

    int more[6] = { 6, 4, 2, 4, 6, 5 };
    three.insert(three.end(), more, more + 6);
    
    cout << endl << "List three: ";
    for_each(three.begin(), three.end(), outint);
    
    //从双向链表中删除值为2的所有实例
    three.remove(2);
    cout << endl << "List three (删除了值为2的实例): ";
    for_each(three.begin(), three.end(), outint);

    //将链表one的内容插入到three头结点的前面
    //***注***one将清空
    three.splice(three.begin(), one);
    cout << endl << "List three after splice: ";
    for_each(three.begin(), three.end(), outint);
    cout << endl << "List one: ";
    for_each(one.begin(), one.end(), outint);

    //将连续的相同元素压缩为单个元素
    three.unique();
    cout << endl << "List three after unique: ";
    for_each(three.begin(), three.end(), outint);

    //排序(默认递增)
    three.sort();
    //***注***
    //不能使用STL函数sort()，
    //因为非成员函数sort()需要随机访问迭代器，
    //而list不支持随机访问
    //sort(three.begin(),three.end());

    //合并同类项
    three.unique();
    cout << endl << "List three after sort & unique: ";
    for_each(three.begin(), three.end(), outint);

    //排序(默认递增)
    two.sort();
    //将两个链表合并
    //***注***前提：两个链表必须已经排序
    three.merge(two);
    cout << endl << "Sorted two merged into three: ";
    for_each(three.begin(), three.end(), outint);

    cout << endl;
    // cin.get();

    return 0;
}
#endif


//程序清单16.13 使用关联容器set
//使用insert()、set_union()、set_intersection()、set_difference()、
//lower_bound()、upper_bound()
//链接无
#if 0
#include <string>
#include <set>//关联容器set
#include <algorithm>//set_union()、set_intersection()、set_difference()
#include <iterator>

int main()
{
    using namespace std;
    
    const int N = 6;
    string s1[N] = { "buffoon", "thinkers", "for", "heavy", "can", "for" };
    string s2[N] = { "metal", "any", "food", "elegant", "deliver","for" };

    set<string> A(s1, s1 + N);
    set<string> B(s2, s2 + N);

    //让输出流能使用迭代器接口
    ostream_iterator<string, char> out(cout, " ");

    cout << "Set A: ";
    copy(A.begin(), A.end(), out);
    cout << endl;
    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;

    cout << "Union of A and B:\n";

    set_union(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Intersection of A and B:\n";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(),
        insert_iterator<set<string> >(C, C.begin()));//使用插入迭代器

    //***注***错误写法：
    //set_union(A.begin(), A.end(), B.begin(), B.end(), C.begin());
    //最后一个参数不能写成C.begin()，
    //因为对于关联集合，
    //将键看作常量，C.begin()返回的是迭代器是常量迭代器
    //而不是输出迭代器
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3);
    cout << "Set C after insertion:\n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range:\n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;
    // cin.get();
    return 0;
}
#endif


//程序清单16.14 使用关联容器multimap
//使用方法insert()、count()、equal_range()
//链接无
#if 0
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
                              //键的类型          存储的值类型
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;

    codes.insert(Pair(415, "San Francisco"));
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Staten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkeley"));

    cout << "Number of cities with area code 415: "
        << codes.count(415) << endl;
    cout << "Number of cities with area code 718: "
        << codes.count(718) << endl;
    cout << "Number of cities with area code 510: "
        << codes.count(510) << endl;

    cout << "Area Code   City\n";
    MapCode::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it)
        cout << "    " << (*it).first << "     "
        << (*it).second << endl;

    //pair<MapCode::iterator, MapCode::iterator>
        auto range
        = codes.equal_range(718);

    cout << "Cities with area code 718:\n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;

    // cin.get();
    return 0;
}
#endif


//程序清单16.15 使用函数对象、使用方法remove_if()
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
    // std::cin.get();
    return 0;
}
#endif


//程序清单16.16 使用函数适配器
//链接无
#if 0
#include <vector>
#include <iterator>
#include <algorithm> //for_each()、transform()
#include <functional> //bind1st()

void Show(double);
const int LIM = 6;

int main()
{
    using namespace std;

    double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
    double arr2[LIM] = { 63, 65, 69, 75, 80, 99 };

    vector<double> gr8(arr1, arr1 + LIM);
    vector<double> m8(arr2, arr2 + LIM);

    cout.setf(ios_base::fixed);
    cout.precision(1);
    
    cout << "gr8:\t";
    for_each(gr8.begin(), gr8.end(), Show);
    cout << endl;
    
    cout << "m8: \t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);

    //plus<double>()生成一个匿名对象，同时其可作为函数对象
    //是个二元函数，接受两个参数
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(),
        plus<double>());
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);

    //multiplies<double>()生成一个匿名对象，同时其可作为函数对象
    //是个二元函数，接受两个参数
    //通过使用函数适配器bind1st()，
    //把二元函数对象捆绑成为一个一元函数对象
    //将常数赋给第一个参数，即第一个参数固定
    transform(gr8.begin(), gr8.end(), prod.begin(),
        bind1st(multiplies<double>(), 2.5));
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);

    cout << endl;
    // cin.get();
    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}
#endif


//程序清单16.17 string类使用STL接口
//链接无
#if 0
#include <string>
#include <algorithm> //sort()、next_permutation()

int main()
{
    using namespace std;
    string letters;

    cout << "Enter the letter grouping (quit to quit): ";

    while (cin >> letters && letters != "quit")
    {
        cout << "Permutations of " << letters << endl;
        sort(letters.begin(), letters.end());
        cout << letters << endl;

        //next_permutation()将区间的内容转换为下一种排序方式
        //***注***必须先对内容进行排序
        while (next_permutation(letters.begin(), letters.end()))
            cout << letters << endl;
        
        cout << "Enter next sequence (quit to quit): ";
    }

    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单16.18 对比STL方法(成员函数)和STL函数(非成员函数)的remove()
//链接无
#if 0
#include <list>
#include <algorithm>

void Show(int);
const int LIM = 10;

int main()
{
    using namespace std;

    int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };

    list<int> la(ar, ar + LIM);
    list<int> lb(la);

    cout << "Original list contents:\n\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;

    la.remove(4);
    cout << "After using the remove() method:\n";
    cout << "la:\t";
    for_each(la.begin(), la.end(), Show);
    cout << endl;
    
    list<int>::iterator last;
    last = remove(lb.begin(), lb.end(), 4);
    cout << "After using the remove() function:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);
    cout << endl;
    
    lb.erase(last, lb.end());
    cout << "After using the erase() method:\n";
    cout << "lb:\t";
    for_each(lb.begin(), lb.end(), Show);

    cout << endl;
    // cin.get();    
    return 0;
}

void Show(int v)
{
    std::cout << v << ' ';
}
#endif


//程序清单16.19 使用STL实现统计单词出现次数的程序
//链接无
#if 1
#include <vector>
#include <string>
#include <set>//关联容器set
#include <map>//关联容器map
#include <iterator>
#include <algorithm> //transform
#include <cctype> //tolower()

using namespace std;

char toLower(char ch) 
{
    return tolower(ch); 
}

string& ToLower(string& st)
{
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string& s);

int main()
{
    //将输入的单词添加到矢量中
    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while (cin >> input && input != "quit")
        words.push_back(input);
    
    //按输入顺序显示单词
    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    //按字母顺序显示单词
    //关联容器set自动对内容进行排序
    // place words in set, converting to lowercase
    set<string> wordset;
    //首先ToLower()把string元素都处理为小写字符，
    //然后transform()把每个string元素交给ToLower()处理
    //插入到set中会自动排序
    transform(words.begin(), words.end(),
        insert_iterator<set<string> >(wordset, wordset.begin()),
        ToLower);
    cout << "\nAlphabetic list of words:\n";
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    //记录每个单词被输入的次数
    // place word and frequency in map
    map<string, int> wordmap;
    set<string>::iterator si;//为set的string类型声明一个迭代器si

    for (si = wordset.begin(); si != wordset.end(); si++)
     //写法一：  
        wordmap.insert(pair<string,int>(*si,count(words.begin(),
            words.end(),*si)));
     //写法二：(可以用数组表示法(将键用作索引值)来访问存储的值)
     //wordmap[*si] = count(words.begin(), words.end(), *si);

    // display map contents
    cout << "\nWord frequency:\n";
    for (si = wordset.begin(); si != wordset.end(); si++)
                                        //可以用数组表示法(将键用作索引值)来访问存储的值
        cout << *si << ": " << wordmap[*si] << endl;
    
    // cin.get();
    // cin.get();
    return 0;
}

void display(const string& s)
{
    cout << s << " ";
}
#endif