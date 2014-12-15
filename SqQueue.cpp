#include "SqQueue.h"
#include <iostream>
using namespace std;

SqQueue::SqQueue(int size)
{
	SIZE = size;  //使用size初始化顺序队列容量
	queue = new ElemType [SIZE];  //初始化顺序队列数组
	front = rear = 0;  //初始化队首指针和队尾指针
}


SqQueue::~SqQueue()
{
	delete [] queue;  //释放顺序队列元素数组内存
}


int SqQueue::Length()
{
	return (rear - front + SIZE) % SIZE;  //返回队列中元素的长度
}


bool SqQueue::Empty()
{
	return front == rear;  //队首指针和队尾指针相等则顺序队列为空
}


bool SqQueue::EnQueue(ElemType element)
{
	if((rear + 1) % SIZE == front)  //顺序队列已满
		return false;

	queue[rear] = element;  //将新元素赋值给队尾
	rear = (rear + 1) % SIZE;  //队尾指针向后移动一位，如果已到数组尾部则从头开始
	return true;
}


bool SqQueue::DeQueue(ElemType &element)
{
	if(front == rear)  //顺序队列为空
		return false;

	element = queue[front];  //将队首元素返回给element
	front = (front + 1 + SIZE) % SIZE;  //队首指针向后移动一位,如果已到数组尾部则从头开始
	return true;
}


bool SqQueue::GetHead(ElemType &element)
{
	if(front == rear)  //顺序队列为空
		return false;

	element = queue[front];  //将队首元素返回给element
	return true;
}


void SqQueue::Clear()
{
	front = rear = 0;  //将队首指针和队尾指针置为0
}


bool SqQueue::Traversal()
{
	if(front == rear)  //顺序队列为空
		return false;

	int i = front;
	while(i != rear)  //从队首元素开始遍历输出元素值
	{
		cout<< queue[i] << endl;
		i = (i + 1 + SIZE) % SIZE;  //i向后移动一位
	}
	return true;
}