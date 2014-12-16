#pragma once
typedef int ElemType;  //二叉树元素类型

struct BTNode  //二叉树结点
{
	ElemType data;  //结点数据类型
	BTNode *lchild;  //左孩子结点指针
	BTNode *rchild;  //右孩子结点指针
}

class BinaryTree
{
public:
	BinaryTree();  //构造函数
	~BinaryTree();  //析构函数
	void Create(ElemType data[], int n);  //用数组元素创建二叉树
	bool PreOrder();  //先序遍历二叉树
	bool InOrder();  //中序遍历二叉树
	bool PostOrder();  //后序遍历二叉树
	bool LevelOrder();  //层次遍历二叉树
private:
	BTNode *root;  //二叉树根结点指针
};

