//2.1 模拟法 
//掌握基本的求最大值的方法 
#if 0
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<int>v1;
	
	int a,b;
	int c;
	while(cin>>a>>b)
	{
		c=a+b;
		v1.push_back(c);
	}
	
	int day=0;
	int day1=0;
	int max=v1[0];
	vector<int>::iterator p;
	for(p=v1.begin();p!=v1.end();p++)
	{
		day++;
		if(*p>max)
		{
			max=*p;
			day1=day;
		}
	}
	
	if(max<=8) 
	cout<<"高兴";
	else
	cout<<"第"<<day1<<"天最不高兴"; 

	return 0;
}
#endif


//2.2 日期问题 
#if 0
#include <iostream>
#include <stdio.h> 
using namespace std;

int main()
{
	int diyibufen,dierbufen,disanbufen;
	
	char temp;
	cin>>diyibufen;
	cin>>temp;
	cin>>dierbufen;
	cin>>temp;
	cin>>disanbufen;
	
//	cout<<diyibufen<<" "<<dierbufen<<" "<<disanbufen<<endl;

	printf("%d-%02d-%02d\n",2000+diyibufen,dierbufen,disanbufen);
	printf("%d-%02d-%02d\n",2000+disanbufen,diyibufen,dierbufen);
	printf("%d-%02d-%02d\n",2000+disanbufen,dierbufen,diyibufen);

//***错误***
//没有充分利用好题目条件
//条件：日期在1960年1月1日至2059年12月31日 
//要求：多个日期按从早到晚顺序排列
 
	return 0;
}
#endif
//改正
#if 0
#include <iostream>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct da
{
   int x, y, z, flag = 0;
}date[5];

int main()
{
    int y, m, d;
    char c;

    cin >> y >> c >> m >> c >> d;
    int num = 0;

    //按年月日循环遍历，符合条件的保存到结构体数组中，
    //***注***顺便满足题目要求的从日期从小到大的顺序

    for (int nian = 1960; nian <= 2059; nian++)
    {

        if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
            mon[2] = 29;
        else mon[2] = 28;

        for (int yue = 1; yue <= 12; yue++)
        {
            for (int ri = 1; ri <= mon[yue]; ri++)
            {
                //当三重循环运行时得到与输入匹配的年月日的排列时

                //输入的是年月日
                if (nian % 100 == y && m == yue && d == ri)
                {
                    date[++num].x = nian;
                    date[num].y = m;
                    date[num].z = d;
                }

                //输入的是月(y)日(m)年(d)
                if (nian % 100 == d && y == yue && m == ri)
                {
                    date[++num].x = nian;
                    date[num].y = y;
                    date[num].z = m;
                }

                //输入的是日(y)月(m)年(d)
                if (nian % 100 == d && m == yue && y == ri)
                {
                    date[++num].x = nian;
                    date[num].y = m;
                    date[num].z = y;
                }
                
            }
        }

    }

    //去重，将重复的日期标记一下
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            if (date[i].x == date[j].x && 
                date[i].y == date[j].y && 
                date[i].z == date[j].z)

                date[j].flag = 1;
        }
    }

    //输出日期
    for (int i = 1; i <= num; i++)
        if (!date[i].flag)
            printf("%d-%02d-%02d\n", date[i].x, date[i].y, date[i].z);
    return 0;
}
#endif 
//使用set关联容器 
#if 0
#include <iostream>
#include <set>
using namespace std;

int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

typedef struct a  //***注***a不能不写，因为会导致报错
{
    int x, y, z;
}RiQiTypeDef;

//报错：二元“operator”:“type*”不定义此运算符或到预定义运算符可接收类型的转换
//原因：使用自定义的键时，要重载<运算符
//***const必须写***
bool operator<(const RiQiTypeDef&, const RiQiTypeDef&);

int main()
{
    int y, m, d;
    char c;

    cin >> y >> c >> m >> c >> d;
    int num = 0;

    //按年月日循环遍历，符合条件的保存到结构体数组中，
    //***注***顺便满足题目要求的从日期从小到大的顺序

    RiQiTypeDef RiQiStruct;
    set<RiQiTypeDef>RiQiSet;

    for (int nian = 1960; nian <= 2059; nian++)
    {

        if ((nian % 4 == 0 && nian % 100 != 0) || nian % 400 == 0)
            mon[2] = 29;
        else mon[2] = 28;

        for (int yue = 1; yue <= 12; yue++)
        {
            for (int ri = 1; ri <= mon[yue]; ri++)
            {
                //当三重循环运行时得到与输入匹配的年月日的排列时

                //输入的是年月日
                if (nian % 100 == y && m == yue && d == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = m;
                    RiQiStruct.z = d;
                    RiQiSet.insert(RiQiStruct);
                }

                //输入的是月(y)日(m)年(d)
                if (nian % 100 == d && y == yue && m == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = y;
                    RiQiStruct.z = m;
                    RiQiSet.insert(RiQiStruct);
                }

                //输入的是日(y)月(m)年(d)
                if (nian % 100 == d && m == yue && y == ri)
                {
                    RiQiStruct.x = nian;
                    RiQiStruct.y = m;
                    RiQiStruct.z = y;
                    RiQiSet.insert(RiQiStruct);
                }

            }
        }

    }

    //去重，将重复的日期标记一下
//    for (int i = 1; i <= num; i++)
//    {
//        for (int j = i + 1; j <= num; j++)
//        {
//            if (date[i].x == date[j].x && 
//                date[i].y == date[j].y && 
//                date[i].z == date[j].z)
//
//                date[j].flag = 1;
//        }
//    }

    //输出日期
    for (auto p = RiQiSet.begin(); p != RiQiSet.end(); p++)
    {
        printf("%d-%02d-%02d\n", p->x,p->y,p->z);
    }
    return 0;
}

