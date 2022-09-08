#define _CRT_SECURE_NO_WARNINGS 1

#ifndef B_P_H
#define B_P_H

class BetelPlorg
{
	char m_name[20];
	int m_level;
public:
	BetelPlorg(const char *data,int level=50);
	BetelPlorg();
	~BetelPlorg();
	void modification(int level);
	void show()const;
};

#endif  /*B_P_H*/