//3.1 枚举法 
//在实际应用中要尽量减少变量的个数以及搜索的空间，
//降低算法的时间复杂度 
#if 0
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//4x+7y=1000000
	int x;
//	int y[5000]={0};  会溢出 
	vector<int>y;
	int temp;
	int index=0;
	for(x=250000; x ;x--)
	{
		temp=(1000000-4*x)/7.0;//***注***.0要写，涉及到的知识点是不同类型的值进行算数运算时，会进行的转换 
		if((1000000-4*x)/7.0>temp)//若temp是个小数 
			continue;
		
		y.push_back(temp);
	}

	for(auto p=y.begin();p!=y.end();p++)
		cout<<*p<<' ';
	
	return 0;
}
#endif


//3.2 等差素数数列 
#if 0
#include <iostream>
#include <vector>
using namespace std;

bool sushu(long num);
int main()
{
	vector<long> num_vector;
	
	for(long num=2;num<50000;num++)
		if(sushu(num))
			num_vector.push_back(num);
	
//	for(auto p=num_vector.begin();p!=num_vector.end();p++)
//	cout<<*p<<" ";
	
	int gongcha=1;
	int k=1;
	int shuliechangdu;
	
	//从第一项开始试 
	for(auto p=num_vector.begin();p!=num_vector.end();p++)
	{
		//三大参数重置为1 
		shuliechangdu=1;
		k=1;
		gongcha=1;
		
		//***修改建议***
		//把公差递增的循环放在循环的最外层 
		while(gongcha<1000)
		{
			//两大参数重置为1 
			shuliechangdu=1;
			k=1;
			
			//从最外层p指向的元素开始试 
			for(auto q=p;q!=num_vector.end();q++)
				if((*p)+gongcha*k==*q)//公差从1开始试 
				{
					shuliechangdu++;
					
					if(shuliechangdu==10)
						goto conclusion;
					
					k++; 
					continue;
				}
			
			//公差增1 
			gongcha++;
		}
	}
	
conclusion:cout<<gongcha;
	
	return 0;
}

bool sushu(long num)
{
	bool status=1;
	
	for(long i=2;i<num;i++)
	{
		if(num%i==0)
			status=0;
	}
	
	return status;
}
#endif
//法二： 
//用埃氏筛选法和求等差数列各项的值的公式 
#if 0
#include <iostream>
using namespace std;

void shengchengsushu(void);
bool ok(int n,int gongcha);

bool flag[10000];
int main()
{
	shengchengsushu();
	
	for(int gongcha=2; ;gongcha++)
	{
		for(int qishizhi=2;qishizhi<10000;qishizhi++)
		{
			if(flag[qishizhi]&&ok(qishizhi,gongcha))
			{
				cout<<gongcha;
				return 0;//***注***可以这样写来替换掉goto语句 
			}
		}
	}

	return 0;
}

void shengchengsushu(void)
{
	//flag数组初始化 
	for(int i=0;i<10000;i++)
		flag[i]=1;
	
	//数组的索引值当成是素数数列的元素，素数数列从2开始 
	for(int i=2;i<10000;i++)
	{
		if(flag[i])
			for(int j=i+i;j<10000;j+=i)
				flag[j]=0;	
	}
}

//判断是否满足长度为10的等差素数数列
//数列的起始值n，数列的公差gongcha
bool ok(int n,int gongcha)
{
	for(int i=0;i<10;i++)
		if(!flag[n+i*gongcha]) 
			return 0;
			
	return 1;//***注***可以直接返回0或1来减少声明的变量数 
} 
#endif


