//7.1 动态规划
//将待求解的问题分解成若干子问题，按顺序求解子问题 
//前一个子问题的解为后一个子问题的求解提供了有用的信息

//兑换硬币问题 
#if 1
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
