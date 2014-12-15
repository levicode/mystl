#pragma once
typedef int ElemType;  //������Ԫ������

struct LinkNode  //�����н��
{
	ElemType data;  //�������
	struct LinkNode *next;  //��һ���ָ��
};

class LinkQueue
{
public:
	LinkQueue();  //���캯��
	~LinkQueue();  //��������
	int Length();  //���������еĳ���
	bool Empty();  //�ж��������Ƿ�Ϊ��
	void EnQueue(ElemType element);  //�������ж�βѹ��һ��Ԫ��element
	bool DeQueue(ElemType &element);  //�������ж���Ԫ��ȡ�����в����ظ�element
	bool GetHead(ElemType &element);  //��ȡ�����ж���Ԫ�ط��ظ�element
	void Clear();  //��ն���
	bool Traversal();   //�Ӷ��׿�ʼ��������
private:
	LinkNode *front;  //����ָ��
	LinkNode *rear;  //��βָ��
};
