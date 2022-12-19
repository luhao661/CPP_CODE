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
//相当于数字用26进制来表示 
#if 1
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;
	
	while(cin>>num)
	{
		vector<int> data;
		
		while(num!=0)
		{
			data.push_back(num%26);

			num/=26;
		}
		
		//***注***写成
//		for(auto i=data.end()-1;i>=data.begin();i--)//也可以 
		for(auto i=data.rbegin();i!=data.rend();i++)
		cout<<*i;
		
		//以上已经转化成二十六进制表示 
		
		
		cout<<endl;
	}
	
	return 0;
}
#endif









