#include <iostream>

//1.
//表示二进制数字 
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	char erjinzhi[32];
	char temp;
	for(int i=31;i>=0;i--)
	{
		temp = (0x01&shijinzhi)+'0';//***注***此处括号一定要加 
		cout<<temp;
		erjinzhi[i]=temp;
		shijinzhi>>=1;	//此处编译器是做循环右移处理	
	}
	
	for(int i=0;i<32;i++)
	{
		cout<<erjinzhi[i];
	}
	
	return 0;
}
#endif
//法二：
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	char erjinzhi[32]={'0'};
	int i=0;
	while(shijinzhi)
	{
		erjinzhi[i++]=shijinzhi%2+'0'; 
		shijinzhi/=2;		
	}
	
	for(int i=32;i>=0;i--)
	{
		cout<<erjinzhi[i];
	}
	
	return 0;
}
#endif 


//2.
//将字符转化成整数 
#if 0
#include <string>
using namespace std;

int function(string st);//***注***char类型能自动转换成string 
int main()					//string类型不能自动转换成char 
{
	char data[10];
	
	cin>>data;
	int num=function(data);	
	cout<<num;

	return 0;
}
int function(string st)
{
	int num=0;
	
	for(int i=0;st[i]!='\0';i++) 
	{
		if(st[i]>='0'&&st[i]<='9')		
		num=num*10+st[i]-'0';//***记*** 
	}
		
	return num;	
}
#endif 


//3.
//十进制转换为其他进制 
#if 0
using namespace std;

int main()
{
	int shijinzhi;
	cin>>shijinzhi;
	
	int qitajinzhi;
	cin>>qitajinzhi;
	
	int result[8]={0};//存储除后取余的数字 
	int i=0;
	
	do//采用出口条件循环 
	{
		result[i++]=shijinzhi%qitajinzhi;
		shijinzhi/=qitajinzhi;
		
	}while(shijinzhi!=0);
	
	//逆向输出 
	for(int i=7;i>=0;i--)
	 cout<<result[i];

	return 0;
}
#endif


//4.
//打开文件 
#if 0
#include <fstream>
using namespace std;

int main()
{
	ifstream In;
	In.open("ceshi.txt");
	
	char data[20]={'\0'};
	In>>data;
	
	for(int i=0;i<20;i++)
	{
		cout<<data[i];
	}
	
	return 0;
}
#endif
//法二： 
#if 0
#include <iostream>
using namespace std;

int main()
{
	FILE *In;
	In=fopen("ceshi.txt","r");
	
	if(In==NULL)
	cout<<"error";
	
	//使用getc()	
	char ch = getc( In );
   while( ch != EOF ) {
      printf( "%c", ch );
      ch = getc( In );
    }
    
   rewind(In);//把文件指针移到由stream(流)指定的开始处,
	//同时清除和流相关的错误和EOF标记 
   
	//使用fscanf() 
	char data[20]={'\0'};
	fscanf(In,"%s",data);
		
	for(int i=0;i<20;i++)
	{
		cout<<data[i];
	}
	
	return 0;
}
#endif








