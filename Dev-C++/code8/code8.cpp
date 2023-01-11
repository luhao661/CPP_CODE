//8.1 其他算法
//最短路径算法——迪杰斯特拉算法，弗洛伊德算法
//并查集算法


//8.2 最大公共子串
#if 0
#include <stdio.h>
#include <string.h>
 
#define N 256
int f(const char* s1, const char* s2)
{
    int a[N][N];
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i,j;
    
    memset(a,0,sizeof(int)*N*N);
    
    int max = 0;
    for(i=1; i<=len1; i++)
	 {
        for(j=1; j<=len2; j++)
		  {
            if(s1[i-1]==s2[j-1]) 
				{
                a[i][j] = a[i-1][j-1]+1; 
                if(a[i][j] > max) 
					 	max = a[i][j];
            }
        }
    }
    
    return max;
}
 
int main()
{
    printf("%d\n", f("abcdkkk", "baabcdadabc"));
    printf("%d\n", f("aaakkkabababa", "baabababcdadabc"));
    printf("%d\n", f("abccbaacbcca", "ccccbbbbbaaaa"));    
    printf("%d\n", f("abcd", "xyz"));
    printf("%d\n", f("ab", "ab"));
    return 0;
}
#endif 


//8.3 螺旋折线 
//***思路***
//处理成n个矩形，算距离时先加上矩形的长度
//根据坐标值，
//推算出与起点坐标之间的关系 
#if 0
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;

int main()
{
	LL X,Y;
	cin>>X>>Y;
	
	//计算该点在第n个正方形上
	LL n=max(abs(X),abs(Y));
	
	//计算要先加上的n-1个正方形的长度	
	LL dis=(0+8*(n-1))*n/2;
	
	//当y>=x时
	if(Y>=X)
		dis+=2*n+X+Y;
	else//当y<x时
		dis+=6*n-X-Y;
		
	cout<<dis;	 

	return 0;
}
#endif


//8.4 日志统计 
#if 0
#include <iostream>
#include <set>
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std;

long f1(vector<long> v,long d);

int main()
{
	//N条记录，D的时间长度，K个赞 
	long N,D,K;
	cin>>N>>D>>K;
	
//***注***
//不能使用multiset关联容器，
//因为对于此容器来说，值就是键，即pair对象，
//那么查询也只能查pair对象 

//	multiset<pair<long,long>>record;
	
//	for(int i=0;i<N;i++)
//	{
//		long ts,id;
//		cin>>ts>>id;					 //错误理解： 
//								          //键 值 
//		record.insert(pair<long,long>(id,ts));
//	}
//	
//	for(auto p=record.begin();p!=record.end();p++)
//	{
//		auto range=record.equal_range((*p).first);//编译错误 
//		
//	}

	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //键 值 
		record.insert(pair<long,long>(id,ts));
	}
	
	#if 0
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	#endif
	
	set <long> id;
	vector<long> v1;
	for(auto p=record.begin();p!=record.end();p++)
	{
		//找到含该id的记录的范围 
		auto range=record.equal_range((*p).first); 
		
//		for(auto it=range.first;it!=range.second;it++)
//		cout<<(*it).first<<" "<<(*it).second<<endl;
		
		int count=0;
		//***注***range.second-1无定义 
		//no match for 'operator -'
//		for(auto it=range.first;it!=range.second;    )
//		{
//no match for 'operator +'
//			if(it+1<range.second&&*((it+1)).second-(*it).second<D)
//				count++; 

//			auto temp=it;
//			it++;
//			
//			if((*it).second-(*temp).second<D)
//				count++;
//		}
		//由于不能保证同一键对应的值是升序排列的，那么把
		//这些值存入vector中，对数组进行排序后计算时间间隔 
		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***必写*** 

		if(count>=K)
			id.insert((*p).first);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
		cout<<*i<<endl;

	return 0;
}

long f1(vector<long> v,long d)
{
	long count=1;//***注***是1不是0 
	
	sort(v.begin(),v.end());
	
	for(auto it=v.begin();it+1!=v.end();it++)
	{
		if(*(it+1)-*it<d)//若两个时间的间隔小于d   
		{
			count++;
		}		
	}	
	
	return count;
}
//7 10 2
//0 1
//0 10
//10 10
//10 1
//9 1
//100 3
//100 3
#endif
//改进：
//用set的元素值来对multimap的记录进行查找，
//减少对multimap重复查找的次数 
#if 0
#include <iostream>
#include <set>
#include <map> 
#include <vector> 
#include <algorithm>
using namespace std;

//计算符合时间间隔的赞的数量 
long f1(vector<long> v,long d);

