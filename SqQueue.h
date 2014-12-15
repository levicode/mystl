#pragma once
typedef int ElemType;  //˳�����Ԫ������

class SqQueue
{
public:
	SqQueue(int size);  //���캯��
	~SqQueue();  //��������
	int Length();  //����˳����еĳ���
	bool Empty();  //�ж�˳������Ƿ�Ϊ��
	bool EnQueue(ElemType element);  //��˳����ж�βѹ��һ��Ԫ��element
	bool DeQueue(ElemType &element);  //��˳����ж���Ԫ��ȡ�����в����ظ�element
	bool GetHead(ElemType &element);  //��ȡ˳����ж���Ԫ�ط��ظ�element
	void Clear();  //��ն���
	bool Traversal();  //�Ӷ��׿�ʼ��������
private:
	ElemType *queue;  //˳�����Ԫ������
	int front;  //����ָ��
	int rear;  //��βָ��
	int SIZE;  //˳����е�����
};
