#include "SqStack.h"
#include <iostream>
using namespace std;

SqStack::SqStack(int size)
{
	SIZE = size;  //使用size初始化顺序栈容量
	sqstack = new ElemType [SIZE];  //初始化顺序栈数组
	top = -1;  //初始化栈顶指针
}


SqStack::~SqStack()
{
	delete [] sqstack;  //释放顺序栈元素数组内存
}


int SqStack::Length()
{
	return top + 1;  //栈顶指针加1则为顺序栈的长度
}


bool SqStack::Empty()
{
	return top == -1;  //栈顶指针为-1时顺序栈为空
}


bool SqStack::Push(ElemType element)
{
	if(top + 1 == SIZE)  //顺序栈元素已满
		return false;

	top++;  //栈顶指针向上移动一位
	sqstack[top] = element;  //在栈顶加入新的元素
	return true;
}


bool SqStack::Pop(ElemType &element)
{
	if(top == -1)  //顺序栈为空
		return false;

	element = sqstack[top];  //将栈顶元素赋值给element
	top--;  //栈顶指针向下移动一位
	return true;
}


bool SqStack::GetTop(ElemType &element)
{
	if(top == -1)  //顺序栈为空
		return false;

	element = sqstack[top];  //将栈顶元素赋值给element
	return true;
}


void SqStack::Clear()
{
	top = -1;  //栈顶指针置为-1
}


bool SqStack::Traversal()
{
	if(top == -1)  //顺序栈为空
		return false;

	int current = top;
	while(current != -1)  //从栈顶开始遍历顺序栈输出元素值
	{
		cout<< sqstack[current--] << endl;  //输出完后current指针向下移动一位
	}
	return true;
}