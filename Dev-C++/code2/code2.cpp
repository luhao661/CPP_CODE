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
#if 1
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


























