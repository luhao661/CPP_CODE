#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//15.7 复习题
//6.
//链接无
#if 1
#include "15.7.6.h"
#include <cstdlib>//srand(), rand()
#include <ctime>//time()

Grand* GetOne(void);

int main()
{
    std::srand(std::time(0));

    Grand* pg;
    Superb* ps;

    for (int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if (ps = dynamic_cast<Superb*>(pg))//在运行阶段判断是否可以安全地
            ps->Say();                                          //将对象的地址赋给特定类型的指针
                                                                       //***注***虚函数的功能保留       
        /*if (typeid(*pg) == typeid(Superb))
            (Superb*)pg->Say();*///***注***产生编译错误
    }                                           //原因：基类指针只能调用基类中有的方法P399     
    // std::cin.get();
    return 0;
}

Grand* GetOne(void)    // generate one of three kinds of objects randomly
{
    Grand* p;
    p = (Grand*)0;//***注***不能写成Grand* p＝(Grand*)0;

    switch (std::rand() % 3)
    {
    case 0: p = new Grand(std::rand() % 100);
        break;
    case 1: p = new Superb(std::rand() % 100);
        break;
    case 2: p = new Magnificent(std::rand() % 100,
        'A' + std::rand() % 26);
        break;
    }

    return p;
}
#endif