bool operator<(const RiQiTypeDef& RiQiStruct1, const RiQiTypeDef& RiQiStruct2)
{
    bool status=0;
    
    if (RiQiStruct1.x < RiQiStruct2.x)
        status = 1;
    else if (RiQiStruct1.x == RiQiStruct2.x &&
        RiQiStruct1.y < RiQiStruct2.y)
        status = 1;
    else if (RiQiStruct1.x == RiQiStruct2.x &&
        RiQiStruct1.y == RiQiStruct2.y &&
        RiQiStruct1.z < RiQiStruct2.z)
        status = 1;
    
    return status;
}
#endif 


//2.3 REPEAT程序 
#if 0
#include <iostream>
using namespace std;

int main()
{
	int num=0;
//	cin>>num;
	
	for(int i=0;i<2;i++)
	{
		num+=4;
		for(int j=0;j<5;j++)
		{	
			for(int k=0;k<6;k++)
				num+=5;
			num+=7;
		}
		num+=8;
	}
	num+=9;
	
	cout<<num;
//***错误***
//prog.txt文件含有超长的程序篇幅，无法通过上述的程序解题。 
 
	return 0;
}
#endif
//改正： 
//使用栈容器 
#if 0
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	int space;
	int zongxunhuanshu=1;
	int result=0;
	
	freopen("2.3.txt","r",stdin);
	
	stack<int> xunhuancishu_stack;
	stack<int> kongbaizifushu_stack;
	
	xunhuancishu_stack.push(1);//缩进为0的语句段循环数为1 
	kongbaizifushu_stack.push(-1);//选一个比缩进值0还要小的数，此处选-1 
	
	string st;
	getline(cin,st);//读取首行内容
	
	while(getline(cin,st))
	{
		//计算空格数量 
		space=0;
		while(st[space]==' ')
			space++;
		
		//根据存储空白字符数的栈判断是否要减少循环
		//***注***要用while语句 
		while(space<=kongbaizifushu_stack.top()) 
		{
			zongxunhuanshu/=xunhuancishu_stack.top();
			xunhuancishu_stack.pop();
			kongbaizifushu_stack.pop();
		}
		
		//判断是否是REPEAT语句 
		if(st[st.size()-1]==':')
		{
			int xunhuanshu=st[st.size()-2]-'0';
			zongxunhuanshu*=xunhuanshu; 
			
			xunhuancishu_stack.push(xunhuanshu);
			kongbaizifushu_stack.push(space);
		}
		else//若不是REPEAT语句 
		{	//要加上的数 
			int jiashu=st[st.size()-1]-'0';
			result+=jiashu*zongxunhuanshu; 
		} 		
		
	} 
	
	cout<<result;

	return 0;
}
#endif


//2.4 整除序列 
#if 0
#include <iostream>

using namespace std;
int main()
{
	long long num=0;
	
	cin>>num;
	
	if(num%2!=0)
	return 0;
	
	while(num>=1)
	{
		cout<<num<<" ";
		num/=2;
	}
//法二：用右移运算符<<，每次除以二相当于右移一位，最高位按是否是正数补0或1 
	return 0;
}
#endif


//2.5 解码 
#if 0
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	char data[500][2];
	
	for(int i=0;i<100;i++)
	{
		data[i][0]='\0';
		data[i][1]='\0';
	}
	
	int i=0;
	int j=0;
	for(int index=0;index<str.size();index++)
	{
		if(isdigit(str[index]))
		continue;
		
		data[i][0]=str[index];
		
		if(isdigit(str[index+1]))
			data[i][1]=str[index+1];
		else
			data[i][1]='1';
		
		i++;
	}
	
//显示数组的内容		
//	for(int i=0;i<100;i++)
//	{
//		cout<<data[i][0]<<" ";
//		cout<<data[i][1]<<endl;
//	}

	i=0;
	while(1)
	{				//***注***char型转化为int型 
		for(int cishu=data[i][1]-'0';cishu>0;cishu--)
		cout<<data[i][0];
		
		i++;
		
		if(data[i][0]=='\0') 
		break;
	}

	return 0;
} 
#endif


//2.6 整数拼接 
#if 0
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int CheckNumber(int num);

