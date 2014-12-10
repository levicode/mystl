#include "SqList.h"

#include <iostream>
using namespace std;

SqList::SqList()
{
	data=new ElemType [MAXSIZE];
	length = 0;  //顺序表长度初始化为0
}


SqList::~SqList()
{
	delete [] data;  //释放顺序表数据内存
}


int SqList::Length()
{
	return length;  //返回顺序表长度
}


bool SqList::Empty()
{
	if(length == 0)  //顺序表长度为0
		return true;
	else
		return false;
}


bool SqList::Insert(int index, ElemType element)
{
	if(length == MAXSIZE || index < 0)  //顺序表长度达到最大值或index小于0
		return false;

	if(index < length)  //index处存在元素
	{
		for(int i = length; i > index; i--)  //从index开始元素向后移动一位
			data[i] = data[i-1];
		data[index] = element;  //在index处添加element
	}
	else
		data[length] = element;  //在顺序表末尾添加element
	length++;  //长度加1
	return true;
}


bool SqList::Delete(int index, ElemType &element)
{
	if(length == 0 || index < 0 || index >= length)  //顺序表为空或index小于0或index大于所有元素索引值
		return false;

	element = data[index];  //删除元素返回给element
	for(int i = index; i < length-1; i++)  //index后的元素向前移动一位
		data[i] = data[i+1];
	length--;  //长度减1
	return true;
}


void SqList::Clear()
{
	length = 0;  //顺序表长度置为0
}

bool SqList::Swap(int a, int b)
{
	if(length == 0 || a < 0 || a >= length || b < 0 || b >= length)  //顺序表为空,a或b小于0或大于所有元素索引值
		return false;

	ElemType temp = data[a];  //创建临时变量temp用于交换
	data[a] = data[b];
	data[b] = temp;
	return true;
}


bool SqList::Traversal()
{
	if(length == 0)  //顺序表为空
		return false;

	for(int i = 0; i < length; i++)  //遍历输出所有元素值
	{
		cout<<data[i]<<endl;
	}
	return true;
}
