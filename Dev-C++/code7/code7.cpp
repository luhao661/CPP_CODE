//7.1 动态规划
//将待求解的问题分解成若干子问题，按顺序求解子问题 
//前一个子问题的解为后一个子问题的求解提供了有用的信息
//***先尝试写dp表格，再尝试建立状态转移方程***
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


//01背包问题 
//有N件物品和一个最多能存重量为W的背包。
//第i件物品的重量是weight[i]，得到的价值是value[i]
//***每件物品只能用一次***，
//求解将哪些物品装入背包里物品价值总和最大。 
#if 0
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
	
	//***注***
	//根据dp(dynamic programming动态规划)的
	//状态转移方程，后面会出现
	//i-1的索引值的情况，所以此处将索引设置
	//从1开始比较好 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//处理第一行： 
	//二维数组的第一行全为0，表示第0件物品放入重量为
	//0~num_weight的背包，价值为0	
	fill(value[0],&value[0][num_weight],0); 

//	for(int i=0;i<=num_weight;i++)
//		cout<<value[0][i]<<" ";

	//第x件物品是否放入背包
	for(int i=1;i<=num_items;i++)
	{
		//处理第一列： 
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
			value[i-1][j-w[i]]+v[i]);
			//若不装第i件物品，则
			//价值是装第i-1件物品在容量为j的
			//背包时的价值；
			//若装第i件物品，则
			//价值是装第i-1件物品在容量为j-w[i]的
			//背包时的价值加上第i件物品的价值 
			
			//比较不装入第x件物品，和装入第x件物品后， 
			//两种选择下的价值，取最大值	
		} 												
	}
	
	//输出num_items件物品放入num_weight容量的
	//背包，价值最大是多少 
	cout<<value[num_items][num_weight]<<endl;
	
	//遍历dp表 
	for(int i=0;i<=num_items;i++)
	{	for(int j=0;j<=num_weight;j++)
		{
			printf("%4d",value[i][j]); 
		}
		cout<<endl;
	}
	
	//显示num_items件物品放入num_weight容量的
	//背包，价值最大时放入的是哪几件物品 
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
	cout<<num_items; 
	
	return 0;
} 
//5 10
//5 10
//3 5
//4 8
//4 9
//2 6
#endif
//dp二维数组的改进：(优化空间复杂度)
//将二维数组压缩成一维数组，
//每次循环都是对一维数组中元素的值的【刷新】 
//value[i][j]=
//			max(value[i-1][j],
//			value[i-1][j-w[i]]+v[i]); 
			
