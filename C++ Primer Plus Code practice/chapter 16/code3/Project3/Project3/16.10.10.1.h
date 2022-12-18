#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_16_10_10_1_H
#define BCLX_16_10_10_1_H
#include <string>
#include <iostream>
#include <memory>

struct Review
{
    std::string title;
    int rating;
    double price;
};

using std::shared_ptr;

bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& p);

//C++ 非成员运算符要求类类型或枚举类型的参数,
bool operator<(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);//按字母顺序
bool anpinjishengxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anpinjijiangxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anjiageshengxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);
bool anjiagejiangxu(const shared_ptr<Review>& p1,
    const shared_ptr<Review>& p2);

void menu(void);

//修改思路：
//既然不能把shared_ptr自动转化成普通指针，那么就把函数形参都
//改成shared_ptr&类型
#endif