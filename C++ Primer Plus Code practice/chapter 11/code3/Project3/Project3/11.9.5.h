#define _CRT_SECURE_NO_WARNINGS 1

#ifndef bclx11_9_5
#define bclx11_9_5
class Stonewt
{
public:
    enum Mode {STONE,INTEGER_POUNDS,FLOAT_POUNDS};
private:
    Mode mode;
    enum { pds_per_stn = 14 };      // pounds per stone
    int stone;                                   // whole stones
    double pds_left;                       // fractional pounds
    double pounds;                       // entire weight in pounds
public:
    //***注***此构造函数能用作隐式类型转换
    Stonewt(double pds,Mode form= FLOAT_POUNDS);// constructor for double pounds
    Stonewt(int stn, double pds, Mode form = STONE);  // constructor for stone, pounds
    Stonewt();                                  // default constructor
    ~Stonewt();
    //void show_pds() const;        // show weight in pounds format
    //void show_stn() const;        // show weight in stone format
    friend std::ostream& operator<<(const std::ostream os,const Stonewt st);

    Stonewt operator+(const Stonewt s)const;
    //Stonewt operator+(int stn, double pds)const;//报错：此运算符函数的参数过多
    Stonewt operator-(const Stonewt s)const;
    Stonewt operator-()const;

    Stonewt operator*(double x)const;
    friend Stonewt operator*(double x,const Stonewt s);
};
#endif /*bclx11_9_5*/
