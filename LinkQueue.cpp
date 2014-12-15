#include "LinkQueue.h"
#include <iostream>
using namespace std;

LinkQueue::LinkQueue()
{
	front = rear = NULL;  //��ʼ������ָ��Ͷ�βָ��
}


LinkQueue::~LinkQueue()
{
	LinkNode *p = front;
	while(p != NULL)  //˳�����������Ԫ���ͷ�Ԫ�ؽ���ڴ�
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
	while(p != NULL)  //˳�����������Ԫ��ͳ�ƽ�����
	{
		length++;  //Ԫ�ش����򳤶ȼ�1
		p = p ->next;
	}
	return length;
}


bool LinkQueue::Empty()
{
	return front == NULL;  //����ָ��Ϊ����������Ϊ��
}


void LinkQueue::EnQueue(ElemType element)
{
	LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));  //��ʼ���½��
	newnode ->data = element;
	newnode ->next = NULL;
	if(front == NULL)  //������Ϊ��
	{
		front = rear = newnode;  //������ָ��Ͷ�βָ�붼ָ���½��
	}
	else
	{
		rear ->next = newnode;  //ԭ��βԪ�ص�nextָ��ָ���½��
		rear = newnode;  //��βָ��ָ���½��
	}
}


bool LinkQueue::DeQueue(ElemType &element)
{
	if(front == NULL)  //������Ϊ��
		return false;

	element = front ->data;  //������Ԫ��ֵ���ظ�element
	LinkNode *p = front;
	front = front ->next;  //����ָ������ƶ�һλ
	delete p;  //�ͷų��ӽ���ڴ�
	return true;
}


bool LinkQueue::GetHead(ElemType &element)
{
	if(front == NULL)  //������Ϊ��
		return false;

	element = front ->data;  //������Ԫ�ط��ظ�element
	return true;
}


void LinkQueue::Clear()
{
	LinkNode *p = front;
	while(p != NULL)  //�����������ͷ�Ԫ�ؽ���ڴ�,�ͷź����ָ��ָ��NULL
	{
		front = p ->next;
		delete p;
		p = front;
	}
	rear = NULL;  //����βָ����ΪNULL
}


bool LinkQueue::Traversal()
{
	if(front == NULL)  //������Ϊ��
		return false;

	LinkNode *p = front;
	while(p != NULL)  //�Ӷ���Ԫ�ؿ�ʼ�������Ԫ��ֵ
	{
		cout<< p ->data <<endl;
		p = p ->next;
	}
	return true;
}