int main()
{
	//N条记录，D的时间长度，K个赞 
	long N,D,K;
	cin>>N>>D>>K;
	
	multimap<long,long> record;
	
	for(int i=0;i<N;i++)
	{
		long ts,id;
		cin>>ts>>id;
								          //键 值 
		record.insert(pair<long,long>(id,ts));
	}
	
	#if 0
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	#endif
	
	//存用于遍历multimap键的键 
	set<long> ID;	
	for(auto p=record.begin();p!=record.end();p++)
	{
		ID.insert((*p).first);
	} 
	
	//存符合条件的id号 
	set <long> id;
	//存id号对应的各个时间 
	vector<long> v1;
	//对set对象的元素进行遍历 
	for(auto p=ID.begin();p!=ID.end();p++)
	{
		//在multimap中找到含该ID的记录的范围 
		auto range=record.equal_range((*p)); 
		
		int count=0;

		for(auto it=range.first;it!=range.second;it++)	
		{
			v1.push_back((*it).second);
		}
		count=f1(v1,D);
		v1.clear();//***必写*** 

		if(count>=K)
			id.insert(*p);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
//		cout<<*i<<endl;
		printf("%ld\n",*i); 

//***注***
//要输出大量数据时cout比printf慢，为了不影响评测结果，此处用printf() 
	return 0;
}

long f1(vector<long> v,long d)
{
	//***注***
	//错误理解：
	//只要两个赞的时间间隔小于d，则满足条件 
	
//	//赞的数量 
//	long count=1;//***注***是1不是0 
//	
//	sort(v.begin(),v.end());
//	
//	for(auto it=v.begin();it+1!=v.end();it++)
//	{
//		if(*(it+1)-*it<d)//若两个时间的间隔小于d   
//		{
//			count++;
//		}		
//	}

	//正确理解： 
	//记录的某一时刻开始的d时间段内的赞的数量，
	//在另一个时刻开始的d时间段记录时赞要回到1 

	sort(v.begin(),v.end());
	
	long max_count=1;
	long count=1;
	for(auto it1=v.begin();it1!=v.end();it1++)
	{
		for(auto it2=it1+1;it2!=v.end();it2++) 
		{
			if(*it2-*it1<d)
			{	
				count++;
				max_count=max_count>count?max_count:count;
			}
		}
		
		count=1;
	}		
	
	return max_count;
}
#endif


//8.5 灵能传输 
//***理解有难度*** 
#if 0
#include <iostream>
#include <algorithm>
#include <string.h>//memset()
#define ll long long

using namespace std;

const int N=3e5+3;

ll a[N],s[N];
bool vis[N];
int n;

int main()
{
   int T;
   scanf("%d",&T);
   
   while(T--)
	{
      memset(vis,0,sizeof(vis));
   
	   scanf("%d",&n);
   
	   s[0]=0;
   
	   for(int i=1;i<=n;++i)
		{
         scanf("%lld",&s[i]);
         s[i]+=s[i-1];
      }
      
      ll s0=0,sn=s[n];
      
      if(s0>sn) swap(s0,sn);//前小后大，为方便取数，可避免讨论取数时重复取的问题。 
      	sort(s,s+n+1);
      	
      int l=0,r=n;
      for(int i=lower_bound(s,s+n+1,s0)-s;i>=0;i-=2)
		{
         a[l++]=s[i],vis[i]=1;
      }
      
      for(int i=lower_bound(s,s+n+1,sn)-s;i<=n;i+=2)
		{
         a[r--]=s[i],vis[i]=1;
      }
      
      for(int i=0;i<=n;++i)
		{
         if(!vis[i]) 
				a[l++]=s[i];
      }
      
      ll res=0;
      
		for(int i=1;i<=n;++i)
         res=max(res,abs(a[i]-a[i-1]));
         
      printf("%lld\n",res);
   }
   return 0;
}
#endif


//8.6 双向排序 
#if 1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool mycompare(const long& a,const long& b);

int main()
{
	//序列长度，操作次数
	long n,m;
	cin>>n>>m;
	
	vector<long>v1;
	for(long i=0;i<=n;i++)//0~n，为了与序列的下标对应，
		v1.push_back(i);	 //索引0的元素不使用 
	
//	for(auto x:v1)
//		cout<<x<<" ";			
//	cout<<endl;
	
	//使用new创建二维数组
	long (*caozuo)[3]=new long[m+1][3]; 
	
	fill(&caozuo[0][0],&caozuo[0][0]+(m+1)*3,0L);
	
	for(long i=1;i<=m;i++)
	{
		cin>>caozuo[i][1]>>caozuo[i][2];
	}
	
	int i=1;
	while(m--)
	{		
		if(caozuo[i][1]==0)//***注***sort()是对[)范围排序 
			sort(&v1[1],&v1[caozuo[i][2]]+1,mycompare);
	
		if(caozuo[i][1]==1)
			sort(&v1[caozuo[i][2]],&v1[n]+1);	
				
		i++;
		
		for(auto x:v1)
			cout<<x<<" ";			
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
		cout<<v1[i]<<" ";

	delete []caozuo;

	return 0;
}  
bool mycompare(const long& a,const long& b)
{
	return a>b;
}
//3 3
//0 3
//1 2
//0 2
#endif































