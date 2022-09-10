#define _CRT_SECURE_NO_WARNINGS 1

#ifndef yinhangzhanghu
#define yinhangzhanghu

class Account
{
	static const int LEN = 50;//创建LEN常量，不存储对象中
	char m_name[LEN];//添加m_前缀以避免方法的形参名与类的数据成员名相同
	enum {LLEN=80};//创建符号常量
	char m_identification[LLEN];
	double m_savings;
public:
	Account(const char *name,const char *identification,double savings);//声明一个构造函数
	/****注***以下语句与上述语句功能相同
	void init_account(const char *name,const char*identification,double savings);*/
	Account();//声明一个默认构造函数
	~Account();//声明一个析构函数
	void show() const;
	void  deposit(double savings);
	void  draw(double savings);
};

#endif  /*yinhangzhanghu*/