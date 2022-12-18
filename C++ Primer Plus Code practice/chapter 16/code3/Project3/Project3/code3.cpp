#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//16.10 编程练习
//1.
//链接无
#if 0
#include <string>
bool huiwen(std::string & st);

int main()
{
	using std::cout;
	using std::string;
	using std::cin;
	using std::endl;

	cout << "请输入字符串：";
	string st;
	cin >> st;
	bool bo = huiwen(st);

	if (bo)
		cout << "是回文\n";
	else
		cout << "不是回文\n";

	return 0;
}
bool huiwen(std::string& st)
{
	int length = st.size();//长度3，则索引0、1、2  索引只要0，长度5，索引只要0、1，长度7，索引只要0、1、2
	int local=0;				   //长度4，索引只要0、1，长度6，索引只要0、1、2，长度8，索引只要0、1、2、3

	//不需要分奇偶
	//if(length%2)//奇数个
		for (int i = 0; i < int(length/2); i++)
		{
			int j = length - i - 1;
			if (st[i] == st[j])
				continue;
			else
				return false;
		}
	//else//偶数个
	//	for (int i = 0; i < int(length / 2); i++)
	//	{
	//		int j = length - i - 1;

	//	}

	return true;
}
#endif


//2.
//链接无
#if 0
#include <cctype>
#include <algorithm>
#include <iterator>

bool huiwen(std::string& st);

char ToLower(char a)
{
	return tolower(a);
}

using std::string;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	//测试erase()的功能
	/*string st = "abcdefghijklmn";
	string::iterator si=st.begin();
	//st.erase(3,1);
	//或写成：
	st.erase(si+3, si+4); */

	string st;
	cin >> st;

	//处理为纯字母内容
	for (int index = 0; index < st.size(); index++)
	{
		if (!isalpha(st[index]))
		{
			st.erase(index, 1);
			--index;//***注***若没写此语句，则输入连续的非字母的字符时会留有一个未删去，如输入,,,则会留下,
		}
	}
	cout << st<<endl;

	string st1;
	//transform(st.begin(), st.end(),st1.begin(),ToLower); //第三个参数必须使用插入迭代器
	transform(st.begin(), st.end(),std::back_insert_iterator<string>(st1), ToLower);

	cout << st1<<endl;

	bool bo = huiwen(st1);

	if (bo)
		cout << "是回文\n";
	else
		cout << "不是回文\n";

	return 0;
}
bool huiwen(std::string& st)
{
	int length = st.size();//长度3，则索引0、1、2  索引只要0，长度5，索引只要0、1，长度7，索引只要0、1、2
	int local = 0;				   //长度4，索引只要0、1，长度6，索引只要0、1、2，长度8，索引只要0、1、2、3

	for (int i = 0; i < int(length / 2); i++)
	{
		int j = length - i - 1;
		if (st[i] == st[j])
			continue;
		else
			return false;
	}

	return true;
}

#endif


//3.
//链接无
#if 0
#include <string>//find()
#include <cstdlib>//srand(0
#include <ctime>//time()
#include <cctype>//tolower()
#include <vector>
#include <fstream>

//const string wordlist[NUM] = { "apiary", "beetle", "cereal",
//    "danger", "ensign", "florid", "garage", "health", "insult",
//    "jackal", "keeper", "loaner", "manage", "nonce", "onset",
//    "plaid", "quilt", "remote", "stolid", "train", "useful",
//    "valid", "whence", "xenon", "yearn", "zippy" };

using namespace std;

