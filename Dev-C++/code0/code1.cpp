#if 1
#include <iostream>

int main ()
{
	using std::cin;
	using std::cout;
	
	int a,b;
	
	cin>>a>>b;
	
	cout<<a+b;
	
	return 0;
}
#endif


//对数字进行排序 
//法一：(提交时必须选择C++11) 
#if 0
#include <iostream> 
#include <valarray>
//#include <algorithm>.
using namespace std;

bool mycompare(int a,int b);

int main ()
{
	int len;
	cin>>len;
	
	int temp[len];
	valarray<int>shuzu(len);//valarry类中没有输入方法，所以采用普通数组向其拷贝数据的方法 
	
	for (int index=0;index<len;index++)
	{
		cin>>*(temp+index);
	}
	
	for (int index=0;index<len;index++)
	{
		shuzu[index]=temp[index];
	}
	
	//shuzu.sort();  valarray类没有sort方法
	//std::sort(shuzu.begin(),shuzu.end()); valarray类没有begin()、end()方法 
	
	//sort(begin(shuzu),end(shuzu));//默认从小到大 
	//或 
	sort(begin(shuzu),end(shuzu),mycompare);
	
	for (int index=0;index<len;index++)
	{
		cout<<shuzu[index];
	}

	return 0;
} 

bool mycompare(int a,int b)
{
	return a<b;
}
#endif
//法二： 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

//***注***若要比较类对象中的元素，则要有以下函数 
//bool operator<(int a,int b);

int main()
{
//写法一：
	int len;
	cin>>len;
	
	vector<int> v1(len);
	
	for(int index=0;index<len;index++)
	{
		cin>>v1[index];
	}

//写法二：
//	int len;
//	cin>>len;
//	vector<int>v1;
//	
//	int a;
//	for(int index=0;index<len;index++)
//	{
//		cin>>a;
//		v1.push_back(a); 
//	}

//写法三：
//	int len;
//	cin>>len;
//	
//	vector<int> v1;
//	back_insert_iterator<vector<int>> it(v1);
//	
//	int num;
//	for(int index=0;index<len;index++)	
//	{
//	cin>>num;
//	*(it)=num;
//	}
	sort(v1.begin(),v1.end());
	
	for(int index=0;index<len;index++)
	{
		cout<<v1[index];
	}
	
	return 0;
}
//bool operator<(int a,int b)
//{
//	return a<b;
//}

#endif 


