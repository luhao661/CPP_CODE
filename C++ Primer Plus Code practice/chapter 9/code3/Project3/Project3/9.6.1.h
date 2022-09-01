#define _CRT_SECURE_NO_WARNINGS 1

#ifndef A_9_6_1_H//命名不能以数字开头
#define A_9_6_1_H

const int Len = 40;

struct golf
{
	char fullname[Len];
	int handicap;
};

//非交互版本
void setgolf(golf& g,const char * name,int hc);
//交互版本
int setgolf(golf& g);
//重新设置handicap成员的值
void handicap(golf& g, int hc);
//显示golf结构变量中的成员的内容
void showgolf(const golf&g);

#endif				/*A_9_6_1_H*/