//value[j]=
//			max(value[j],
//			value[j-w[i]]+v[i]);
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  物品个数  背包总质量 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//存重量，存价值

	cin>>num_items>>num_weight;
	
	//***注***
	//根据dp(dynamic programming动态规划)的
	//状态转移方程，后面会出现
	//i-1的索引值的情况，所以此处将索引设置
	//从1开始比较好 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//一维数组元素都先赋值为0 
	fill(value,value+100,0); 

	//第x件物品是否放入背包
	for(int i=1;i<=num_items;i++)
	{
		//处理第一列： 
		//第x件物品放入重量为0的背包，价值为0 
		value[0]=0;
		
		//第x件物品放入重量为1~num_weight的背包
		//***注***
		//循环次序必须为逆序 
		//覆盖时要从后往前覆盖
		//因为更新元素值时要用到数组前面的数(旧数据) 
		for(int j=num_weight;j>=1;j--)
		{	
			//若背包当前重量(容量)大于等于第x件物品的重量 
			if(j>=w[i])
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//比较不装入第x件物品，和装入第x件物品后， 
		} 							  //两种选择下的价值，取最大值				
	
		//显示每次状态更新后的dp表 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//输出num_items件物品放入num_weight容量的
	//背包，价值最大是多少 
	cout<<value[num_weight]<<endl;
	
	//显示最新状态的dp表 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
#endif


//完全背包问题 
//有N件物品和一个最多能存重量为W的背包。
//第i件物品的重量是weight[i]，得到的价值是value[i]
//***每件物品可以无限使用***，
//求解将哪些物品装入背包里物品价值总和最大。
//思考： 
//无限其实有上限，上限为当前背包容量
//除以该物品的重量。因此得到
//朴素完全背包算法 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  物品个数  背包总质量 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//存重量，存价值

	cin>>num_items>>num_weight;
	
	//***注***
	//根据dp(dynamic programming动态规划)的
	//状态转移方程，后面会出现
	//i-1的索引值的情况，所以此处将索引设置
	//从1开始比较好 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//一维数组元素都先赋值为0 
	fill(value,value+100,0); 

	//第x件物品是否放入背包
	for(int i=1;i<=num_items;i++)
	{
		//处理第一列： 
		//第x件物品放入重量为0的背包，价值为0 
		value[0]=0;
		
		//第x件物品放入重量为1~num_weight的背包
		//***注***(小技巧) 
		//覆盖时要从后往前覆盖
		//因为更新元素值时要用到数组前面的数 
		for(int j=num_weight;j>=1;j--)
		{	
			//第i个物品从1件开始拿，
			//拿到j/w[i]件为止 
			for(int k=1;k<=j/w[i];k++) 
			{
				//若背包当前容量大于等于k个第x件物品的重量 
				if(j>=k*w[i])
				value[j]=
				max(value[j],
				value[j-k*w[i]]+k*v[i]);
			}
		} 									
	
		//显示每次状态更新后的dp表 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//输出num_items件物品放入num_weight容量的
	//背包，价值最大是多少 
	cout<<value[num_weight]<<endl;
	
	//显示最新状态的dp表 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
//4 10
//2 1
//3 3
//4 5
//7 9
#endif
//朴素完全背包算法改进：
//写dp表，推导状态转移方程
//***注***
//发现01背包的状态转移方程与完全背包的一致(见书P121) 
//将二维dp数组优化成一维数组 
#if 0
#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	//  物品个数  背包总质量 
	int num_items,num_weight;
	
	int value[100];
	int w[100],v[100];//存重量，存价值

	cin>>num_items>>num_weight;
	
	//***注***
	//根据dp(dynamic programming动态规划)的
	//状态转移方程，后面会出现
	//i-1的索引值的情况，所以此处将索引设置
	//从1开始比较好 
	for(int i=1;i<=num_items;i++)
		cin>>w[i]>>v[i]; 
	
	//一维数组元素都先赋值为0 
	fill(value,value+100,0); 

	//第x件物品是否放入背包
	for(int i=1;i<=num_items;i++)
	{
		//处理第一列： 
		//第x件物品放入重量为0的背包，价值为0 
		value[0]=0;
		
		//第x件物品放入重量为1~num_weight的背包
		//***注***
		//循环次序必须为顺序 
		//覆盖时要从前往后覆盖
		//因为更新元素值时要用到新的数据
		#if 0 
		for(int j=1;j<=num_weight;j++)
		{	
			//若背包当前重量(容量)大于等于第x件物品的重量 
			if(j>=w[i])
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//比较不装入第x件物品，和装入第x件物品后， 
		} 							  //两种选择下的价值，取最大值				
		#endif
	
		//再次优化： 
		for(int j=w[i];j<=num_weight;j++)
		{	
			value[j]=
			max(value[j],
			value[j-w[i]]+v[i]);//比较不装入第x件物品，和装入第x件物品后， 
		}
	
		//显示每次状态更新后的dp表 
		for(int k=0;k<=num_weight;k++)
			printf("%4d",value[k]);
		cout<<endl;	 
	}
	
	//输出num_items件物品放入num_weight容量的
	//背包，价值最大是多少 
	cout<<value[num_weight]<<endl;
	
	//显示最新状态的dp表 
	for(int j=0;j<=num_weight;j++)
	{
		printf("%4d",value[j]); 
	}
	
	return 0;
} 
#endif 


//7.2 包子凑数
//***思路***
//题目说明了每笼包子的个数，但是每种蒸笼的笼子
//是无限的，由此想到完全背包问题。如果要凑出
//包子数，则要满足a1x1+a2x2+a3x3+…+anxn=c，
//这类不定方程。
//结论：对于n维的式子，如下：
//a1x1+a2x2+a3x3+…+anxn=c，如果a1,a2,a3…an
//互质，则x1,x2,x3…xn一定有解且有无穷多个 
//但当x1,x2,...xn>=0且都为整数时,导致方程解的个数有限，
//或无解。 
//如果a1,a2,a3…an不互质,那么就有无穷多个c使得
//方程无解。
//若最大公约数不为1，则有无限个凑不出
//若最大公约数为1，则需考虑用完全背包思想解题
#if 0
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	//不同蒸笼的数量 
	int N;
	cin>>N;
	
	//不同蒸笼含的包子个数 
	int zhenglong[N]={0};
	
	//第x个蒸笼含的包子个数 
	for(int i=1;i<=N;i++)
		cin>>zhenglong[i];
	
	int gongyinshu;
	for(int i=1;i<N;i++)
	{
		gongyinshu=__gcd(zhenglong[i],zhenglong[i+1]);
	} 
	
	if(gongyinshu!=1)
	{
		cout<<"INF";
		return 0;
	}
	
	int dp[20000];
	fill(dp,dp+20000,0);
	
	//***注***
	//完全背包问题的背包的价值，对应
	//此题dp[x]的0或1，
	//能拿到要求的包子数就是1，不能就是0 
	
	//要0个包子肯定能凑出 
	dp[0]=1;
	
	//第x笼 
	for(int i=1;i<=N;i++)
	{
		//当前要的包子数 
		for(int j=1;j<=20000;j++)
		{
			//若当前要的包子数大于等于第x笼含的包子数 
			if(j>=zhenglong[i])
				dp[j]=max(dp[j],dp[j-zhenglong[i]]);//完全背包问题的优化写法 
		}
	}

	int count=0;
	for(int i=0;i<20000;i++)
	{
		if(!dp[i])
			count++;
	}
	cout<<count;

	return 0;
}
#endif
//法二：
//for(int i=1;i<N;i++)
//	for(int j=0;j<20000;j++) 
//	{
//		if(dp[j])
//			dp[j+zhenglong[i]]=1;
//	}


