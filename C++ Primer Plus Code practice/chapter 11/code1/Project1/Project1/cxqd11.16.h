#define _CRT_SECURE_NO_WARNINGS 1

// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
private:
    enum { pds_per_stn = 14 };      // pounds per stone
    int stone;                                   // whole stones
    double pds_left;                       // fractional pounds
    double pounds;                       // entire weight in pounds
public:
    Stonewt(double pds);               // constructor for double pounds
    Stonewt(int stn, double pds);  // constructor for stone, pounds
    Stonewt();                                  // default constructor
    ~Stonewt();
    void show_pds() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format
};
#endif