int main()
{
	vector<string>source;

    ifstream fin;
    fin.open("abc.txt");

    if (fin.is_open() == false)
    {
        cerr << "Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }

    //不能使用getline
    //getline(fin, target);
    //while (fin)  // while input is good
    //{
    //    cout << target <<'\t';
    //    getline(fin, target);
    //}

    string temp;
    int NUM=0;

    fin >> temp;
    while (fin)
    {
        source.push_back(temp);
        NUM++;

        fin >> temp;
    }

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);

    std::srand(std::time(0));
    while (play == 'y')
    {
        string target = source[std::rand() % NUM];

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


//4.
//链接无
#if 0
#include <list>

int reduce(long ar[],int n);

int main()
{
    long ar[] = {1,3,4,3,3,5,7,8,9,8,8,1,2,5,4};
    int len = sizeof ar / sizeof(long);

    int num=reduce(ar,len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//n值为15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar+index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    for (int index = 0; index < num; index++)
    {
       result[index] = l1.front();
       l1.pop_front();
    }
   

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
#endif
//其他方法：
//链接无
#if 0
#include <list>
#include <algorithm>

int reduce(long ar[], int n);
long mycopy(long a);

int main()
{
    long ar[] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int len = sizeof ar / sizeof(long);

    int num = reduce(ar, len);
    std::cout.put('\n') << num << std::endl;

    return 0;
}
int reduce(long ar[], int n)//n值为15
{
    std::list<long> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    long* result = new long[num];
    /*for (int index = 0; index < num; index++)
    {
        result[index] = l1.front();
        l1.pop_front();
    }*/

    //法二：
    //copy(l1.begin(),l1.end(),result);
    //法三：
    transform(l1.begin(),l1.end(),result,mycopy);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index];
    }

    return num;
}
long mycopy(long a)
{
    long result = a;
    return result;
}
#endif


//5.
//链接无
#if 0
#include <list>
#include <algorithm>
//#include <vector>

template <class T>
int reduce(T * ar,int n);

int main()
{
    long ar[15] = { 1,3,4,3,3,5,7,8,9,8,8,1,2,5,4 };
    int num = reduce(ar,15);
    std::cout << num<<std::endl;

    std::string s1 [4] = {"abc","ghj","cdf","bef"};
    num = reduce(s1,4);
    std::cout << num;

    return 0;
}
template <class T>
int reduce(T* ar, int n)
{
    std::list<T> l1;

    for (int index = 0; index < n; index++)
    {
        l1.push_back(*(ar + index));
    }

    l1.sort();
    l1.unique();

    int num = l1.size();

    T* result = new T[num];

    copy(l1.begin(),l1.end(),result);

    for (int index = 0; index < num; index++)
    {
        std::cout << result[index]<<' ';
    }
    std::cout.put('\n');

    return num;
}
#endif


//6.
//链接16.10.6.cpp
#if 0
#include "16.10.6.h"
#include <queue>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    using std::queue;
    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item>line;                 //创建对象并用构造函数初始化
                                              // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;              //  hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    cin >> perhour;
    double min_per_cust;    //  average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;//得每位客户到来的平均时间

    Item temp;              //  new customer data
    long turnaways = 0;     //  turned away by full queue
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line

// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))  // have newcomer
        {
            if (line.size()==qs)
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.push(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.empty())//当队列空闲且有节点时
        {
            temp=line.front();     //排第一个的顾客在队列中被排除，其开始进行交易
            line.pop();
            wait_time = temp.ptime(); //wait_time即进行交易所花的时间

            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.size();
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;//加入队列的人数
        cout << "  customers served: " << served << endl;//已服务完的人数
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    // cin.get();
    // cin.get();
    return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);//详细分析见《C Primer Plus》程序清单17.9
}

#endif


//7.
//链接无
#if 0
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<int> lotto(int num_of_dot,int num_of_choose);

int main()
{
    vector<int> winners;
    winners = lotto(51,6);

    cout << "\n彩票中奖数字：\n";
    for (auto p = winners.begin(); p < winners.end(); p++)
    {
        cout << *p << '\t';
    }

    return 0;
}
vector<int> lotto(int num_of_dot, int num_of_choose)
{
    vector<int> data(num_of_dot);
    for (int i = 1; i <= num_of_dot; i++)
    {
        data[i-1] = i;
    }

    cout << "数字：";
    vector<int>::iterator p;
    for (p = data.begin(); p < data.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    srand(time(0));//***注***此处产生的种子能供random_shuffle函数使用
    random_shuffle(data.begin(),data.end());

    vector<int> win(num_of_choose);
    for (int index = 0; index < num_of_choose; index++)
    {
        win[index] = data[index];
    }
    
    return win;
}
#endif


//8.
//链接无
#if 0
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool FillData(set<string>&);
int main()
{
    set<string>data_Mat;
   
    cout << "请输入姓名：\n";
    FillData(data_Mat);
    for (auto p = data_Mat.begin(); p != data_Mat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_Pat;

    cout << "请输入姓名：\n";
    FillData(data_Pat);
    for (auto p = data_Pat.begin(); p != data_Pat.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    set<string>data_M_and_P;
    //法一：使用针对集合操作的函数
    //set_union(data_Mat.begin(), data_Mat.end(), 
    //    data_Pat.begin(), data_Pat.end(),
    //    insert_iterator<set<string>>(data_M_and_P, data_M_and_P.begin()));//使用插入迭代器

    //法二：
    //错误写法：(原因：书P569)
    //copy(data_Mat.begin(), data_Mat.end(), data_M_and_P.begin());
    //错误写法：错误使用back_insert_iterator
    /*copy(data_Mat.begin(), data_Mat.end(),
        back_insert_iterator<set<string> >(data_M_and_P));*/

    copy(data_Mat.begin(), data_Mat.end(),
        insert_iterator<set<string> > (data_M_and_P, data_M_and_P.begin()));
    copy(data_Pat.begin(), data_Pat.end(),
        insert_iterator<set<string> >(data_M_and_P, data_M_and_P.begin()));

    cout << "两人的朋友有：\n";
    for (auto p = data_M_and_P.begin(); p != data_M_and_P.end(); p++)
    {
        cout << *p << '\n';
    }
    cout.put('\n');

    return 0;
}
bool FillData(set<string>& data)
{
    bool status=1;

    string temp;

    getline(cin,temp);
    while (cin&&temp!="")
    {
        data.insert(temp);
        getline(cin, temp);
    }

    if (cin)
        cin.clear();

    if (data.size() == 0)
        status = 0;

    return status;
}
#endif


//9.
//链接无
#if 0
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

void show(int);
int main()
{
    vector<int>vi0;

    srand((int)time(0));
    for (int i = 0; i < 100000; i++)
        vi0.push_back(rand());

#if 0
    for_each(vi0.begin(),vi0.end(),show);
    cout << endl;
#endif

    vector<int>vi(vi0);
    list<int>li(vi0.size());
    copy(vi0.begin(),vi0.end(),li.begin());

    cout << "STL的sort()函数所用的时间：\n";
    //计算对数组内容排序所需的时间
    clock_t start = clock();
    sort(vi.begin(),vi.end());
    clock_t end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;

    cout << "list的sort()方法所用的时间：\n";
    //计算对链表内容排序所需的时间
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    cout << "链表内容复制到数组，再对vi进行排序所需的时间：\n";
    copy(vi0.begin(), vi0.end(), li.begin());
    //计算链表内容复制到数组，对vi进行排序，再将结果复制到li所需的时间
    start = clock();
    copy(li.begin(),li.end(),vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
void show(int num)
{
    cout << num<<" ";
}
#endif


//10.
//链接16.10.10.cpp
#if 0
#include "16.10.10.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;

    //创建一个vectoir数组，每个元素都是智能指针，指向Review类型的值
    auto p_temp=new Review;
    vector<shared_ptr<Review>> books;
       /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//指向下一个可用于存储Review的内存区域
    }

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
            << books.size() << " ratings:\n"
            << "Rating\tBook\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
//错误	C2664	“void(const Review*)” :
//无法将参数 1 从“std::shared_ptr<Review>”转换为“const Review * ”
//即：智能指针类型不能自动转化成普通指针类型
                for_each(books.begin(), books.end(), ShowReview);
                break;
            case '2':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(*books_kaobei.begin(), *books_kaobei.end());

                }
            default:
                cout << "输入有误，请重新输入！"<<endl;
                break;
            }//可用于替换程序清单16.8中的for循环

            ////用sort()和内置的<operator()对vector数组的元素进行排序
            //sort(books.begin(), books.end());
            //cout << "Sorted by title:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////用sort()和自定义的函数对vector数组的元素进行排序
            //sort(books.begin(), books.end(), worseThan);
            //cout << "Sorted by rating:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            ////用random_shuffle()进行随机排序，即打乱数组的元素
            //random_shuffle(books.begin(), books.end());
            //cout << "After shuffling:\nRating\tBook\n";
            //for_each(books.begin(), books.end(), ShowReview);

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}
#endif


//10.改正
//链接16.10.10.1cpp
#if 0
#include "16.10.10.1.h"
#include <vector>
#include <algorithm>//for_each()，sort()，random_shuffle()，swap()
#include <memory>//shared_ptr

int main()
{
    using namespace std;


    //待改进的方法：
    //这只支持最多10组数据
    //而且输入选择的数字'7'后，程序会崩溃
    //Expression: _CrtisvalidHeapPointer(block) 发生问题
#if 0
    //创建一个vectoir数组，每个元素都是智能指针，指向Review类型的值
    auto p_temp = new Review[10];
    vector<shared_ptr<Review>> books;
    /* = { (shared_ptr<Review>)p_temp};*/

    while (FillReview(*p_temp))
        //p_books.push_back(p_temp);
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp++;//指向下一个可用于存储Review的内存区域
    }
#endif

    //改进后的方法：
#if 0
    //创建一个vectoir数组，每个元素都是智能指针，指向Review类型的值
    vector<shared_ptr<Review>> books;

    auto p_temp = new Review;
    while (FillReview(*p_temp))
    {
        books.push_back((shared_ptr<Review>)p_temp);
        p_temp = new Review;
    }
#endif

    //改进后的方法(更好)：
#if 1
    vector<shared_ptr<Review>> books;
    Review temp;

    while (FillReview(temp))
    {
        shared_ptr<Review> p  (new Review (temp));
        books.push_back(p);//属于智能指针间的赋值，而不是初始化
    }
#endif

    if (books.size() > 0)
    {
        cout << "Thank you. You entered "
            << books.size()<<" books !\n";

        menu();

        char choice;
        cin >> choice;
        while (choice != '7')
        {
            switch (choice)
            {
            case '1':
                for_each(books.begin(), books.end(), ShowReview);
                break;

            case '2':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(books_kaobei.begin(), books_kaobei.end());
                    for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
                }
                break;

            case '3':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(books_kaobei.begin(), books_kaobei.end(),
                        anpinjishengxu);
                    for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
                }
                break;

            case '4':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(books_kaobei.begin(), books_kaobei.end(),
                        anpinjijiangxu);
                    for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
                }
                break;

            case '5':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(books_kaobei.begin(), books_kaobei.end(),
                        anjiageshengxu);
                    for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
                }
                break;

            case '6':
                {//***注***若不加括号，则报错：switch控制传输跳过的实例化
                    vector<shared_ptr<Review>> books_kaobei(books);
                    sort(books_kaobei.begin(), books_kaobei.end(),
                        anjiagejiangxu);
                    for_each(books_kaobei.begin(), books_kaobei.end(), ShowReview);
                }
                break;

            default:
                cout << "输入有误，请重新输入！" << endl;
                break;
            }

            menu();
            cin >> choice;
        }
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";

    return 0;
}
#endif