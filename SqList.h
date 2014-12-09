#pragma once
typedef int ElemType  //˳���Ԫ������
const int MAXSIZE=1000;  //˳�����󳤶�

class SqList
{
public:
	SqList();  //���캯��
	~SqList();  //��������
	int Length();  //���س���
	bool Empty();  //�ж��Ƿ�Ϊ��
	bool Insert(int index, ElemType element);  //����ָ��Ԫ��element��index
	bool Delete(int index, ElemType &element);  //ɾ��ָ��Ԫ��index�����ظ�element
	void Clear();  //���Ԫ��
	bool Swap(int a, int b);  //��������Ԫ��
	bool Traversal();  //����Ԫ��
private:
	ElemType data[MAXSIZE];  //˳���Ԫ������
	int length;  //˳�������
};
