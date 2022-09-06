#define _CRT_SECURE_NO_WARNINGS 1

#ifndef class_Golf
#define class_Golf

class Golf
{
	enum {Len=40};
	struct golf
	{
		char fullname[Len];
		int handicap;
	}golf_structure;						//此处创建的结构变量并没有存储在对象中

public:
	Golf(const char* p_data,const int hc);
	Golf();
	//交互版本
	int setgolf();
	void handicap(const int hc);
	void showgolf() const;
};

#endif  /*class_Golf*/