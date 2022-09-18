#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX11_9_2
#define BCLX11_9_2

#include <iostream>
#include <cmath>

namespace VECTOR
{
    class Vector
    {
    public:
        // RECT for rectangular, POL for Polar modes
        // RECT：直角坐标系下，POL：极坐标系下
        //声明一个枚举类型，没有创建枚举变量，但创建了符号常量
        enum Mode { RECT, POL };
    private:
        double x;               // horizontal value
        double y;               // vertical value
        Mode mode;        // RECT or POL 创建一个枚举变量
    public:
        // default constructor
        Vector();

        // construct vector from rectangular coordinates if form is RECT (the default) 
        // or else from polar coordinates if form is POL
        //此构造函数能根据输入的参数，初始化Vector类对象的私有数据成员
        //输入一种表示矢量的形式，将自动生成另一种表示形式，
        // x, y, mag, ang 将都有数值
        Vector(double n1, double n2, Mode form = RECT);

        // reset vector from rectangular coordinates if form is
        // RECT (the default) or else from polar coordinates if
        // form is POL
        //此方法能使用户修改了矢量的一种表示后，对象将自动更新另一种表示
        void reset(double n1, double n2, Mode form = RECT);

        // destructor
        ~Vector();

        //公有方法(写成内联函数)
        double xval() const { return x; }       // report x value
        double yval() const { return y; }       // report y value
        double magval() const//写成内联函数
        { return sqrt(x * x + y * y); }   // report magnitude
        double angval() const 
        { //***注***atan2(0,0)未定义，需要手动设置值
            if (x == 0.0 && y == 0.0)
                return 0.0;
            else
                return atan2(y, x);
        }   // report angle

        //公有方法(写成封装形式)
        void polar_mode();                    // set mode to POL
        void rect_mode();                     // set mode to RECT

        // operator overloading
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // friends
        //重载二元运算符(带两个参数的运算符)时，常常需要友元
        // multiply n by Vector a
        friend Vector operator*(double n, const Vector& a);
        // display rectangular coordinates if mode is RECT,
        // else display polar coordinates if mode is POL
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };

}   // end namespace VECTOR

#endif  /*BCLX11_9_2*/
