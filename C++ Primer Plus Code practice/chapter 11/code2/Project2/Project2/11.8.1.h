#define _CRT_SECURE_NO_WARNINGS 1

#ifndef fxt11_8_1
#define fxt11_8_1
class Stonewt
{
private:
    enum { Lbs_per_stn = 14 };      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs);          // construct from double pounds
    Stonewt(int stn, double lbs); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const;        // show weight in pounds format
    void show_stn() const;        // show weight in stone format

    Stonewt operator*(double a)const;

    friend Stonewt operator*(double a,const Stonewt& st);

    //特殊的C++运算符函数——转换函数
    // conversion functions
    explicit operator int() const;
    explicit operator double() const;
};
#endif /*fxt11_8_1*/
