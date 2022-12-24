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
#if 1
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>//sort() 
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
					
					//改正3：每个正整数都不含数字2或4					
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
					
					//排序 
					sort(v1.begin(),v1.end());
					
					//按升序赋给x,y,z 
					fenjieStruct.x=v1[0];
					fenjieStruct.y=v1[1];
					fenjieStruct.z=v1[2];		
					
					//自动删掉重复项 
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



























