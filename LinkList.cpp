#include "LinkList.h"
#include <iostream>
using namespace std;

LinkList::LinkList()
{
	head = new LinkNode();  //��ʼ������ͷָ��
	head ->data = NULL;
	head ->next = NULL;
}


LinkList::~LinkList()
{
	LinkNode *p = head;
	while(p != NULL)  //˳���������Ԫ���ͷ�Ԫ�ؽ���ڴ�
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
	while(p != NULL)  //˳���������Ԫ��ͳ�ƽ�����
	{
		length++;  //Ԫ�ش����򳤶ȼ�1
		p = p ->next;
	}
	return length;
}


bool LinkList::Empty()
{
	if(head == NULL)  //ͷָ��ָ��NULL������Ϊ��
		return true;
	else
		return false;
}


bool LinkList::Insert(int index, ElemType element)
{
	if(index < 0)  //indexС��0
		return false;

	LinkNode *newnode = new LinkNode();  //�����½��
	newnode ->data = element;  //��ʼ���½��
	newnode ->next = NULL;

	if(index == 0 || head == NULL)  //indexΪ0������Ϊ��ʱ�ڱ�ͷ�����½��
	{
		newnode ->next = head;
		head = newnode;
	}
	else if(index < Length())  //index������Ԫ��������
	{
		LinkNode *p = FindIndex(index - 1);  //�ҵ�����Ϊindex-1�Ľ��
		newnode ->next = p ->next;  //�½���nextָ������Ϊindex�Ľ��
		p ->next = newnode;  //����Ϊindex-1�Ľ���nextָ���½��
	}
	else  //index��������Ԫ������ֵ���ڱ�β�����½��
	{
		LinkNode *p = head;
		while(p ->next != NULL)  //�ҵ���β���
		{
			p = p ->next;
		}
		p ->next = newnode;  //��β����nextָ���½��
	}
	return true;
}


bool LinkList::Delete(int index, ElemType &element)
{
	if(head == NULL || index < 0  || index >= Length())  //����Ϊ�ջ�indexС��0��index��������Ԫ������ֵ
		return false;

	if(index == 0)  //indexΪ0ʱɾ���׽��
	{
		LinkNode *p = head;
		head = head ->next;  //ͷָ��ָ����һ�����
		delete p;  //�ͷ�ɾ������ڴ�
	}
	else  //index������Ԫ��������
	{
		LinkNode *p = FindIndex(index - 1);  //�ҵ�����Ϊindex-1�Ľ��
		LinkNode *q = p ->next;  //qָ������Ϊindex�Ľ��
		p ->next = q ->next;  //����Ϊindex-1 �Ľ���nextָ������Ϊindex�Ľ���next���
		delete q;  //�ͷ�����Ϊindex�Ľ���ڴ�
	}
	return true;
}


void LinkList::Clear()
{
	LinkNode *p = head;
	while(p != NULL)  //���������ͷ�Ԫ�ؽ���ڴ�,�ͷź�ͷָ��headָ��NULL
	{
		head = p ->next;
		delete p;
		p = head;
	}
}


bool LinkList::Swap(int a, int b)
{
	if(Empty() || a < 0 || a >= Length() || b < 0 || b >= Length())  //����Ϊ��,a��bС��0���������Ԫ������ֵ
		return false;

	LinkNode *p = FindIndex(a),*q = FindIndex(b);  //�ҵ�����Ϊa��b��Ԫ�ؽ��
	ElemType temp = p ->data;  //������ʱ����temp���ڽ���
	p ->data = q ->data;
	q ->data = temp;
	return true;
}


bool LinkList::Traversal()
{
	if(Empty())  //����Ϊ��
		return false;

	LinkNode *p = head;
	while(p != NULL)  //�����������Ԫ��ֵ
	{
		cout << p ->data << endl;
		p = p ->next;
	}
	return true;
}


LinkNode *LinkList::FindIndex(int index)
{
	if(index <0 || index >= Length())  //indexС��0��index��������Ԫ������ֵ
		return NULL;

	int current = 0;  //��ǰ����ֵ
	LinkNode *p = head;
	while(p != NULL && current != index)  //��ǰ����ֵ��Ϊindexʱ������������
	{
		current++;
		p = p ->next;
	}
	return p;  //��������Ϊindex�Ľ��ָ��
}