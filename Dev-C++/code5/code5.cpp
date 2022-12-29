//5.1 贪心算法 
//对问题求解时，总是做出在当前看来是最好的选择
//做出的是局部最优解 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	float W=15;	
	float weight_data[7]={4.5,1,2,3.3,2.8,6.2,8.4};
	
	int count=0;
	sort(weight_data,weight_data+7);
	
	for(int i=0;i<7;i++)
	cout<<weight_data[i]<<" ";
	
	float temp=0.0;	
	for(int i=0;i<7;i++)
	{
		temp+=weight_data[i];
		if(temp<=W)
		{
			count++;
		}
		else
		break;
	}
	
	cout<<endl<<count<<endl;
	
	return 0;
} 
#endif
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
	float jiage;
	float danjia;
	float weight;
}FoodTypeDef;

bool mycompare(const FoodTypeDef& ,const FoodTypeDef&);
int main()
{
	float W=15;	
	FoodTypeDef food_structure[7]=
	{
		{18,18.0/4.5,4.5},
		{3,3.0/1,1},
		{7.8,7.8/2,2},
		{15.8,15.8/3.3,3.3},
		{8,8/2.5,2.5},
		{99.2,99.2/6.2,6.2},
		{20.2,20.2/8.4,8.4}
	};
	
	int count=0;
	sort(food_structure,food_structure+7,mycompare);
	
	for(int i=0;i<7;i++)
		cout<<food_structure[i].danjia<<" ";
	
	float temp=0.0;
	float money=0;	
	for(int i=0;i<7;i++)
	{
		temp+=food_structure[i].weight;
		if(temp<=W)
		{
			count++;
			money+=food_structure[i].jiage;
		}
		else
		temp-=food_structure[i].weight;
	}
	
	cout<<endl<<count<<endl<<money;
	
	return 0;
} 
bool mycompare(const FoodTypeDef& F1,const FoodTypeDef& F2)
{
	if(F1.danjia>=F2.danjia)
		return 1;
	else
		return 0;
}
#endif


//5.2 分巧克力 
#if 0
#include <iostream>

using namespace std;

typedef struct
{
	int H;
	int W;
}AttributeTypeDef;

int main()
{
	int N,K;
	cin>>N>>K;
	
	AttributeTypeDef AttributeStruct[N];//***C++支持数组长度是变量 
	
	int temp;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		AttributeStruct[i].H=temp;
		cin>>temp;
		AttributeStruct[i].W=temp;
	}
	
	int k=0;
	int bianchang;
	for(bianchang=1;    ;bianchang++) 
	{
		k=0;
		
		for(int i=0;i<N;i++)
		{
			int m=AttributeStruct[i].H/bianchang;
			int n=AttributeStruct[i].W/bianchang;
			k+=m*n;
		}
		
		if(k>=K)
			continue;
		else
			break;
	}
	
	cout<<bianchang-1;

	return 0;
} 
//2 10
//6 5
//5 6
#endif


//5.3 递增三元组 
#if 0
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int N;
	cin>>N;
	
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		A[i]=temp;
	}	
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		B[i]=temp;
	}
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		C[i]=temp;
	}
	
	int count=0;
	//时间复杂度：O(n^3) 
//	for(int i=0;i<N;i++)
//		for(int j=0;j<N;j++)
//			for(int k=0;k<N;k++)
//			{
//				if(A[i]<B[j]&&B[j]<C[k])
//					count++;
//			}

//修改法一：(时间复杂度：O(n^2)) 
//对A[j]<B[i]和B[i]<C[j]分开统计数目，将统计的结果相乘 
	int m=0,n=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(A[j]<B[i])
				m++;
			if(B[i]<C[j])
				n++;
		}
		count+=m*n;
		m=n=0;
	}

	cout<<count;

	return 0;
}
#endif
//修改法二： 
//思路：
//对三个数组排序，然后找出A中小于B[i]的最大的一个数的
//索引值，找出C中大于B[i]的最小的一个数的索引值 
//再把两个索引值进行处理后得到A中小于B[i]的个数和
//C中大于B[i]的个数，相乘后得到结果 
//转换为一个查找问题 
//***注***画数组的索引及对应的数据图以辅助理解和编程 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int small(const vector<int>& ,int );
int big(const vector<int>& ,int );