//3.3 乘积尾零 
#if 0
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("3.3.txt","r",stdin);
	
	int count=0;
	
	long temp;
	long long result=1;
	
	char shuzu[100]={'\0'};
	char shuzu2[100]={'\0'};
	int index2=0;
	int weishu;
	
	for(int i=0;i<100;i++)
	{
		cin>>temp;
		result*=temp;

//***注*** 
//数字转化成字符串
//法一：		
//		sprintf(shuzu,"%d",result);
//法二：
//itoa 并不是一个标准的C函数，它是Windows特有的，如果要写跨平台的程序，请用sprintf 
		itoa(result,shuzu,10);
		
		//若result为8800 
		//计算要保留的位数 	
		weishu=1;	//***注***此语句若放在for的int index=0后，不会被执行 
		for(int index=0;shuzu[index];index++)
		{
			if(shuzu[index]=='0')
				weishu++;			
		}
		
		//计算result数字的长度 
		int changdu=0;
		for(int index=0;shuzu[index];index++)
		{
			if(shuzu[index]!='\0')
				changdu++;
		} 
		
		//weishu为3（保留非零的最低位）
		//***注***shuzu2要进行内容清空 
		for(int i=0;i<100;i++)
		{
			shuzu2[i]='\0';
		}
		
		for(int index=0;index!=weishu;index++)
		{
			shuzu2[index]=shuzu[changdu-weishu+index];
		}
		
		//result处理为800 
		result=atoi(shuzu2);
		
		if(result/10==result/10.0)
		{
			count++;
			result/=10;
		}
	}
	
	cout<<count;

//***错误***
//1.若把每次两数相乘之后的值把0截掉，那么值最终
//还是会超出long long能表示的最大范围 
//2.若按上述程序所做的那样，仅保留非零的最低位，那么结果
//还是不正确
 
	return 0;
}
#endif
//改正 
//把每次两数相乘之后的值把0截掉，而且把值始终保持在8位数 
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long temp,result=1;
	int zero=0;
	
	freopen("3.3.txt","r",stdin);
	
	for(int i=0;i<100;i++)
	{
		cin>>temp;
		result*=temp;
		
		while(result%10==0)
		{
			result/=10;
			zero++;
		}
		
		result%=100000000;//result始终保持在8位数 
	}
	cout<<zero; 

	return 0;
}
#endif


//3.4 数的分解 
#if 0
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>//STL的sort() 
using namespace std;

typedef struct s
{
	int x;
	int y;
	int z;
}fenjieTypeDef;

bool operator<(const fenjieTypeDef&,const fenjieTypeDef&);

//set关联集合对元素进行自动排序时不会用到==运算符 
//bool operator==(const fenjieTypeDef&,const fenjieTypeDef&);

