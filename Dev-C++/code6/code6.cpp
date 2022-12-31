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
	
	//入口标记为已访问
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
	//选另一个方向再次进行路径搜索 
	} 
	
}
#endif 


//6.3 组队 
#if 0
#include <iostream>
#include <vector>

using namespace std;
bool mark[20];

//1号位至5号位的各个球员的评分存入vector 
	
//***错误写法*** 
//	vector<int> rates(20) [5];
vector<int> rates[5];

int max_sum;

int max(int a,int b);
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
	cout<<max_sum<<endl;

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

//***形参选择第x号位和临时的数字和 
void dfs(int num,int sum)
{
	if(num>4)//num从0到4共有5号位 
	{
//		cout<<sum<<endl;
		max_sum=max(max_sum,sum);
		return;
	}		
	
	for(int i=0;i<20;i++)
	{
		if(!mark[i])
		{
			mark[i]=1;
//***注***
//特别注意要完成递归时，应该把递归更新的条件都
//写在被调函数的括号内，而不是在函数外处理好后
//再写在被调函数的括号内 
//			sum+=rates[num][i];
//       dfs(num+1,sum);

			dfs(num+1,sum+rates[num][i]);
			
			mark[i]=0;
		}
		else
			continue;
	}
	return;
}

int max(int a,int b)
{
	return (a>b)?a:b;
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


//6.4 全球变暖 
#if 0
#include <iostream>

using namespace std;

bool mark[1000][1000];
char picture[1000][1000];
int N;

void dfs(int a,int b);
int main()
{
	cin>>N;
	
	char data[N][N];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin>>data[i][j];
		} 
	
	//把data数据放到picture[1][1]开始的位置 
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			picture[i+1][j+1]=data[i][j];		
		}
		
	//如何计算岛屿数量？
	
	mark[1][1]=1;
	dfs(1,1);
	
	int count=0;
	for(int i=1;i<N+1;i++)
		for(int j=1;j<N+1;j++)	 
		{
			if(picture[i][j]=='#')
			count++;
		}
		
	cout<<count;
		
	return 0;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

void dfs(int x,int y)
{
	if(x==7&&y==7)						//------>x轴 
	{										//|
		cout<<"Done! "<<endl;		//|
		return;							//∨ y轴 
	}
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(picture[nx][ny]=='.'&&mark[nx][ny]==0)
		{
			mark[nx][ny]=1;
			
			cout<<"("<<nx<<","<<ny<<")"<<" ";
			//1颗海水淹没4个方向的陆地，将淹没标记为* 
			if(picture[nx][ny+1]=='#')
			picture[nx][ny+1]='*';	
			
			if(picture[nx][ny-1]=='#')		
			picture[nx][ny-1]='*';
			
			if(picture[nx-1][ny]=='#')
			picture[nx-1][ny]='*'; 
			
			if(picture[nx+1][ny]=='#')
			picture[nx+1][ny]='*';
			
			dfs(nx,ny);		
		}
//	cout<<"ok\n";
	} 
}  
//7
//. . . . . . .
//. # # . . . .
//. # # . . . .
//. . . . # # .
//. . # # # # .
//. . . # # # .
//. . . . . . .
#endif
//改正：
//***思路***
//对#进行搜索，找到后对其进行dfs搜索，看其周围是否有陆地
//都有，则flag置1 
#if 0
#include<iostream>
#include<string>
 
using namespace std;

const int maxn=1005;
int mark[maxn][maxn];

string island[maxn];
int n,flag,sum;

void dfs(int x, int y);

int main()
{
   cin >> n;
   for(int i = 0; i < n; ++i)
   cin >> island[i];
   
   for(int i = 0; i < n; ++i)
   {
       for(int j = 0; j < n; ++j)
       {
           if(island[i][j] =='#'&&mark[i][j]==0)
           {
               flag=0;
               dfs(i,j);
               if(!flag)//如果flag=0,表示在这个岛屿中没有找到合适的，最终会消失,sum累加没有找到的。 
               ++sum;	//如果flag=1,表示在这个岛屿中找到了合适的，这是将flag置为1。 
           } 
       }
   }
   cout<<sum;
   return 0;
}
 
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1}; 
void dfs(int x, int y)
{
	//标记走过的陆地 
   if(island[x][y] =='#'&&!mark[x][y])
       mark[x][y] = 1;
   else
       return;
       
   //判断是否符合条件 
   if(island[x][y+1]=='#'&&island[x][y-1]=='#'
	&&island[x+1][y]=='#'&&island[x-1][y]=='#')
   flag = 1;
   
   //上下左右搜索  
	for(int i=0;i<4;i++)
	{
		dfs(x+dx[i],y+dy[i]);
	}
} 
#endif


//6.5 迷宫 
//***思路***
//BFS模板 
//queue<type> q;
//q.push(初始状态);
//while (!q.empty())
//{
//  type t = q.front() ;
//  q.pop();
//  遍历 t 的各个Next状态  next
//  { 
//    if (next is legal)
//      q.push(next的状态); 计数或维护等; 
//  } 
//}

#if 1
#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int ROW=30,COL=50;
char migong[ROW][COL+1];
bool mark[ROW][COL];

//结构体node记录xy坐标和走的顺序
struct node
{
	int x;
	int y;
	string s;
};

struct node create_node(int x,int y,string s)
{
	struct node temp;
	temp.x=x;
	temp.y=y;
	temp.s=s;
	
	return temp;
}
					//向下 向左  向右  向上 
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char zimu[4]={'D','L','R','U'};
bool visited[100][100];

void bfs(int x,int y); 
int main()
{
	freopen("6.5.txt","r",stdin);
	
	for(int i=0;i<ROW;i++)
		cin.getline(migong[i],COL+1);//***每行读COL个字符*** 
	
	bfs(0,0); 
	
	return 0; 
}
void bfs(int x,int y)
{
	queue<node> qn;
	
	qn.push(create_node(0,0,""));
	visited[x][y]=1;
	
	while(!qn.empty())
	{
		node t=qn.front();
		qn.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int xn=t.x+dir[i][0];
			int yn=t.y+dir[i][1];
			
			if(xn>=0&&xn<ROW&&yn>=0&&yn<COL&&
			!visited[xn][yn]&&migong[xn][yn]!='1')
			{
				if(xn==ROW-1&&yn==COL-1)
				{
					cout<<t.s<<zimu[i]<<endl;	//注意也要将zimu[i]一并输出因为此时它还没有被加到t.s
					return;
				}
				else
				{
					visited[xn][yn]=1;//应用了string的+运算符重载函数，拼接字符串 
					qn.push(create_node(xn,yn,t.s+zimu[i]));
				}
			}
		}	
	}
}
#endif



































