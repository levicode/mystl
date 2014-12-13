#include "LinkStack.h"
#include <iostream>
using namespace std;

LinkStack::LinkStack()
{
	top = NULL;  //��ʼ��ջ��ָ��
}


LinkStack::~LinkStack()
{
	LinkNode *p = top;
	while(p != NULL)  //˳�������ջԪ���ͷ�Ԫ�ؽ���ڴ�
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
		while(p != NULL)  //˳�������ջԪ��ͳ�ƽ�����
	{
		length++;  //Ԫ�ش����򳤶ȼ�1
		p = p ->next;
	}
	return length;
}


bool LinkStack::Empty()
{
	if(top == NULL)  //ջ��ָ��ָ��NULL����ջΪ��
		return true;
	else
		return false;
}


bool LinkStack::Push(ElemType element)
{
	LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));  //��ʼ���½��
	newnode ->data = element;
	newnode ->next = top;  //�½���nextָ��ԭ����top���
	top = newnode; //��ջ��ָ��ָ���½��
	return true;
}


bool LinkStack::Pop(ElemType &element)
{
	if(top == NULL)  //��ջΪ��
		return false;

	element = top ->data;  //��ջ��Ԫ�ظ�ֵ��element
	LinkNode *p = top;
	top = top ->next;  //ջ��ָ�������ƶ�һλ
	delete p;  //�ͷų�ջԪ���ڴ�
	return true;
}


bool LinkStack::GetTop(ElemType &element)
{
	if(top == NULL)  //��ջΪ��
		return false;

	element = top ->data;  //��ջ��Ԫ�ظ�ֵ��element
	return true;
}


void LinkStack::Clear()
{
	LinkNode *p = top;
	while(p != NULL)  //������ջ�ͷ�Ԫ�ؽ���ڴ�,�ͷź�ջ��ָ��ָ��NULL
	{
		top = p ->next;
		delete p;
		p = top;
	}
}


bool LinkStack::Traversal()
{
	if(top == NULL)  //��ջΪ��
		return false;

	LinkNode *p = top;
	while(p != NULL)  //������ջ���Ԫ��ֵ
	{
		cout << p ->data << endl;
		p = p ->next;
	}
	return true;
}