int main()
{
	int i,j,k;
	
	fenjieTypeDef fenjieStruct;
	set<fenjieTypeDef> num_set;
	vector<int> v1;
	
	//改正1：
	//判断一个整数是否含2或4 
	char erhuosi[10]={'\0'};
	
	const int NUM=2019;
	for(i=1;i<NUM;i++)
		for(j=1;j<NUM;j++)
			for(k=1;k<NUM;k++)
				if(i+j+k==NUM&&i!=j&&i!=k&&j!=k)//改正2：各不相同的正整数 
				{
//错误理解： 
//					if(i==2||j==2||k==2||i==4||j==4||k==4)
//						continue;
					
					//每个正整数是否含数字2或4的标记					
					int biaoji=0;
					
					itoa(i,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;

					itoa(j,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;
							
					itoa(k,erhuosi,10); 
					for(int i=0;erhuosi[i];i++)
						if(erhuosi[i]=='2'||erhuosi[i]=='4')
							biaoji=1;
																				
					if(biaoji)
					continue;
					
					//每次进入时v1都要清空内容 
					v1.clear();
					
					v1.push_back(i);
					v1.push_back(j);
					v1.push_back(k);
					
					//排序(对vector容器使用sort()) 
					sort(v1.begin(),v1.end());
					
					//按升序赋给x,y,z 
					fenjieStruct.x=v1[0];
					fenjieStruct.y=v1[1];
					fenjieStruct.z=v1[2];		
					
					//自动删掉重复项(利用set关联容器) 
					num_set.insert(fenjieStruct);
				}
	
//	int count=0;			
//	for(auto p=num_set.begin();p!=num_set.end();p++)
//	{	
//		cout<<p->x<<" "<<p->y<<" "<<p->z<<endl;
// 		count++;
//	 }
 	
 	cout<<endl<<num_set.size()<<endl;
 	
	return 0;
}
bool operator<(const fenjieTypeDef& f1,const fenjieTypeDef& f2)
{
	bool b=0;
	
	if(f1.x<f2.x)
		b=1;
	else if(f1.x==f2.x&&f1.y<f2.y) 
		b=1;
	else if(f1.x==f2.x&&f1.y==f2.y&&f1.z<f2.z) 
		b=1;
		
	return b;
}
//bool operator==(const fenjieTypeDef& f1,const fenjieTypeDef& f2)
//{
//	set<int> s1;
//	set<int> s2;
//	
//	s1.insert(f1.x);
//	s1.insert(f1.y);
//	s1.insert(f1.z);
//
//	s2.insert(f2.x);
//	s2.insert(f2.y);
//	s2.insert(f2.z);
//	
//	if(s1==s2)
//	return 1;
//	else
//	return 0;
//}
#endif
//法二： 
#if 0
#include <iostream>

using namespace std;

bool judge(int);
int main()
{
	int count=0;
	
//通过巧妙地设置三个循环的起始值和和终止值来避免出现数字重复
//i,j,2019-i-j三个数以升序的形式生成
 
//	for(int i=1;i<2019/3+1;i++)
//		if(judge(i))				
//			for(int j=i+1;j<2019-i-j;j++)
//				if(judge(j))
//					if(judge(2019-i-j))
//						count++;
		
	//也可以写成				
		for(int i=1;i<2019;i++)
			if(judge(i))
				for(int j=i+1;j<2019-i-j;j++)
					if(judge(j))
						if(judge(2019-i-j))
							count++;
						
	cout<<count;

	return 0;
}
bool judge(int num)
{
	while(num)
	{
		if(num%10==2||num%10==4)//对num从最低位开始判断是否有数字2或4 
			return 0;
		
		num/=10;
	}

	return 1; 
}
#endif


//3.5 特别数之和 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long num;
	cin>>num;
	
	bool flag=0;
	long long result=0;
	for(int i=1;i<=num;i++)
	{
		long long temp=i;
		flag=0;
		while(temp)
		{
			if(temp%10==2||temp%10==0||temp%10==1||temp%10==9)
				flag=1;
				
			temp/=10;
		}
		
		if(flag)
		result+=i;
	}
	
	cout<<result<<endl;

	return 0;
} 
#endif
//法二： 
#if 0
#include <iostream>
#include <vector>  
#include <algorithm>//STL的find()函数 

using namespace std;

bool judge(long );
int main()
{
	long long num;
	cin>>num;
	
	long long result=0;
	for(int i=1;i<=num;i++)
	{
		if(judge(i))
		result+=i;
	}
	
	cout<<result<<endl;

	return 0;
} 
bool judge (long num)
{
	char shuzi[10]={'\0'};
	itoa(num,shuzi,10);
	
	vector<char> shuzi2;
	for(int index=0;shuzi[index];index++)
		shuzi2.push_back(shuzi[index]);

//写法一：		
//	for(auto p=shuzi2.begin();p!=shuzi2.end();p++)
//		if(*p=='2'||*p=='0'||*p=='1'||*p=='9')
//			return 1;
		
//写法二： 
	char ch[4]={'2','0','1','9'};
	for(int index=0;index<4;index++)
		if(find(shuzi2.begin(),shuzi2.end(),ch[index])!=shuzi2.end())
			return 1;
	
	return 0;	
}
#endif


//3.6 完全二叉树的权值 
#if 0
#include <iostream>
#include <cmath>
//#include <valarray>
using namespace std;

typedef int SqBiTree[100];//SqBiTree是顺序存储结构的二叉树类型 

bool InitBiTree(SqBiTree T);
bool CreateBiTree(SqBiTree T); 

int num;
	
int main()
{
	SqBiTree T;
	InitBiTree(T);
	
	CreateBiTree(T);

	int deep;
	deep=log2(num)+1;//***注***n个节点求深度公式 
	
	//创建一个数组，用于存每层的元素之和 
	int* p=new int[deep];
	
	//数组初始化为0 
	for(int i=0;i<deep;i++)
		p[i]=0;
	
	int d=deep;
	
	for(int i=1;i<=d;i++)//第几层 
		for(int j=pow(2,i-1)-1;j<=pow(2,i-1)-1+pow(2,i-1)-1;j++)
			*(p+i-1)+=T[j];
	
	//遍历寻找数组中的最大值对应的索引值，索引值+1就是层号(深度)		
	int max=p[0];
	int result=1;
	for(int i=0;i<deep;i++)
		if(p[i]>max)
		{
			max=p[i]; 
			result=i+1; 
		} 
		
	cout<<result;
		
	return 0;
}

bool InitBiTree(SqBiTree T)
{
	int i;
	for (i = 0; i < 100; i++)
		T[i] = 0; /* 初值为空 */

	return 1;
}
bool CreateBiTree(SqBiTree T)
{
	cin>>num;
	
	for(int index=0;index<num;index++)
		cin>>T[index];	
}
//测试：
//7
//1 6 5 4 3 2 1 
#endif


//3.7 等差数列 
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int size;
	cin>>size;
	
	vector<long long> shuzu(size);
	long long temp;
	for(int i=0;i<size;i++)
	{	
		cin>>temp;
		shuzu[i]=temp;
	}
	
	sort(shuzu.begin(),shuzu.end());
	
//	for(int i=0;i<size;i++)
//		cout<<shuzu[i];

	long long gongcha=shuzu[1]-shuzu[0];

	long long min=shuzu[0];
	long long max=shuzu[0];
	for(int i=0;i<size;i++)
	{
		if(shuzu[i]>max)
			max=shuzu[i];
		if(shuzu[i]<min)
			min=shuzu[i];			
	}
	
	cout<<(max-min)/gongcha+1;
		
	return 0;
} 
#endif


