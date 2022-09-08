#define _CRT_SECURE_NO_WARNINGS 1

#ifndef Move_H
#define Move_H
class Move
{
private:
	double x;
	double y;
public:
	Move(double a=0,double b=0);
	void showmove()const;
	Move add(const Move &m)const;
	void rest(double a=0,double b=0);
};

#endif  /*Move_H*/