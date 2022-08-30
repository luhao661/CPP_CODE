#define _CRT_SECURE_NO_WARNINGS 1
// structure templates
#ifndef CXQD9_1_H
#define CXQD9_1_H

struct rect
{
    double x;        // horizontal distance from origin
    double y;        // vertical distance from origin
};
struct polar
{
    double distance;    // distance from origin
    double angle;        // direction from origin
};

// prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif  /*CXQD9_1_H*/