//3.8 跑步训练 
#if 0
#include <iostream>

using namespace std;
int main()
{
	int energy = 10000;
	
	int seconds=0;
	while(1)
	{
		energy-=10;
		seconds++;
		
		if(energy<=0)
			break;
			
		energy+=5;
		seconds++;
	}
	//***错误：理解为了跑一秒钟休息一秒钟 
	cout<<seconds;

	return 0; 
}
#endif
//改正 
#if 0
#include <iostream>

using namespace std;
int main()
{
	int energy = 10000;
	
	int seconds=0;
	while(1)
	{
		if(energy>=600)
		{	
			energy-=600;
			seconds+=60;
		}
		else//当体力小于600时 
		{
			seconds+=energy/10;//(体力每秒下降10点)
			break; 
		}
			
		energy+=300;
		seconds+=60;
	}

	cout<<seconds;

	return 0; 
}
#endif


//3.9 合并检测 
#if 0
#include <iostream>
#include <valarray>
//#include <algorithm>

using namespace std;
int main()
{
	long zongrenshu=10000;
	int ganranrenshu=10000*0.01;
	int k=2;//2人混管 
	int k1=0;
	
	valarray<long> data(998);
	int index=0;
	
	char ch[10]={'\0'};
	
	for(   ;   k<=1000;    k++,k1=0)
	{			
		int temp=zongrenshu/k;//第一次筛查时用了几个试剂盒 
		k1+=temp;		
		
		int temp2;
//错误写法1： itoa即int to a，只支持整数转换成字符串 
//		itoa(temp*0.01,ch,10);

//错误写法2： 
//		sprintf(ch,"%f",temp*0.01);//即使是整除，也会在数字后补零，如50.000000 
//		cout<<ch;
//		if(find(ch,ch+10,'.')!=ch+10)//判断是否是小数 
//			temp2=temp*0.01+1;//第一次有异样的试剂盒数		
//		else
//			temp2=temp*0.01;

		if(temp*0.01>int(temp*0.01))
			temp2=temp*0.01+1;//第一次有异样的试剂盒数		
		else
			temp2=temp*0.01;						
		
		k1+=temp2*k;//k1再加上第二次筛查时要用的试剂盒数 
		
		data[index++]=k1;
	}
	
	for(int index=0;index<998;index++)
		cout<<data[index]<<" ";
		
	cout<<endl<<data.min()<<endl;
	
	int result;
	for(int index=0;index<998;index++)
		if(data[index]==data.min())
			result=index;

	cout<<"索引值："<<result;//得到：           10000个人，110个人混管最节省试剂盒，为200盒 
	
//***疑问***
//人数的不同，会影响程序模拟得到的试剂盒最小值 
//***错误 
//没有考虑类似10000个人3人混管的情况要去除 

	return 0;
}
#endif
//改正 
#if 0
#include <iostream>
#include <valarray>
#include <map> 
//#include <iterator>
using namespace std;
int main()
{
	long zongrenshu=100;
	int k=2;//2人混管 
	int k1=0;
	
	map<long,long> data_map;
	
	for(   ;   k<=100;    k++,k1=0)
	{			
		int temp=zongrenshu/k;//第一次筛查时用了几个试剂盒 
		
		//检查是否整除 
		if(zongrenshu/(double)k>temp)
			continue;
		
		k1+=temp;		
		
		int temp2;
		//再检查是否整除 
		if(temp*0.01>int(temp*0.01))
			temp2=temp*0.01+1;//第一次有异样的试剂盒数		
		else
			temp2=temp*0.01;						
		
		k1+=temp2*k;//k1再加上第二次筛查时要用的试剂盒数 
		
		//向map中存数据方法一： 
		//***数组表示法***
		data_map[k]=k1;
		//方法二： 
//		data_map.insert(pair<long,long>(k,k1));
	}
	
	//***map关联容器的遍历方法***
	for(auto p=data_map.begin();p!=data_map.end();p++)
	{
		cout<<p->first<<' '<<p->second<<endl;
	}
	
	//寻找试剂盒数最少的数字
	map<long,long>::iterator di;
	di=data_map.begin();
	long min=di->second;	
	for(auto p=data_map.begin();p!=data_map.end();p++)
	{
		if(p->second<min)
		{	
			min=p->second;
			di=p;//暂存p的值 
		} 
	}
	
	cout<<endl<<di->first<<" "<<min;

//***错误***只能通过键来寻找元素，而不能通过元素来寻找键	
//	auto search = data_map.find(min);
//   if (search != data_map.end()) 
//	{
//      cout << "Found " << search->first << " " << search->second << '\n';
//   }

	return 0;
}
#endif


