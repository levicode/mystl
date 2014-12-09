#include "SqList.h"

#include <iostream>
using namespace std;

SqList::SqList()
{
	length = 0;  //˳������ȳ�ʼ��Ϊ0
}


SqList::~SqList()
{
	delete [] data;  //�ͷ�˳��������ڴ�
}


int SqList::Length()
{
	return length;  //����˳�������
}


bool SqList::Empty()
{
	if(length == 0)  //˳�������Ϊ0
		return true;
	else
		return false;
}


bool SqList::Insert(int index, ElemType element)
{
	if(length == MAXSIZE || index < 0)  //˳������ȴﵽ���ֵ��indexС��0
		return false;

	if(index < length)  //index������Ԫ��
	{
		for(int i = length; i > index; i--)  //��index��ʼԪ������ƶ�һλ
			data[i] = data[i-1];
		data[index] = element;  //��index������element
	}
	else
		data[length] == element;  //��˳���ĩβ����element
	length++;  //���ȼ�1
	return true;
}


bool SqList::Delete(int index, ElemType &element)
{
	if(length == 0 || index < 0 || index >= length)  //˳���Ϊ�ջ�indexС��0��index��������Ԫ������ֵ
		return false;

	element = data[index];  //ɾ��Ԫ�ط��ظ�element
	for(int i = index; i < length-1; i++)  //index���Ԫ����ǰ�ƶ�һλ
		data[i] = data[i+1];
	length--;  //���ȼ�1
	return true;
}


void SqList::Clear()
{
	length = 0;  //˳���������Ϊ0
}

bool SqList::Swap(int a, int b)
{
	if(length == 0 || a < 0 || a >= length || b < 0 || b >= length)  //˳���Ϊ��,a��bС��0���������Ԫ������ֵ
		return false;

	ElemType temp = data[a];  //������ʱ����temp���ڽ���
	data[a] = data[b];
	data[b] = temp;
	return true;
}


bool SqList::Traversal()
{
	if(length == 0)  //˳���Ϊ��
		return false;

	for(int i = 0; i < length; i++)  //�����������Ԫ��ֵ
	{
		cout<<data[i]<<endl;
	}
	return true;
}