#pragma once
typedef int ElemType;  //˳��ջԪ������
int SIZE = 0;  //˳��ջ������

class SqStack
{
public:
	SqStack(int size);  //���캯��
	~SqStack();  //��������
	int Length();  //��ȡ˳��ջ�ĳ���
	bool Empty();  //�ж�˳��ջ�Ƿ�Ϊ��
	bool Push(ElemType element);  //��ջ��ѹ��һ��Ԫ��element
	bool Pop(ElemType &element);  //��ջ��ȡ��һ��Ԫ�ط��ظ�element
	bool GetTop(ElemType &element);  //��ȡջ��Ԫ�ط��ظ�element
	void Clear();  //���ջ
	bool Traversal();  //����ջ
private:
	ElemType *sqstack;  //˳��ջԪ������
	int top;  //ջ��ָ��
};
