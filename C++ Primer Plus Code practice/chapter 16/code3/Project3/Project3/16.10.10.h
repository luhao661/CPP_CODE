#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_16_10_10_H
#define BCLX_16_10_10_H
#include <string>

struct Review
{
    std::string title;
    int rating;
    double price;
};

bool FillReview(Review& rr);
void ShowReview(const Review *p);

//C++ 非成员运算符要求类类型或枚举类型的参数,
//所以不能是const Review*p1
bool operator<(const Review p1, const Review p2);//按字母顺序
bool worseThan(const Review* r1, const Review* r2);

void menu(void);
bool a(const Review* r1, const Review* r2);

//修改思路：
//既然不能把shared_ptr自动转化成普通指针，那么就把函数形参都
//改成shared_ptr&类型
#endif