//3.10 直线 
//***思路***
//方程Ax+By+C=0能表示所有直线(包括垂直于x轴的直线)
//可以利用直线的两点式推出A、B、C对应的表达式 
#if 0
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

//求最大公约数(A、B、C三个数同时乘以一个非0的倍数，
//还是表示同一条直线，但这种情况set无法去重)
int measure(int ,int); 

using namespace std;
int main()
{
	int x,y;//坐标的范围 
	cin>>x>>y;
	
	pair<int,int> pa;
	vector<pair<int,int>>v;//以坐标点为元素，存入vector对象 
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++) 
		{
			pa.first=i;
			pa.second=j;
			v.push_back(pa);
		}
		
	pair<pair<int,int>,int> pa2;
	set<pair<pair<int,int>,int>>s;//好处：不用重新定义<运算符重载函数 
	//或声明一个结构布局，存3个变量 
	//set<jiegou_TypeDef>s;
	 
	for(int i=0;i<v.size();i++)//取一个点 
		for(int j=i+1;j<v.size();j++)//取另一个点 
		{
			int x1=v[i].first;
			int y1=v[i].second; 
			int x2=v[j].first;
			int y2=v[j].second;
			
			int A=y2-y1;
			int B=x1-x2;
			int C=x2*y1-x1*y2;
			
			int gongyueshu=measure(measure(A,B),C);
			
			pa.first=A/gongyueshu;
			pa.second=B/gongyueshu;
			pa2.first=pa;
			pa2.second=C/gongyueshu;
			
			s.insert(pa2); 
		} 
		
	cout<<s.size();

	return 0;
} 

