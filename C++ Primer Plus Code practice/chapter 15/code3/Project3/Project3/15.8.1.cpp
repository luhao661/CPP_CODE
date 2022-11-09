#define _CRT_SECURE_NO_WARNINGS 1

#if 0

#include <iostream>
#include "15.8.1.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;

    cout << "TV is " << (state == Off ? "Off" : "On") << endl;

    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna ? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV ? "TV" : "DVD") << endl;
    }
}

bool Tv::switch_moshi(Remote& r)const
{
    if (ison())
    {
        r.normal_or_interaction ^= 1;//***注***若Tv不声明为Remote类的友元
                                                          //则Tv类方法中不能访问Remote类中的私有成员
        return true;
    }
    else
        return false;
}

void Remote::show_moshi(void)const
{
    using std::cout;
    using std::endl;
    cout << "当前模式为："<<((normal_or_interaction==Tv::Normal)?"常规":"互动");
    cout << endl;                   //***注***此处要对整个条件运算符语句用括号括起，涉及到运算符优先级
}

#endif