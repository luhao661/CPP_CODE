#define _CRT_SECURE_NO_WARNINGS 1

#include <string>

// create the pers and debts namespaces
//创建pers和debts名称空间
namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };//声明一个结构布局，标签为Person
    void getPerson(Person&);
    void showPerson(const Person&);
}

namespace debts
{
    using namespace pers;//可以在名称空间中使用using编译指令和using声明

    struct Debt
    {
        Person name;//嵌套结构
        double amount;
    };//声明一个结构布局，标签为Debt

    void getDebt(Debt&);
    void showDebt(const Debt&);
    double sumDebts(const Debt ar[], int n);
}
