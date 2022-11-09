#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX_15_8_1_H
#define BCLX_15_8_1_H

class Tv
{
    friend class Remote;   // Remote can access Tv private parts
                                          //***注***此友元声明可以位于任何位置
private:
    int state;                // on or off
    int volume;            // assumed to be digitized
    int maxchannel;    // maximum number of channels
    int channel;           // current channel setting
    int mode;              // broadcast or cable
    int input;               // TV or DVD

public:
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };
    enum {Normal, Interaction};

    Tv(int s = Off, int mc = 125)
        : state(s), volume(5), maxchannel(mc), channel(2),
        mode(Cable), input(TV)
    {}
    void onoff()
    {
        //state = (state == On) ? Off : On; 
        //写法二：
        state ^= 1;
    }
    bool ison() const
    {
        return state == On;
    }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode()
    {
        mode = (mode == Antenna) ? Cable : Antenna;
    }
    void set_input()
    {
        input = (input == TV) ? DVD : TV;
    }
    void settings() const; // display all settings

    bool switch_moshi(Remote& r)const;
};

class Remote
{
    friend class Tv;

private:
    int mode;              // controls TV or DVD
    int normal_or_interaction;//常规或互动模式

public:
    Remote(int m = Tv::TV,int m1= Tv::Normal)//友元不在类作用域内，要使用类中的明示常量的话要用类名和作用域解析运算符P329
        : mode(m),normal_or_interaction(m1)
    {}
    bool volup(Tv& t)
    {
        return t.volup();
    }
    bool voldown(Tv& t)
    {
        return t.voldown();
    }
    void onoff(Tv& t)
    {
        t.onoff();
    }
    void chanup(Tv& t)
    {
        t.chanup();
    }
    void chandown(Tv& t)
    {
        t.chandown();
    }
    void set_chan(Tv& t, int c)
    {
        t.channel = c; //***注***友元类方法可以访问原始类的私有成员和保护成员
    }
    void set_mode(Tv& t)
    {
        t.set_mode();
    }
    void set_input(Tv& t)
    {
        t.set_input();
    }
    void show_moshi(void)const;
};
#endif
