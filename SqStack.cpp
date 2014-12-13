#include "SqStack.h"
#include <iostream>
using namespace std;

SqStack::SqStack(int size)
{
	SIZE = size;  //ʹ��size��ʼ��˳��ջ����
	sqstack = new ElemType [size];  //��ʼ��˳��ջ����
	top = -1;  //��ʼ��ջ��ָ��
}


SqStack::~SqStack()
{
	delete [] sqstack;  //�ͷ�˳��ջԪ�������ڴ�
	SIZE = 0;  //��λ˳��ջ����
}


int SqStack::Length()
{
	return top + 1;  //ջ��ָ���1��Ϊ˳��ջ�ĳ���
}


bool SqStack::Empty()
{
	if(top == -1)  //ջ��ָ��Ϊ-1ʱ˳��ջΪ��
		return true;
	else
		return false;
}


bool SqStack::Push(ElemType element)
{
	if(top + 1 == SIZE)  //˳��ջԪ������
		return false;

	top++;  //ջ��ָ�������ƶ�һλ
	sqstack[top] = element;  //��ջ�������µ�Ԫ��
	return true;
}


bool SqStack::Pop(ElemType &element)
{
	if(top == -1)  //˳��ջΪ��
		return false;

	element = sqstack[top];  //��ջ��Ԫ�ظ�ֵ��element
	top--;  //ջ��ָ�������ƶ�һλ
	return true;
}


bool SqStack::GetTop(ElemType &element)
{
	if(top == -1)  //˳��ջΪ��
		return false;

	element = sqstack[top];  //��ջ��Ԫ�ظ�ֵ��element
	return true;
}


void SqStack::Clear()
{
	top = -1;  //ջ��ָ����Ϊ-1
}


bool SqStack::Traversal()
{
	if(top == -1)  //˳��ջΪ��
		return false;

	int current = top;
	while(current != -1)  //��ջ����ʼ����˳��ջ���Ԫ��ֵ
	{
		cout<< sqstack[current--] << endl;  //������currentָ�������ƶ�һλ
	}
	return true;
}