int main()
{
	int n;
	cin>>n;
	int* shuzu1=new int[n];//输入的数字 
	int* shuzu2=new int[(n-1+1)*(n-1)];//拼接好后的数字 
	
	int k;
	cin>>k;
	
	int index=0;
	int n1=n;
	do
	{		
		cin>>shuzu1[index++];
		n1--;
	}while(n1);
	
	
	int temp=0;
	int m=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			temp=shuzu1[i]* pow(10,CheckNumber(shuzu1[j]))+shuzu1[j];
			shuzu2[m++]=temp;
			temp=shuzu1[j]* pow(10,CheckNumber(shuzu1[i]))+shuzu1[i];
			shuzu2[m++]=temp; 
		}
	}

//显示数组的内容		
//	for(int i=0;i<(n-1+1)*(n-1);i++)
//	cout<<shuzu2[i]<<" ";
	
	//改正 
	//***注*** 
	//使用set关联容器去除重复的值 
	set<int>shuzi_set;
	for(int i=0;i<(n-1+1)*(n-1);i++)
		shuzi_set.insert(shuzu2[i]);
	
	int geshu=0;
	for(auto p=shuzi_set.begin();p!=shuzi_set.end();p++)
		(*p%k==0)?geshu++:geshu;
		
	cout<<geshu;
		
	return 0;
} 

int CheckNumber(int num)
{
	int weishu = 0;
	for ( int num1 = num; num1; )
	{
	   //当num为一位时 循环进行一次 当num为两位时 两次 ,三位时 三次
	   num1 = num1 / 10;
	   weishu++;								//循环进行一次,位数加一
	}
//	cout<< weishu;
	return weishu;
}
//测试输入
//4 2
//1 2 3 4 
//5 2
//1 12 123 1234 12345
#endif


//2.7 卡片 
#if 0
#include <iostream>
#include <vector>
#include <stdio.h>//sprintf() 
using namespace std;

void meiweideshuzi(vector<int>& ,int num);
int main()
{
	vector<int> data[10];
	
	for(int i=0;i<10;i++)
	{
		data[i].push_back(i);
		data[i].push_back(2021);
	}
	
//显示数组内容 
//	for(int i=0;i<10;i++)
//	{
//		cout<<data[i][0]<<" "<<data[i][1];
//		cout<<endl;
//	}

	vector<int> shuzi;
	
	//要拼的整数 
	int pindezhengshu=1;
	int result;
	
	while(1)
	{
		meiweideshuzi(shuzi,pindezhengshu);
		
		for(auto p=shuzi.begin();p!=shuzi.end();p++)
			for(int i=0;i<10;i++)
				if(*p==data[i][0])
				{
					if(data[i][1])
						data[i][1]--;
					else
						{
							result=pindezhengshu-1;
							goto step1;
						}
				}
		
		pindezhengshu++;
	}	 
	
step1:cout<<result;

	return 0;
}

//计算每位上的数字 
void meiweideshuzi(vector<int>& data,int num)
{
//	int num1=num;
//	int weishu=0;
//	do
//	{
//		num1/=10;
//		weishu++;
//	}while(num1);

//***注***有至少两种方法	
//法一：循环提取法 
// data.clear();
//	while(num)
//	{					//***注***要插入到头部 
//		data.insert(data.begin(),num%10);
//		num/=10;	
//	}
//	for(auto p=data.begin();p!=data.end();p++)
//		cout<<*p<<" ";
//法二：使用sprintf()直接将数字转换为字符串，
//然后可以选择以字符的形式输出，也可以选择向int数组存入每位的数字 
	char str[100]={'\0'};
	sprintf(str,"%d",num);
	
	int index=0;
	int weishu=0;
	while(str[index++])
	{
		weishu++;
	}
	
	//改正： 
	//***注***在每次调用此函数时，vector数组都要先恢复初始状态 
	data.clear();
	for(index=0;index<weishu;index++)
		data.push_back(str[index]-'0');
		
//	for(auto p=data.begin();p!=data.end();p++)
//		cout<<*p<<" ";
}
#endif


//2.8 杨辉三角 
#if 0
#include <iostream>
using namespace std;

int main()
{
	long long N;
	cin>>N;
	
	long long yanghui[100][100];
	
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			yanghui[i][j]=0;
			
	yanghui[0][0]=1;
	yanghui[1][0]=yanghui[1][1]=1;
	for(int i=2;i<100;i++)//从第三层开始 
	{
		yanghui[i][0]=yanghui[i][i]=1;
		for(int j=1;j<=i-1;j++)
			yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j]; 
	}
		
//	for(int i=0;i<100;i++)
//	{
//		for(int j=0;j<100;j++)
//			if(yanghui[i][j]!=0)
//				cout<<yanghui[i][j]<<" ";
//		cout<<endl;
//	}

	int jishu=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{	
			if(yanghui[i][j]==0)
				continue;
				
			++jishu;
			if(yanghui[i][j]==N)
				goto step;
		}	
	}

step:cout<<jishu;

	return 0;
}
#endif
























