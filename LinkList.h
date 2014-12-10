#pragma once
typedef int ElemType;  //����Ԫ������

struct LinkNode  //�������
{
	ElemType data;  //�������
	struct LinkNode *next;  //��һ���ָ��
};

class LinkList
{
public:
	LinkList();  //���캯��
	~LinkList();  //��������
	int Length();  //������������
	bool Empty();  //�ж������Ƿ�Ϊ��
	bool Insert(int index, ElemType element);  //��index������Ԫ��element
	bool Delete(int index, ElemType &element);  //ɾ��index��Ԫ�ز���ֵ���ظ�element
	void Clear();  //�������
	bool Swap(int a, int b);  //��������Ϊa��b����Ԫ�ص�ֵ
	bool Traversal();  //����Ԫ��
	LinkNode *FindIndex(int index);  //��������Ϊindex��Ԫ�ؽ�㲢����
private:
	LinkNode *head;  //����ͷָ��
};
