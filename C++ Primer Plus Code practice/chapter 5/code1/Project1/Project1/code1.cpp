#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>//string 类
//
#if 1
#endif


//程序清单5.3 注意运算符优先级
#if 0
int main()
{
    using namespace std;
    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl;
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    cout.setf(ios_base::boolalpha);   //a newer C++ feature

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;
    /// cin.get();
    return 0;
}
#endif


//程序清单5.4 用for循环实现阶乘(for循环与数组协同工作)
#if 0
const int ArSize = 16;      // example of external declaration
int main()
{
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;//0!=1，1!=1

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;
    // std::cin.get();
    return 0;
}
#endif


//程序清单5.5 修改步长
#if 0
int main()
{
    using std::cout;    // a using declaration
    using std::cin;
    using std::endl;

    cout << "Enter an integer: ";
    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for (int i = 0; i < 100; i = i + by)
        cout << i << endl;
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.6 用for循环访问字符串
#if 0
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // display letters in reverse order
    for (int i = word.size() - 1; i >= 0; i--)
        cout << word[i];

    cout << "\nBye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif


//程序清单5.9 将数组中字符顺序反转
#if 1
int main()
{
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // physically modify string object
    char temp;
    int i, j;

    //法一：
    //for (int i = 0, j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //法二：
    for (       i = 0, j = word.size() - 1;                i < j;           ++i,--j       )
    {                       // start block
        temp = word[j];
        word[j] = word[i];
        word[i] = temp;
    }                       // end block

    //***注***
    //for (int i = 0, int j = word.size() - 1; i < j; ++i, --j)
    //{
    //}
    //报错：j未声明，原因：书P116

    cout << word << "\nDone\n";
    // cin.get();
    // cin.get();
    return 0;
}
#endif