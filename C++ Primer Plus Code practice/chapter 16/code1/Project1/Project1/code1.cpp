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
    //但unique_ptr允许unique_ptr类型的临时右值赋给unique_ptr指针
    //或使用move()将一个unique_ptr赋给另一个(智能指针间的赋值)
    /*unique_ptr<string> pwin;
    pwin = films[2];   // films[2] loses ownership   */

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
//使用STL容器的方法：size()，begin()，end()，swap()，push_back()
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


//程序清单16.9 使用STL函数
//链接cxqd16.9.cpp
#if 1
#include "cxqd16.9.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()

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