#include "SqQueue.h"
#include <iostream>
using namespace std;

SqQueue::SqQueue(int size)
{
	SIZE = size;  //ʹ��size��ʼ��˳���������
	queue = new ElemType [SIZE];  //��ʼ��˳���������
	front = rear = 0;  //��ʼ������ָ��Ͷ�βָ��
}


SqQueue::~SqQueue()
{
	delete [] queue;  //�ͷ�˳�����Ԫ�������ڴ�
}


int SqQueue::Length()
{
	return (rear - front + SIZE) % SIZE;  //���ض�����Ԫ�صĳ���
}


bool SqQueue::Empty()
{
	return front == rear;  //����ָ��Ͷ�βָ�������˳�����Ϊ��
}


bool SqQueue::EnQueue(ElemType element)
{
	if((rear + 1) % SIZE == front)  //˳���������
		return false;

	queue[rear] = element;  //����Ԫ�ظ�ֵ����β
	rear = (rear + 1) % SIZE;  //��βָ������ƶ�һλ������ѵ�����β�����ͷ��ʼ
	return true;
}


bool SqQueue::DeQueue(ElemType &element)
{
	if(front == rear)  //˳�����Ϊ��
		return false;

	element = queue[front];  //������Ԫ�ط��ظ�element
	front = (front + 1 + SIZE) % SIZE;  //����ָ������ƶ�һλ,����ѵ�����β�����ͷ��ʼ
	return true;
}


bool SqQueue::GetHead(ElemType &element)
{
	if(front == rear)  //˳�����Ϊ��
		return false;

	element = queue[front];  //������Ԫ�ط��ظ�element
	return true;
}


void SqQueue::Clear()
{
	front = rear = 0;  //������ָ��Ͷ�βָ����Ϊ0
}


bool SqQueue::Traversal()
{
	if(front == rear)  //˳�����Ϊ��
		return false;

	int i = front;
	while(i != rear)  //�Ӷ���Ԫ�ؿ�ʼ�������Ԫ��ֵ
	{
		cout<<queue[i]<<endl;
		i = (i + 1 + SIZE) % SIZE;  //i����ƶ�һλ
	}
	return true;
}