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
//链接无
#if 1
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
    queue<int>line;                 //创建对象并用构造函数初始化
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
                line.enqueue(temp); // add newcomer to line
            }
        }
        if (wait_time <= 0 && !line.isempty())//当队列空闲且有节点时
        {
            line.dequeue(temp);     //排第一个的顾客在队列中被排除，其开始进行交易
            wait_time = temp.ptime(); //wait_time即进行交易所花的时间

            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queuecount();
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