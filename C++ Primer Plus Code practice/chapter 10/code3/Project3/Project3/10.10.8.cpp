#define _CRT_SECURE_NO_WARNINGS 1

#if 1
#include "10.10.8.h" 
#include <stdio.h>//定义了NULL为0

List::List()
{
	plist->head = NULL;//即头指针head=NULL
	plist->end = NULL;
}

bool List::ListIsFull()const
{
	bool full;
	Node* p;
	p =new Node;//测试能否为新项分配空间
	if (p == NULL)
		full = true;
	else
		full = false;
	delete p;

	return full;
}

bool List::AddItem(Item item)
{
	Node* begin, * current;

	begin = plist->head;

	current = new Node;//首先为新节点分配空间
										//current指向新节点，存新节点的地址
	if (current == NULL)//若用户未调用ListIsFull()函数，那么此语句也能检查能否为新项分配空间
		return false;

	current->item = item;//若分配成功，则把项拷贝到新节点中(拷贝结构)
//***注***此处可同名是因为两个变量的作用域不同

	current->next = NULL;//表明该节点是链表的最后一个节点

	if (begin == NULL)//若传入参数是头指针
		plist->head = current;//则把头指针设置为指向第一个节点
	else
	{
		plist->end->next = current;
	}

	plist->end = current;//更新end指针指向的节点

	return true;
}

bool List::ListIsEmpty()const
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

void List::Visit(void(*pf)(Item&))const
{
	Node* begin = plist->head;

	while (begin != NULL)
	{
		(*pf)(begin->item);
		begin = begin->next;
	}
}

unsigned int List::ListItemCount()const
{
	unsigned int count = 0;
	Node* begin = plist->head;

	while (begin != NULL)
	{
		count++;
		begin = begin->next;
	}
	return count;
}

void List::EmptyTheList()
{
	Node* temp = (Node *)0x01;

	while (plist->head != NULL)
	{
		temp = (plist->head)->next;//保存下一节点的地址
		delete(plist->head);
		plist->head = temp;//前进至下一节点
	}
}

#endif