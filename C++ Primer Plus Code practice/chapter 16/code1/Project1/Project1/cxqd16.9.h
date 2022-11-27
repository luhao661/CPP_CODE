#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_16_9_H
#define CXQD_16_9_H
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