int measure(int a,int b)
{
//	if (b==0)
//		return a;
//	else 
//	   return measure(b,a%b); 

	//法二：algorithm头文件中包含的__gcd() 
	return __gcd(a,b);
	
	//补充：最小公倍数=两数乘积/最大公约数
}
 /* 辗转相除法基于如下原理：
    两个整数的最大公约数等于其中较小的数和两数的相除的余数的最大公约数
	 那y和x%y如果余数为0，那y不就是最大公约数
    补充：两个数的最小公倍数等于  x*y/measure(x,y);
*/
#endif


//3.11 货物摆放 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num=2021041820210418;
	
	long long count=0;
//	for(int i=1;i<=num;i++)
//		for(int j=1;j<=num;j++)
//			for(int k=1;k<=num;k++)
//			{
//				if(i*j*k==2021041820210418)
//				count++;
//			}

	for(long long i=1;i<=num;i++)
		for(long long j=1;j<=num;j++)
		{
			long long k=num/i/j;
			
			if(k>num||k<1||((double)num/i/j)>k)
			continue; 
			else
			{ 
				cout<<i<<' '<<j<<' '<<k<<' '<<endl;
				count++;		
			}
		
		}
//***错误***
//严重超时 

	cout<<count;		
			
	return 0;
} 
#endif
//改正 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num=2021041820210418;
	
	long long count=0;

	//求出num的因子，并存入数组 
	long long a[1000]={0}; 
	
	//***补充知识***
	//若num的因子的集合为A，
	//则a*b*c=num，a、b、c均来自集合A 
	
	int index=0;
	for(long long i=1;i*i<=num;i++)
	{
		if(num%i==0)//若i是因子 
		{
			a[index++]=i; 
			
			//***注***以下语句必须写 
			if(num/i!=i)
				a[index++]=num/i;//存入num/i即因子的较大者 
		} 
	} 
	
	cout<<"index="<<index<<endl; 

	for(int i=0;i<index;i++)
		for(int j=0;j<index;j++)
			for(int k=0;k<index;k++)
			{
				if(a[i]*a[j]*a[k]==num)
					count++;
			}	
			
	cout<<count;		
			
	return 0;
} 
#endif
//法二：使用set关联容器 
#if 1
#include <iostream>
#include <set>

using namespace std;
int main()
{
	long long num=2021041820210418;
	
	long long count=0;

	//求出num的因子，并存入数组 
	set<long long>a; 
	
	//***补充知识***
	//若num的因子的集合为A，
	//则a*b*c=num，a、b、c均来自集合A 
	
	int index=0;
	for(long long i=1;i*i<=num;i++)
	{
		if(num%i==0)//若i是因子 
		{
			a.insert(i);//计算到900000009后面的数字时会非常慢 
//							//所以才需要i*i<num这一判断条件 
			a.insert(num/i); 
		} 
	} 
	
	for(auto p=a.begin();p!=a.end();p++)
	cout<<*p<<endl; 

	for(auto i=a.begin();i!=a.end();i++)
		for(auto j=a.begin();j!=a.end();j++)
			for(auto k=a.begin();k!=a.end();k++)
			{
				if((*i)*(*j)*(*k)==num)
					count++;
			}	
			
	cout<<count;		
			
	return 0;
} 
#endif



























