#define _CRT_SECURE_NO_WARNINGS 1

// vect.h -- Vector class with <<, mode state
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

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
        double mag;         // length of vector
        double ang;          // direction of vector in degrees
        Mode mode;        // RECT or POL 创建一个枚举变量
    // private methods for setting values 
        void set_mag();
        void set_ang();
        void set_x();
        void set_y()//也可以写成内联函数
        {
            y = mag * sin(ang);
        }
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
        double magval() const { return mag; }   // report magnitude
        double angval() const { return ang; }   // report angle

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
#endif
