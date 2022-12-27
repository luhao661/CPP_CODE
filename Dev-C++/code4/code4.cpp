//4.1 递推和递归 
#if 0
#include <iostream>

using namespace std;
int ditui(int n);
int digui(int n);
int main()
{
	int n;
	cin>>n;
	
	int result1=ditui(n);
	int result2=digui(n);
	
	cout<<result1<<endl<<result2<<endl;

	return 0;
}
int ditui(int n)
{
	int arr[100]={0};
	
	arr[1]=1;
	arr[2]=2;
	
	for(int i=3;i<=n;i++)
		arr[i]=arr[i-1]+arr[i-2];
		
	return arr[n]; 
}
int digui(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	
	return digui(n-1)+digui(n-2);
}
#endif


//4.2 承压计算 
#if 0
#include <iostream>
#include <valarray>
#include <cmath>
#include <stdio.h>

using namespace std;
int main()
{
	freopen("4.2.txt","r",stdin);
	
	double data_jinzita[30][30];
	
	for(int i=0;i<30;i++)
		for(int j=0;j<30;j++)
			data_jinzita[i][j]=0.0;
	
	int temp;
	for(int i=0;i<29;i++)
		for(int j=0;j<=i;j++)
		{
			cin>>temp;
			data_jinzita[i][j]=temp;
		}
		
	for(int i=0;i<30;i++)
	{	
		for(int j=0;j<30;j++)		
			cout<<data_jinzita[i][j]<<" ";
		cout<<endl;
	}

//***错误***
//直接用double数据类型存储除以2之后的值，会出现问题
//第一层的数字到最底层相当于要除以2的29次方，double达不到此精度 

	for(int i=0;i<29;i++)
	{	
		for(int j=0;j<=i;j++)		
			data_jinzita[i][j]*=pow(2,29);//改正	
	}

	data_jinzita[1][0]+=data_jinzita[0][0]/2.0;				
	data_jinzita[1][1]+=data_jinzita[0][0]/2.0;	

//	从第三层开始，分开算金字塔最外侧的数字和金字塔内的数字 
	for(int i=2;i<30;i++)
	{
		//计算最外侧的两个数字 
		data_jinzita[i][0]+=data_jinzita[i-1][0]/2.0;
		data_jinzita[i][i]+=data_jinzita[i-1][i-1]/2.0;
		for(int j=1;j<=i-1;j++)
		{
//***语句的位置错误*** 
//			data_jinzita[i][0]+=data_jinzita[i-1][0]/2.0;
//			data_jinzita[i][i]+=data_jinzita[i-1][i-1]/2.0; 				
			
			//计算金字塔内的数字			
			data_jinzita[i][j]+=data_jinzita[i-1][j-1]/2.0+data_jinzita[i-1][j]/2.0;
		
		}
	}
		
	for(int i=0;i<30;i++)
	{	
		for(int j=0;j<30;j++)		
			cout<<data_jinzita[i][j]<<" ";
		cout<<endl;
	}
	
	valarray<double> a(30);
	for(int i=0;i<30;i++)
		a[i]=data_jinzita[29][i];
		
	cout<<endl<<a.min()<<endl<<a.max()<<endl;	

	printf("%.2f",a.max());
	return 0;
}
#endif


//4.3 取数位 
#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

int len(int x)
{
	if(x<10)
		return 1;
		
	return len(x/10)+1;
}
//取x的第k位数字 
int f(int x,int k)
{
	if(len(x)-k==0)
		return x%10;
	
	return f(x/10,k);
}

int main()
{
	int x=23574;
	printf("%d\n",f(x,3));

	return 0;
} 
#endif


//4.4 数列的值 
#if 0
#include <iostream>

using namespace std;
int main()
{
	const long num=20190324;

//***注*** 
//会导致程序最终异常终止的警告： 
//函数使用 堆栈的constant_1 字节：超过 /analyze：stacksize constant_2。
//考虑将部分数据移到堆	
//	long long shuzu[num]={0};
	
	long long *shuzu=new long long[num]; 
	
	shuzu[0]=shuzu[1]=shuzu[2]=1;
	
	//从第四项开始 
	for(long i=3;i<num;i++)
	{
		shuzu[i]=shuzu[i-1]+shuzu[i-2]+shuzu[i-3];
		shuzu[i]%=100000000;//保留8位，以控制在long long的表示范围内 
	}
	cout<<shuzu[num-1]; 
	
	delete [] shuzu; 

	return 0;
}
#endif


//4.5 快速排序 
#if 0
#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop 
标题：快速排序。 
以下代码可以从数组a[]中找出第k小的元素。
它使用了类似快速排序中的分治算法，期望时间复杂度是O(N)的。
请仔细阅读分析源码，填写划线部分缺失的内容。 
*/
int quick_select(int a[], int l, int r, int k) 
{  
	//生成一个随机的索引值，作为中心轴 
	int p = rand() % (r - l + 1) + l;  
	
	//x存入随机选定的数字 
	int x = a[p];
	
	{
		int t = a[p];//t存入随机选定的数字 
		a[p] = a[r];//交换中心轴与右指针指向的元素 
		a[r] = t;
	}  
	
	int i = l, j = r;
	while(i < j) 
	{
		//正序遍历数组，查找第一个大于或等于中心轴数据的
		//数的索引值 
		while(i < j && a[i] < x) i++;  
		
		//若其索引值不是最末的数据的索引值 
		if(i < j) 
		{  
		   //将该数据复制到最末位                    
			a[j] = a[i]; 
			j--;                          
		}
		
		//逆序遍历数组，查找第一个小于或等于中心轴数据的
		//数的索引值 
		while(i < j && a[j] > x) j--; 
		
		if(i < j)
		{
			//将该数据复制到第一个大于或等于中心轴数据的
			//数的位置 
			a[i] = a[j];           
			i++;
		}
	}
	
	//循环结束时i左边的数都比中心轴处的数小，
	//i右边的数都比中心轴处的数大 
	
	//将原中心轴处的数字复制到i的位置 
	a[i] = x;
	p = i;
	
	if(i - l + 1 == k)//即i-l==k-1 索引值是否等于要求的 
		return a[i];	//第k小的数所在的位置(即k-1)
							//若判断条件成立，
							//则说明中心轴处的数字就是第k小的数字 
	
	//若小于k，则说明k对应的数在中心轴右边，
	//下一次只在中心轴右边去找				
	//***注***
	//k-i+l-1即k-(i-l+1),是去掉了i左半部分后，i右半部分从0开始的索引值		
	if(i - l + 1 < k)
		return quick_select(a,i+1,r,k-i+l-1); //填空 
	else
		return quick_select(a, l, i - 1, k);
}
int main()
{
	int a[] = {1, 4, 2, 8, 5, 7, 23, 58, 16, 27, 55, 13, 26, 24, 12};   
	printf("%d\n", quick_select(a, 0, 14, 2));            
	return 0;
}
#endif





























