#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "cxqd16.8.h"
#include <iostream>

bool FillReview(Review& rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr.title);

    if (rr.title == "quit")
        return false;

    std::cout << "Enter book rating: ";
    std::cin >> rr.rating;
    
    if (!std::cin)
        return false;
    
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    
    return true;
}

void ShowReview(const Review& rr)
{
    std::cout << rr.rating << "\t" << rr.title << std::endl;
}

#endif
