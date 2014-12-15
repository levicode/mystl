#include "LinkQueue.h"
#include <iostream>
using namespace std;

LinkQueue::LinkQueue()
{
	front = rear = NULL;  //初始化队首指针和队尾指针
}


LinkQueue::~LinkQueue()
{
	LinkNode *p = front;
	while(p != NULL)  //顺序遍历链队列元素释放元素结点内存
	{
		front = p ->next;
		delete p;
		p = front;
	}
}


int LinkQueue::Length()
{
	int length = 0;
	LinkNode *p = front;
	while(p != NULL)  //顺序遍历链队列元素统计结点个数
	{
		length++;  //元素存在则长度加1
		p = p ->next;
	}
	return length;
}


bool LinkQueue::Empty()
{
	return front == NULL;  //队首指针为空则链队列为空
}


void LinkQueue::EnQueue(ElemType element)
{
	LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));  //初始化新结点
	newnode ->data = element;
	newnode ->next = NULL;
	if(front == NULL)  //链队列为空
	{
		front = rear = newnode;  //将队首指针和队尾指针都指向新结点
	}
	else
	{
		rear ->next = newnode;  //原队尾元素的next指针指向新结点
		rear = newnode;  //队尾指针指向新结点
	}
}


bool LinkQueue::DeQueue(ElemType &element)
{
	if(front == NULL)  //链队列为空
		return false;

	element = front ->data;  //将队首元素值返回给element
	LinkNode *p = front;
	front = front ->next;  //队首指针向后移动一位
	delete p;  //释放出队结点内存
	return true;
}


bool LinkQueue::GetHead(ElemType &element)
{
	if(front == NULL)  //链队列为空
		return false;

	element = front ->data;  //将队首元素返回给element
	return true;
}


void LinkQueue::Clear()
{
	LinkNode *p = front;
	while(p != NULL)  //遍历链队列释放元素结点内存,释放后队首指针指向NULL
	{
		front = p ->next;
		delete p;
		p = front;
	}
	rear = NULL;  //将队尾指针置为NULL
}


bool LinkQueue::Traversal()
{
	if(front == NULL)  //链队列为空
		return false;

	LinkNode *p = front;
	while(p != NULL)  //从队首元素开始遍历输出元素值
	{
		cout<< p ->data <<endl;
		p = p ->next;
	}
	return true;
}