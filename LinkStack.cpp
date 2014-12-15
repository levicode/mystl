#include "LinkStack.h"
#include <iostream>
using namespace std;

LinkStack::LinkStack()
{
	top = NULL;  //初始化栈顶指针
}


LinkStack::~LinkStack()
{
	LinkNode *p = top;
	while(p != NULL)  //顺序遍历链栈元素释放元素结点内存
	{
		top = p ->next;
		delete p;
		p = top;
	}
	delete top;
}


int LinkStack::Length()
{
	int length = 0;
	LinkNode *p = top;
		while(p != NULL)  //顺序遍历链栈元素统计结点个数
	{
		length++;  //元素存在则长度加1
		p = p ->next;
	}
	return length;
}


bool LinkStack::Empty()
{
	return top == NULL;  //栈顶指针指向NULL则链栈为空
}


bool LinkStack::Push(ElemType element)
{
	LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));  //初始化新结点
	newnode ->data = element;
	newnode ->next = top;  //新结点的next指向原来的top结点
	top = newnode; //将栈顶指针指向新结点
	return true;
}


bool LinkStack::Pop(ElemType &element)
{
	if(top == NULL)  //链栈为空
		return false;

	element = top ->data;  //将栈顶元素赋值给element
	LinkNode *p = top;
	top = top ->next;  //栈顶指针向下移动一位
	delete p;  //释放出栈元素内存
	return true;
}


bool LinkStack::GetTop(ElemType &element)
{
	if(top == NULL)  //链栈为空
		return false;

	element = top ->data;  //将栈顶元素赋值给element
	return true;
}


void LinkStack::Clear()
{
	LinkNode *p = top;
	while(p != NULL)  //遍历链栈释放元素结点内存,释放后栈顶指针指向NULL
	{
		top = p ->next;
		delete p;
		p = top;
	}
}


bool LinkStack::Traversal()
{
	if(top == NULL)  //链栈为空
		return false;

	LinkNode *p = top;
	while(p != NULL)  //遍历链栈输出元素值
	{
		cout << p ->data << endl;
		p = p ->next;
	}
	return true;
}