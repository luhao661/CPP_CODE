//1.2 
//购物单
#if 0
#include <iostream>
#include <valarray>
//#include <algorithm> 
using namespace std;

int main ()
{
	freopen("cost.txt","r",stdin);

//***注***错误写法： 
//	valarray<double> jiage[100];
//	valarray<int> zhekou[100];
//正确写法：
	valarray<double> jiage(100);  //默认全为0 
	valarray<int> zhekou(100); 
	
//	double jiage[100]={0.0};
//	int zhekou[100]={};
	
	double a;
	int b;
	int index=0;
	while(cin>>a>>b)
	{
//错误： valarray对象长度不支持动态改变 
//		jiage.push_back(a);
//		zhekou.push_back(b);
		jiage[index]=a;
		zhekou[index]=b;
		index++;
	}
	
	int count=0;//计算商品数量 
	for(int i=0;i<100;i++)
	{
		if(jiage[i])
		count++;
	}
	
//	for(int i=0;i<count;i++)
//	{
//	cout<<jiage[i];
//	}
	 
	valarray<double> result(100);
	for(int i=0;i<count;i++) 
	{
		if(zhekou[i]>0&&zhekou[i]<10)//打9折 
		result[i]=jiage[i]*0.1*zhekou[i];
		else//打88折 
		result[i]=jiage[i]*0.01*zhekou[i];
	}
	
	double sum=result.sum(); 
	cout<<sum;
	
	return 0;
}
#endif


//1.3 
//第几天(判断闰年，即二月是否为29天)
#if 0
#include <iostream>

using namespace std;
bool runnian (int year);

int main()
{
	int year;
	
	cin>>year;
	
	if(runnian(year))
	cout<<"是闰年"<<endl;
	
	return 0;
}
bool runnian (int year)
{
	return(year%4==0&&year%100!=0||year%400==0);
}
#endif


//1.4 明码 
#if 0
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in;
	in.open("1.4.txt");

	vector<int>data[10];//创建二维数组 
	
	int i,temp;
	for(i=0; i<10; i++)
	{
		for(int j=0;j<32;j++)
		{
			in>>temp;
			data[i].push_back(temp);
		}
	}
	
	for(i=0; i<10; i++)
	{
		for(auto p=data[i].begin();p!=data[i].end();p++)
		cout<<*p<<" ";
		
		cout<<endl;
	}
	cout<<endl;
		

	//现在处理的是第几个字 
	int dijigezi=1;

	vector<int> data2[16];//创建一个2*16的二维数组
	int j=0;
	for(i=0;i<32;i++)
	{
		data2[j].push_back(data[dijigezi-1][i]);
		data2[j].push_back(data[dijigezi-1][++i]);
		j++; //换行 
	} 

	//显示十进制表示的字形信息 
	int huanhang=0;	
	for(i=0;i<16;i++)
	for(auto p=data2[i].begin();p!=data2[i].end();p++)
	{
		cout<<*p<<" ";
		huanhang++;
		
		if(huanhang%2==0)
		cout<<endl;
	}

	//***注*** 
	//错误理解：内容全为0 (在C语言中确实是这样)
	char shuzu[16][16]={{'0'},{'0'}};
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
			shuzu[i][j]='0';
	}
	
	int num;

	for(int i=0;i<16;i++)		//***注***此处-1必须写 
	for(auto p=data2[i].begin();p!=data2[i].end()-1;   )
	{
		num=*p;			
		
		//若为负数 
		if(num<0)
		num=256+num;
		 
		int index=7;//除后取余倒读，干脆存储时倒着存，读时顺着读 
		while(num!=0&&index!=0)
		{
			shuzu[i][index--]=num%2+'0';
			num/=2;
		}
		
		p++;
		num=*p;
		
				
		if(num<0)
		num=256+num;
		
		index=15;
		while(num!=0&&index!=8)
		{
			shuzu[i][index--]=num%2+'0';
			num/=2;
		}			
//***负数如何转化成二进制？？ 
//法二：用bitset模板类 
	}
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		cout<<shuzu[i][j];
	cout<<endl;
	}
	
	return 0;
}
#endif