int main()
{
	int N;
	cin>>N;
	
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		A[i]=temp;
	}	
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		B[i]=temp;
	}
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		C[i]=temp;
	}

	sort(A.begin(),A.end()); 
	sort(B.begin(),B.end()); 
	sort(C.begin(),C.end()); 

	int count=0;

	int m=0,n=0;
	for(int i=0;i<N;i++)
	{
		int key=B[i];
		int m=small(A,key);
		int n=big(C,key);
		
		if(A[m]<key&&C[n]>key)
			count+=(m+1)*(N-n);
	}

	cout<<count;

	return 0;
}
int small(const vector<int>& v,int key)
{
	//用二分法查找
	int left=0,right=v.size()-1;
	
	while(left<right)
	{
		int mid=(left+right+1)/2;//防止陷入死循环 
		if(v[mid]<key)
			left=mid;
		else
			right=mid-1;
	} 

	return left;
}
int big(const vector<int>& v,int key)
{
	//用二分法查找
	int left=0,right=v.size()-1;
	
	while(left<right)
	{
		int mid=(left+right)/2;//防止陷入死循环 
		if(v[mid]>key)
			right=mid;
		else
			left=mid+1;
	} 

	return left;
}
#endif


//5.4 乘积最大 
#if 0
#include <iostream>
#include <vector>
#include <valarray>
#include <map>
#include <cmath>
#include <algorithm>//copy()
using namespace std;
typedef long long LL;

int main()
{
	int N,K;
	cin>>N>>K;
	
	vector<LL> data(N);
	for(int i=0;i<N;i++)
	{
		LL temp;
		cin>>temp;
		data[i]=temp; 
	} 
	
	valarray<LL>shuzu(N);//N必须要写 
	copy(data.begin(),data.end(),begin(shuzu));

//不能用map，因为不能存相同值的键	
//	map<LL,LL>data_map;
//	for(auto p=begin(shuzu);p!=end(shuzu);p++)
//	{
//		data_map[*p]=abs(*p);
//	}
	int* judge=new int[N];//p数组存某个数是否为负值
	
	for(int i=0;i<N;i++)
		judge[i]=0;
	
	valarray<LL>shuzu_jueduizhi(N);
	for(int index=0;index<N;index++)
	{
		LL temp;
		if(shuzu[index]<0)
		{
			temp=abs(shuzu[index]);
			judge[index]=1;
			shuzu_jueduizhi[index]=temp;
		} 
		else
		shuzu_jueduizhi[index]=shuzu[index];
	}
	
	
	LL *qvshuzi=new LL[K];
	
	int fushu_count=0;
	for(int i=0;i<K;i++)
	{
		qvshuzi[i]=shuzu_jueduizhi.max();
		auto p=find(begin(shuzu_jueduizhi),
		end(shuzu_jueduizhi),shuzu_jueduizhi.max());
		
		//最大值数字用最小值覆盖
		//***错误***
		//最大值选过后，不能再选，但是把最大值处理为
		//别的数字有bug，不能保证之后一定不会选这个处理过后的数字 
		*p=shuzu_jueduizhi.min();
		
		if(judge[p-begin(shuzu_jueduizhi)])
		fushu_count++;
	}
	
	LL result=1;
	for(int i=0;i<K;i++)
	{
		result*=qvshuzi[i];
		result%=1000000009;
	}
	
	if(fushu_count%2!=0)//奇数个负数
		result=0-result;
	
	cout<<result<<endl;		
	
	delete []judge;
	delete []qvshuzi;
	return 0;
} 
#endif
#if 1
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;

//typedef struct
//{
//	LL num;
//	bool flag;
//}NumTypeDef;

//1.用内置的pair类型代替结构体，不用写<运算符重载函数
//2.用deque容器，支持数组表示法随机访问元素， 
//支持元素的增删
//3.支持对deque对象使用sort()排序 

int main()
{
	int N,K;
	cin>>N>>K;
	
	pair<LL,bool> p1;
	deque<pair<LL,bool>> Num_deque;
	for(int i=0;i<N;i++)
	{
		LL temp;
		cin>>temp;
		
		bool f;
		if(temp<0)
		{
			f=1;
			temp=-temp;
		}
		else
			f=0;
		
		p1.first=temp;
		p1.second=f;
		Num_deque.insert(Num_deque.begin(),p1);
	}
	
	sort(Num_deque.begin(),Num_deque.end());
	
	for(auto p=Num_deque.begin();p!=Num_deque.end();p++)
		cout<<(*p).first<<" "; 
	cout<<endl;
	
	LL result=1;
	int fushu_count=0;
	for(int i=0;i<K;i++)
	{
//***错误写法*** 
//		result*=(*Num_deque.end()).first;
		result*=(*(Num_deque.end()-1)).first;
		result%=1000000009;
		
		if((*(Num_deque.end()-1)).second)
			fushu_count++;
		
		Num_deque.pop_back();
	}
	
	if(fushu_count%2!=0)//奇数个负数
		result=0-result;
	
	cout<<result<<endl;	

	return 0;
}
//5 3
//-100000
//-100000
//-2
//-100000
//-100000
#endif 


























