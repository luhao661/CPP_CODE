//6.1 搜索算法 
//深度优先遍历(DFS)、广度优先遍历(BFS) 
#if 0
#include <iostream>

using namespace std;

const int XLEN=14,YLEN=17;
int migong [XLEN][YLEN];
int mark[XLEN][YLEN];
int ox,oy;
bool seek_path(int ix,int iy);
int main()
{
	freopen("6.1.txt","r",stdin); 
	
//	int XLEN,YLEN;
//	cin>>XLEN>>YLEN;
	
	for(int i=0;i<XLEN;i++)
		for(int j=0;j<YLEN;j++)
		{
			cin>>migong[i][j];
			mark[i][j]=0;
		}
	
	fclose(stdin);
	freopen("CON","r",stdin);	
	cout<<"入口坐标：";
	int ix,iy;
//	cin>>ix>>iy;
	ix=1;
	iy=0;
	
	//标记为已访问
	mark[1][0]=1; 
	
	cout<<"出口坐标：";

//	cin>>ox>>oy;
	ox=12;
	oy=16;
	
	if(seek_path(ix,iy))
		cout<<"("<<ix<<","<<iy<<")"<<endl;//最后输出入口坐标
	else
		cout<<"ERROR";
		
	return 0;
}

//上下左右 
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
bool seek_path(int ix,int iy)
{
	if(ix==ox&&iy==oy)
		return true;
	
	int m,n;
	
	for(int i=0;i<4;i++)
	{
		m=ix+dx[i];
		n=iy+dy[i];
		
		//如果通，且未被访问过 
		if(migong[m][n]==0&&mark[m][n]==0)
		{
			//标记为已访问过
			mark[m][n]=1;
			
			//递归试探
			if(seek_path(m,n))
			{
				//逆向输出路径坐标
				cout<<"("<<m<<","<<n<<")"<<endl;
				return true;
			} 
		}
		//回溯，换一个方向再试探通向出口的路径 
	}
	
	return false;
}
#endif


//6.2方格分割 
//***思路***
//观察得到每个分割方案都根据点(3,3)对称
//以(3,3)为起点进行DFS 
#if 0
#include <iostream>

using namespace std;
const int N=6;

bool mark[N+1][N+1]; //如果未初始化外部变量，它们会被自动初始化为 0。这一原则也适用于外部定义的数组元素。
void dfs(int x,int y);
int count;

int main()
{	
	//将中心点标记为已访问 
	mark[3][3]=true;
	dfs(3,3);
	cout<<count/4;//旋转对称属于同一种分割法，因此要将结果除以四 

	return 0;
}

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y)
{
	//若有一点已到达边界 
	if (x==0||x==N||y==0||y==N)
	{
		count++;
		return;
	}
	
	for(int i=0;i<4;i++)
	{
		int m=x+dx[i];
		int n=y+dy[i];
		
		if(mark[m][n]==0)
		{
			mark[m][n]=true;
			
			//该点关于(3,3)对称处的点也标记为已访问
			mark[N-m][N-n]=true;
			
			dfs(m,n); 
			
			//该条路径上的点重置为未访问 
			mark[m][n]=false;
			mark[N-m][N-n]=false;			
		}
	} 
	
}
#endif 


//6.3 组队 
#if 1
#include <iostream>
#include <vector>

using namespace std;
bool mark[20];

//1号位至5号位的各个球员的评分存入vector 
	
//***错误写法*** 
//	vector<int> rates(20) [5];
vector<int> rates[5];
	
void dfs(int num,int sum);
int main()
{
	freopen("6.3.txt","r",stdin);
	
	int shuzu[20][6];
	
	for(int i=0;i<20;i++)
		for(int j=0;j<6;j++)
			cin>>shuzu[i][j];			
	
//	for(int i=0;i<20;i++)
//	{	for(int j=0;j<6;j++)	
//			cout<<shuzu[i][j]<<' ';
//		cout<<endl;		
//	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<20;j++)
		rates[i].push_back(shuzu[j][i+1]);
	} 
	
//	for(int i=0;i<20;i++)
//	cout<<rates[0][i]<<' ';

	dfs(0,0); 

	return 0;
} 

//int count=0; 
//int sum;
//void dfs(int num)
//{
//	//问题：如何找到各号位的最高评分的球员且球员不重复？
//	//如何利用递归来计算？ 
//	 
//	if(count>5)
//		cout<<sum<<endl; 
//	
//	//x号位 
//	for(int i=0;i<5;i++)
//	{
//		//各球员评分 
//		for(int j=0;j<20;j++)
//		{
//			if(mark[j]!=1)
//			{
//				mark[j]=1;
//				count++;
//				sum+=rates[i][j];
//			}
//			else
//				continue; 
//		}
//	}
//	
//	
//}

//改正：
//联想走迷宫的程序
//递归结束条件：坐标等于出口坐标
//递归更新的条件：当前坐标
//循环条件：坐标的x轴范围，y轴范围

int sum;
//***形参选择第x号位和临时的数字和 
void dfs(int num,int sum)
{
	if(num>4)//num从0到4共有5号位 
	{
		cout<<sum<<endl;
		return;
	}		
	
	for(int i=0;i<20;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
//			sum+=rates[num][i];
			dfs(num+1,sum+rates[num][i]);
			mark[i]=0;
		}
		else
			continue;
	}
	return;
}

//法二：
//int maxSum = 0;
//            for (int i = 0; i < 20; i++)
//                for (int j = 0; j < 20; j++)
//                    for (int k = 0; k < 20; k++)
//                        for (int h = 0; h < 20; h++)
//                            for (int g = 0; g < 20; g++)
//                                if ((i != j && i != k && i != h && i != g) && (j != k && j != h && j != g)
//                                        && (k != h && k != g) && h != g) {
//                                    int max = team[i][0] + team[j][1] + team[k][2] + team[h][3] + team[g][4];
//                                    if (max > maxSum)
//                                        maxSum = max;
//                                }
 
#endif


