//1.5 年号字符串 
//用字母组合来表示数字 
//***思路***
//相当于数字用26进制来表示 （即0到25） 
#if 0
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;//***注***输入1应显示A，A的索引为0 
	
	while(cin>>num)
	{
		num-=1; //变成索引值 
		
		//使用vector类对象的好处是可以动态调整长度，而且
		//使用数组无法处理没有元素输入的位置的表示 
		vector<int> data;
		
		//***注***要使用出口条件循环，否则输入1时，data无数据输入 
		do
		{
			data.push_back(num%26);

			num/=26;
		}while(num!=0);
		
		
		//***注***写成
//		for(auto i=data.end()-1;i>=data.begin();i--)//也可以 
		for(auto i=data.rbegin();i!=data.rend();i++)
		cout<<*i;
		
		//以上已经转化成二十六进制表示 
		
		
		//***注***
		//二位数、三位数等到除了最低位之外的位都应该在
		//原基础上-1，因为就二位数来说，一般情况下是10开始，
		//而此题要求是00开始。 
		cout.put('\n');
		
		//反向指针通过先递减，再解除写引用
		for(auto i=data.rbegin();i!=data.rend();i++)
		{
			if(data.size()==1) 
			cout<<(char)(*(i)+'A');
			else
			{
				if(i==data.rend()-1)//最低位 ***注***此处-1需要理解 
				cout<<(char)(*(i)+'A');//rend()指向反转序列的超尾，所以-1后指向反转序列的最后一个元素 
				else//高位 
				cout<<(char)(*(i)+'A'-1);
			}
		}
		 
		cout<<endl;
	}
	
	return 0;
}
#endif


//1.6 纪念日 
//计算两个时间的差值 
#if 0
#include <iostream>
using namespace std;

bool runnian (int year);
int main()
{
	long minutes=0;
	
	//计算1922年到2019年的分钟数 
	for(int year=1922;year<=2019;year++)
	{
		if(runnian(year))
		{
			cout<<year<<endl;
			minutes+=366*24*60;
		}
		else
		minutes+=365*24*60;
	}
	
	//1921年7月23日中午12时到12月31日的时间 
	minutes+=9*24*60-12*60+(31+30+31+30+31)*24*60;
	//2020年1月1日到7月1日中午12时的时间
	minutes+=(31+29+31+30+31+30)*24*60+12*60; 
	
	cout<<minutes; 

	return 0;
}
bool runnian (int year)
{
	bool status=0;
	
	if(year%4==0&&year%100!=0||year%400==0)
		status=1;
	
	return status;
}
#endif


//1.7 空间 
#if 0
#include <iostream>
using namespace std;

int main()
{
//	//256MB转化为bits为单位   MB->KB->B->bits
//	long cunchukongjian=256*1024*1024*8;
//	
//	long zhengshu=32;
//	//***注***[Warning] integer overflow in expression [-Woverflow]
//整数溢出警告
//	cout<<cunchukongjian/zhengshu;

	//***注***要使用强制类型转换 
	//256MB转化为bits为单位   MB->KB->B->bits
    long long cunchukongjian =(long long)256 *(long)1024 * (long)1024 * 8;
	
	int zhengshu=32;
	//[Warning] integer overflow in expression [-Woverflow]
	cout<<cunchukongjian/zhengshu;
	return 0;
} 
#endif


//1.8 时间显示 
#if 0
#include <iostream>

using namespace std;

int main()
{
	long long haomiaoshu;
	cin>>haomiaoshu;
	
	long long miaoshu=haomiaoshu/10;//***错误：1秒应该等于1000毫秒 
	
	int hour=(miaoshu/60/60)%24;
	
//	miaoshu-=hour*3600;
	
	int minutes=(miaoshu/60)%60;
	
//	miaoshu-=minutes*60;
	
	int second=miaoshu%60;
	
	//***注***cout实现时分秒不足两位时前导补0较麻烦 
	//可以用printf()的转换说明修饰符实现前导补0 
	cout<<hour<<":"<<minutes<<":"<<second<<endl;

	return 0;
}
#endif
//改正： 
#if 0
#include <iostream>
#include <stdio.h> 

using namespace std;

int main()
{
	long long haomiaoshu;
	cin>>haomiaoshu;
	
	//去除天数数据 
	haomiaoshu%=(24*60*60*1000); 
	
	//去除毫秒，变成秒 
	long long miaoshu=haomiaoshu/1000;
	
	int hour=(miaoshu/60/60)%24;
	
//可不写 
//	miaoshu-=hour*3600;
	
	int minutes=(miaoshu/60)%60;
	
//	miaoshu-=minutes*60;
	
	int second=miaoshu%60;
	
	//法二：
	/*
	second=miaoshu%60;
	miaoshu/=60;
	minutes=miaoshu%60;
	miaoshu/=60;
	hour=miaoshu; 
	*/
	
	//***注***cout实现时分秒不足两位时前导补0较麻烦 
	//可以用printf()的转换说明修饰符实现前导补0 
	printf("%02d:%02d:%02d",hour,minutes,second);
	
	return 0;
}
#endif



















