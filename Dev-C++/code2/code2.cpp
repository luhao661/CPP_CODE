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



























