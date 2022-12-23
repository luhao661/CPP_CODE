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
#if 1
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
	for(auto p=num_vector.begin();p!=num_vector.end();p++)
	{
		shuliechangdu=1;
		
		for(auto q=p;q!=num_vector.end();q++)
			if(*p+gongcha*k==*q)
				{
					shuliechangdu++;
					
					if(shuliechangdu==10)
						goto conclusion;
					
					k*=2; 
					continue;
				}
		gongcha++;
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



























