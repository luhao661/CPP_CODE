#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CXQD_16_8_H
#define CXQD_16_8_H

#include <string>
struct Review
{
    std::string title;
    int rating;
};

bool FillReview(Review& rr);
void ShowReview(const Review& rr);

#endif
