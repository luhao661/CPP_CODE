#include <iostream>

#if 0
int main()
{	
	std::cout<<"Hello World !\n";
	
	return 0;
}
#endif


#if 0

#include <string>
#include <iterator>//back_insert_iterator、insert_iterator
#include <vector>
#include <algorithm>//copy()
#include "cxqd.h"

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


#if 1
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

