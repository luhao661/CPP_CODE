//7.1 动态规划
//将待求解的问题分解成若干子问题，按顺序求解子问题 
//前一个子问题的解为后一个子问题的求解提供了有用的信息
//建立状态转移方程
//考虑初始条件和边界情况 

//兑换硬币问题 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=65535;
int main()
{
	int n=21;
	int a[3]={2,5,9};
	
	int cc[21];//0~21为要得到的硬币总面值 
	
	cc[0]=0;
	for(int i=1;i<=n;i++)//硬币的总面值 
	{
		cc[i]=MAX;//先默认凑不出 
		for(int j=0;j<=2;j++)
		{
			//总面值大于等于现有的硬币的面值且
			//总面值减去现有面值后还能够按之前的情况凑得 
			if(i>=a[j]&&cc[i-a[j]]!=MAX)
				cc[i]=min(cc[i-a[j]]+1,cc[i]);//algorithm头文件中的min() 
		}
	}
	lower_bound
	cout<<cc[21]<<endl;

	return 0;
}
#endif 
//***注***
//algorithm头文件中实用的函数：
//min()、max()、abs()
//swap()、reverse()、sort() 
//find()、upper_bound()、lower_bound()
//fill()、count()、foreach() 
//__gcd()
//set_intersection()、set_union()、set_difference() 
//next_permutation()

//0-1背包问题 
#if 1
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int num_items,num_weight;
	
	int value[100][100];
	int w[100],v[100];//存重量，存价值

	cin>>num_items>>num_weight;
	
	for(int i=0;i<num_items;i++)
		cin>>w[i]>>v[i];
		
	fill(value[0],&value[0][num_weight],0); 

//	for(int i=0;i<=num_weight;i++)
//		cout<<value[0][i]<<" ";

	
	
	return 0;
} 
#endif
 
























