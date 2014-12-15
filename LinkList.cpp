#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{
	head = (LinkNode*)malloc(sizeof(LinkNode));  //初始化链表头指针
	head ->data = NULL;
	head ->next = NULL;
}


LinkList::~LinkList()
{
	LinkNode *p = head;
	while(p != NULL)  //顺序遍历链表元素释放元素结点内存
	{
		head = p ->next;
		delete p;
		p = head;
	}
	delete head;
}


int LinkList::Length()
{
	int length = 0;
	LinkNode *p = head;
	while(p != NULL)  //顺序遍历链表元素统计结点个数
	{
		length++;  //元素存在则长度加1
		p = p ->next;
	}
	return length;
}


bool LinkList::Empty()
{
	return head == NULL;  //头指针指向NULL则链表为空
}


bool LinkList::Insert(int index, ElemType element)
{
	if(index < 0)  //index小于0
		return false;

	LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));  //创建新结点
	newnode ->data = element;  //初始化新结点
	newnode ->next = NULL;

	if(index == 0 || head == NULL)  //index为0或链表为空时在表头添加新结点
	{
		newnode ->next = head;
		head = newnode;
	}
	else if(index < Length())  //index在现有元素索引内
	{
		LinkNode *p = FindIndex(index - 1);  //找到索引为index-1的结点
		newnode ->next = p ->next;  //新结点的next指向索引为index的结点
		p ->next = newnode;  //索引为index-1的结点的next指向新结点
	}
	else  //index大于所有元素索引值，在表尾添加新结点
	{
		LinkNode *p = head;
		while(p ->next != NULL)  //找到表尾结点
		{
			p = p ->next;
		}
		p ->next = newnode;  //表尾结点的next指向新结点
	}
	return true;
}


bool LinkList::Delete(int index, ElemType &element)
{
	if(head == NULL || index < 0  || index >= Length())  //链表为空或index小于0或index大于所有元素索引值
		return false;

	if(index == 0)  //index为0时删除首结点
	{
		LinkNode *p = head;
		head = head ->next;  //头指针指向下一个结点
		delete p;  //释放删除结点内存
	}
	else  //index在现有元素索引内
	{
		LinkNode *p = FindIndex(index - 1);  //找到索引为index-1的结点
		LinkNode *q = p ->next;  //q指向索引为index的结点
		p ->next = q ->next;  //索引为index-1 的结点的next指向索引为index的结点的next结点
		delete q;  //释放索引为index的结点内存
	}
	return true;
}


void LinkList::Clear()
{
	LinkNode *p = head;
	while(p != NULL)  //遍历链表释放元素结点内存,释放后头指针head指向NULL
	{
		head = p ->next;
		delete p;
		p = head;
	}
}


bool LinkList::Swap(int a, int b)
{
	if(Empty() || a < 0 || a >= Length() || b < 0 || b >= Length())  //链表为空,a或b小于0或大于所有元素索引值
		return false;

	LinkNode *p = FindIndex(a),*q = FindIndex(b);  //找到索引为a和b的元素结点
	ElemType temp = p ->data;  //创建临时变量temp用于交换
	p ->data = q ->data;
	q ->data = temp;
	return true;
}


bool LinkList::Traversal()
{
	if(Empty())  //链表为空
		return false;

	LinkNode *p = head;
	while(p != NULL)  //遍历链表输出元素值
	{
		cout << p ->data << endl;
		p = p ->next;
	}
	return true;
}


LinkNode *LinkList::FindIndex(int index)
{
	if(index <0 || index >= Length())  //index小于0或index大于所有元素索引值
		return NULL;

	int current = 0;  //当前索引值
	LinkNode *p = head;
	while(p != NULL && current != index)  //当前索引值不为index时继续遍历链表
	{
		current++;
		p = p ->next;
	}
	return p;  //返回索引为index的结点指针
}