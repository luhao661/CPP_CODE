#define _CRT_SECURE_NO_WARNINGS 1

#ifndef FXT_16_9_10_H
#define FXT_16_9_10_H

#include <string>

struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review& rr);
void ShowReview(const Review& rr);
bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);

#endif