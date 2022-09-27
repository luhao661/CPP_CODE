#define _CRT_SECURE_NO_WARNINGS 1

#ifndef BCLX12_10_6_H
#define BCLX12_10_6_H

class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() : arrive(0), processtime(0) {}//成员初始化列表只能用在(默认)构造函数
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
    // class scope definitions
    // Node is a nested structure definition local to this class
    enum { Q_SIZE = 10 };//创建明示常量(符号常量)，Q_SIZE表示默认的队列最大长度
    struct Node { Item item; struct Node* next; };
    Node* front;       // pointer to front of Queue
    Node* rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    //使用定义的复制构造函数和赋值运算符重载函数，
    //但放在private中，可以避免对象被初始化成其他对象的数据或进行对象间的赋值操作
    // preemptive definitions to prevent public copying
    Queue(const Queue& q) : qsize(0) { }//若不提供，则程序会使用默认的复制构造函数，造成严重后果
    Queue& operator=(const Queue& q) { return *this; }
public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item& item); // add item to end
    bool dequeue(Item& item);       // remove item from front
};

#endif /*BCLX12_10_6_H*/