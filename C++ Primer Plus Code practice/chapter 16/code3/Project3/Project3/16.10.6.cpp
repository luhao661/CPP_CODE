#define _CRT_SECURE_NO_WARNINGS 1

#if 0
#include "16.10.6.h"
#include <cstdlib>
// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
#endif
