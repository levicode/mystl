#pragma once
typedef int ElemType;  //��ջԪ������

struct LinkNode  //��ջ���
{
	ElemType data;  //�������
	struct LinkNode *next;  //��һ���ָ��
};

class LinkStack
{
public:
	LinkStack();  //���캯��
	~LinkStack();  //��������
	int Length();  //������ջ����
	bool Empty();  //�ж���ջ�Ƿ�Ϊ��
	bool Push(ElemType element);  //��ջ��ѹ��һ��Ԫ��element
	bool Pop(ElemType &elemnet);  //��ջ��ȡ��һ��Ԫ�ط��ظ�element
	bool GetTop(ElemType &element);  //��ȡջ��Ԫ�ط��ظ�element
	void Clear();  //���ջ
	bool Traversal();  //����ջ
private:
	LinkNode *top;  //ջ��ָ��
};
