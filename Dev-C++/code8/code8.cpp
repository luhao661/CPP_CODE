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
#if 1
#include <iostream>
#include <set>
#include <map> 
using namespace std;

int main()
{
	//N条记录，D的时间长度，K个赞 
	long N,D,K;
	cin>>N>>D>>K;
	
//***注***
//不能使用multiset关联容器，
//因为对于此容器来说，值就是键 
//	multiset<pair<long,long>>record;
	
//	for(int i=0;i<N;i++)
//	{
//		long ts,id;
//		cin>>ts>>id;
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
	
	cout.put('\n');
	for(auto p=record.begin();p!=record.end();p++)
	{
		cout<<(*p).first<<" "<<(*p).second<<endl;
	}
	
	set <long> id;
	
	for(auto p=record.begin();p!=record.end();p++)
	{
		//找到含该id的记录的范围 
		auto range=record.equal_range((*p).first); 
		
//		for(auto it=range.first;it!=range.second;it++)
//		cout<<(*it).first<<" "<<(*it).second<<endl;
		
		int count=0;
		//***注***range.second-1无定义 
		//no match for 'operator -'
		for(auto it=range.first;it!=range.second;    )
		{
			//no match for 'operator +'
//			if(it+1<range.second&&*((it+1)).second-(*it).second<D)
//				count++; 

			auto temp=it;
			it++;
			
			if((*it).second-(*temp).second<D)
				count++;
		}
		
		if(count>=K)
			id.insert((*p).first);
	}
	
	for(auto i=id.begin();i!=id.end();i++)
		cout<<*i<<endl;

	return 0;
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
































