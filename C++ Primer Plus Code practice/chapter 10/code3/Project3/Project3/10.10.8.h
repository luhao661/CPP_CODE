#define _CRT_SECURE_NO_WARNINGS 1

#ifndef LIST_H
#define LIST_H

#define LENGTH 45

//存储项目
struct film
{
	char title[LENGTH];
	int rating;
};
typedef struct film Item;//把film结构布局命名为Item
//***注***若把此结构声明放入类声明中，则仅有共有成员函数可以访问。
//而成员函数只能由对象访问，所以要使用此结构模板的话必须先创建类对象。

class List
{
	//确定如何存储这种类型的项
	//链表的节点
	typedef struct node
	{
		Item item;							//链表内容	
		struct node* next;				//指向下一个节点的指针					//表明用链式结构存储数据

		//***注***上句不能写成Node* next;原因是typedef还没给类型命名好就使用了Node，编译时会产生很多错误				
		//所以此处用typedef来命名一个结构类型，但不省略结构的标记

	}Node;										//把note结构布局命名为Node		
													/***每个链节叫做节点，每个节点包含链表内容和指向下一个节点的指针***/

	struct P_Node
	{
		Node* head;//指向开头，存Node结构的地址，但是头指针一开始为NULL
		Node* end;//指向结尾，存Node结构的地址
	};//声明一个结构布局，标签为P_Node
	 
	P_Node movies;//创建一个结构变量，存这两个指针
	P_Node* plist=&movies;//plist指向此结构变量(C++11类内初始化)
	
public:
	/* 操作∶ 初始化一个链表 */
	/* 前提条件∶ plist 指向一个链表 */
	/* 后置条件∶ 链表初始化为空 */
	//void InitializeList(P_Node* plist);
	//传入plist的是&movies，是P_Node结构布局的结构的地址
	List();

	/*操作∶ 确定链表是否已满，plist 指向一个已初始化的链表 */
	/* 后置条件∶ 如果链表已满，该函数返回真;否则返回假 */
	//bool ListIsFull(const P_Node* plist);
	bool ListIsFull()const;

	/*操作∶ 在链表的末尾添加项*/
	/*前提条件∶ item是一个待添加至链表的项，plist 指向一个已初始化的链表 */
	/*后置条件∶ 如果可以，该函数在链表末尾添加一个项，且返回true;否则返回false*/
	//bool AddItem(Item item, P_Node* plist);
	bool AddItem(Item item);

	/* 操作∶ 确定链表是否为空，plist 指向一个已初始化的链表 */
	/*后置条件∶ 如果链表为空，该函数返回true;否则返回false */
	//bool ListIsEmpty(const P_Node* plist);
	bool ListIsEmpty()const;

	/*操作∶ 把函数作用于链表中的每一项，plist指向一个已初始化的链表 */
	/*pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值 */
	/*后置条件∶ pfun 指向的函数作用于链表中的每一项一次 */
	//void Traverse(const P_Node* plist, void(*pfun)(Item item));
	void Visit(void(*pf)(Item&))const;

	/*操作∶ 确定链表中的项数，plist 指向一个已初始化的链表 */
	/* 后置条件∶ 该函数返回链表中的项数 */
	//unsigned int ListItemCount(const P_Node* plist);
	unsigned int ListItemCount()const;

	/*操作∶ 释放已分配的内存（如果有的话） */
	/* plist 指向一个已初始化的链表 */
	/* 后置条件∶ 释放了为链表分配的所有内存，链表设置为空 */
	//void EmptyTheList(P_Node* plist);
	void EmptyTheList();
};

#endif /*LIST_H*/