//7.3 K倍区间 
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	int N,K;
	cin>>N>>K;
	
	vector<int>shulie(N+1);
	for(int i=1;i<=N;i++)
		cin>>shulie[i];	
	
	int count=0;	
	//从第1个数到第N个数 
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++)//第i个数到第i个数到第N个数 
		{
			int sum=0;
			
			//若只取一个数 
			if(i==j)
			{
				if(shulie[i]%K==0)
				count++;
			}
			else//若取2至j-i+1个数 
			{ 
				int temp=i;
				
				do
				sum+=shulie[temp];
				while(temp++!=j);
				
				if(sum%K==0)
					count++;
			}
		} 

	cout<<count;

	return 0;
}
//5 2
//1
//2
//3
//4
//5
#endif


//7.4 测试次数 
//***思路***
//要兼顾最坏运气与最佳策略 
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1000;

int main()
{
	//创建一部手机，两部手机，三部手机
	//从第一层到第N层测试的dp数组 
	int dp[4][N+1];	

//***注***
//用fill()对二维数组赋值 
//错误的参数填法 
//	fill(&dp[0][0],&dp[4][N+1],0);
//正确的填法 
//	fill(&dp[0][0],&(dp[0][0])+4*(N+1),0);

	//将扔手机的次数赋值为楼层数(即都只用一部手机的情况) 
	for(int i=1;i<=3;i++)
		for(int j=0;j<=N;j++)
			dp[i][j]=j;
		
	//有i部手机 
	for(int i=2;i<=3;i++)
	{	
		//要测第j层 
		for(int j=1;j<=N;j++)
		{
			//在测第k层楼时 
			for(int k=1;k<=j;k++)
				dp[i][j]=
				//在最坏的运气下选最优的决策(选最少的测试次数) 
				min(dp[i][j],
				//取最坏的运气   +1:表示已经经过一次测试 
				1+max
				//手机摔坏，待测1~k-1层 
				(dp[i-1][k-1],
				//手机没坏，待测k+1~j层，共j-(k+1)+1层 
				dp[i][j-(k+1)+1]));
		} 
	}
	
	cout<<dp[3][N];

	return 0;
}
#endif


