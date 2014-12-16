#pragma once
typedef int ElemType;  //������Ԫ������

struct BTNode  //���������
{
	ElemType data;  //�����������
	BTNode *lchild;  //���ӽ��ָ��
	BTNode *rchild;  //�Һ��ӽ��ָ��
}

class BinaryTree
{
public:
	BinaryTree();  //���캯��
	~BinaryTree();  //��������
	void Create(ElemType data[], int n);  //������Ԫ�ش���������
	bool PreOrder();  //�������������
	bool InOrder();  //�������������
	bool PostOrder();  //�������������
	bool LevelOrder();  //��α���������
private:
	BTNode *root;  //�����������ָ��
};
