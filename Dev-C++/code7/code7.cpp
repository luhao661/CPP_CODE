//7.1 动态规划
//将待求解的问题分解成若干子问题，按顺序求解子问题 
//前一个子问题的解为后一个子问题的求解提供了有用的信息
//先尝试写表格，再尝试建立状态转移方程
//考虑初始条件和边界情况

//区别于贪心算法
//贪心算法不能保证求得的最后解释最优解，
//贪心算法使用的前提是局部最优解能产生全局最优解 

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
	//  物品个数  背包总质量 
	int num_items,num_weight;
	
	int value[100][100];
	int w[100],v[100];//存重量，存价值

	cin>>num_items>>num_weight;
	
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//二维数组的第一行全为0，表示第0件物品放入重量为
	//0~num_weight的背包，价值为0	
	fill(value[0],&value[0][num_weight],0); 

//	for(int i=0;i<=num_weight;i++)
//		cout<<value[0][i]<<" ";

	//第x件物品是否放入背包
	for(int i=1;i<=num_items;i++)
	{
		//第x件物品放入重量为0的背包，价值为0 
		value[i][0]=0;
		
		//第x件物品放入重量为1~num_weight的背包 
		for(int j=1;j<=num_weight;j++)
		{	
			//若背包当前重量(容量)小于第x件物品的重量，
			//则背包当前容量所存的物品价值仍为上件物品加入后
			//的价值 
			if(j<w[i])			 
			value[i][j]=value[i-1][j];//***注***若没有此句，则会出现部分元素是0的不正常情况
			
			//若背包当前重量(容量)大于等于第x件物品的重量 
			else 
			value[i][j]=
			max(value[i-1][j],
			value[i-1][j-w[i]]+v[i]);//比较不装入第x件物品，和装入第x件物品后， 
		} 									 //两种选择下的价值，取最大值				
	}
	
	cout<<value[num_items][num_weight]<<endl;
	
	for(int i=0;i<=num_items;i++)
	{	for(int j=0;j<=num_weight;j++)
		{
			printf("%4d",value[i][j]); 
		}
		cout<<endl;
	}
	
	//显示10斤背包中放置的物品 
	while(value[num_items][num_weight]!=0)
	{
		if(value[num_items][num_weight]>
		value[num_items-1][num_weight])
		{
			cout<<num_items<<" ";
			num_weight-=w[num_items];
		} 
		
		num_items--;
	} 
	
	return 0;
} 
//5 10
//5 10
//3 5
//4 8
//4 9
//2 6
#endif


//完全背包问题 
#if 0

#endif


//7.2 包子凑数
//***思路***
//若最大公约数不为1，则有无限个凑不出
//若最大公约数为1，则需考虑用完全背包思想解题

//***注***
//01背包：有N件物品和一个最多能存重量为W的背包。
//第i件物品的重量是weight[i]，得到的价值是value[i]
//每件物品只能用一次，
//求解将哪些物品装入背包里物品价值总和最大。 
 
//完全背包：有N件物品和一个最多能存重量为W的背包。
//第i件物品的重量是weight[i]，得到的价值是value[i]
//每件物品可以无限使用，
//求解将哪些物品装入背包里物品价值总和最大。 
 
#if 0
#include <iostream>

using namespace std;
int main()
{


	return 0;
}
#endif
 
