//7.5 矩阵 
//***不理解*** 
#if 0
#include <iostream> 

using namespace std;
int dp[2030][1020];

int main()
{
	int n=2020;
	
   dp[1][1]=1;
   
   //当前用了i个数字 
   for(int i=2;i<=n;i++)
   {
      for(int j=1;j<=i;j++)
      {
         dp[i][j]+=dp[i-1][j-1];
         
         if(i-j<=j)
			   dp[i][j]+=dp[i-1][j];
			   
			dp[i][j]%=n;
      }
   }
   
   printf("%d\n",dp[2020][1010]);
   return 0;
}
#endif


//7.6走方格 
#if 0
#include <iostream>
#include <algorithm>

using namespace std;

long dp[10000][100];

int main()
{
	long n,m;
	cin>>n>>m;
	
	//第一行走法只有一种 
	fill(&dp[1][1],&dp[1][1]+99,1);
	
	//从第二行开始 
	for(int i=2;i<=n;i++)
	{  
		//第i行第一列走法只有一种 
		dp[i][1]=1;
		//从第i行第二列开始 
		for(int j=2;j<=m;j++)
		{
			//当i、j均为偶数 
			if(i%2==0&&j%2==0)
				dp[i][j]=0;
			//当待计算元素的前面一个元素为0 
			else if(dp[i][j-1]==0)
			{
				dp[i][j]=dp[i-1][j];
			}
			//当待计算元素的上面一个元素为0 
			else if(dp[i-1][j]==0)
			{
				dp[i][j]=dp[i][j-1];	
			}
			//当待计算元素前面一个元素和上面一个元素均不为0
			else
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}			 
		}
	}	
	
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//			printf("%6d",dp[i][j]);
//		cout<<endl;
//	}

	cout<<dp[n][m];
	
	return 0;
}
#endif


//7.7 砝码称重 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[110][200010];

int main()
{
	int N;
	cin>>N;
	
	vector<int> fama(N+1);
	
	for(int i=1;i<=N;i++)
		cin>>fama[i];		
		
	//第i个砝码 
	for(int i=1;i<=N;i++)
	{
		//上一行的数据拷贝到当前行 
		for(int j=1;j<=200010;j++)
		{
			dp[i][j]=dp[i-1][j];
		}
		
		//记录1~i个砝码能表示的最大质量 
		int Max=0;
		for(int index=1;index<=i;index++)
			Max+=fama[index];
		
		//要凑的质量 
		for(int j=1;j<=Max;j++)
		{
			if(j==fama[i])
				dp[i][j]=1;
				
			if(fama[i]-j>=1&&dp[i-1][fama[i]-j])
				dp[i][j]=1;
			
			if(j-fama[i]>=1&&dp[i-1][j-fama[i]])
				dp[i][j]=1;
		} 
	}
	
//	for(int i=0;i<=N;i++)
//	{
//		for(int j=0;j<=15;j++)
//			printf("%6d",dp[i][j]);
//		cout<<endl;
//	}	
	 
	int count=0;
	for(int j=0;j<=200010;j++)
		if(dp[N][j])
			count++;
	
	cout<<count;			
	 
	return 0;
}
#endif


//7.8 括号序列 
//***不理解*** 
#if 0
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin>>str;

	string::iterator p;
	int l_count=0,r_count=0;
	for(p=str.begin();p!=str.end();p++)
	{
		if(*p=='(')
			l_count++;
		if(*p==')')
			r_count++;
	}
	
	cout<<l_count<<" "<<r_count;	

	return 0;
} 
#endif
























