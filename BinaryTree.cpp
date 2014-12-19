#include "BinaryTree.h"
#include <iostream>
#define MAX 100  //层次遍历循环队列容量
using namespace std;

void Destroy(BTNode *bt);  //后序遍历二叉树释放节点内存
void Visit(BTNode *bt);  //输出结点元素值
void DoPreOrder(BTNode *bt);  //执行先序遍历操作
void InOrder(BTNode *bt);  //执行中序遍历操作
void DoPostOrder(BTNode *bt);  //执行后序遍历操作

BinaryTree::BinaryTree()
{
	root = (BTNode*)malloc(sizeof(BTNode));  //初始化根结点指针
	root ->data = NULL;
	root ->lchild = NULL;
	root ->rchild = NULL;
}


BinaryTree::~BinaryTree()
{
	Destroy(root);  //后序遍历二叉树释放节点内存
}


void Destory(BTNode *bt)
{
	if(bt != NULL)  //结点存在
	{
		Destroy(bt ->lchild);  //递归释放左子树结点内存
		Destroy(bt ->rchild);  //递归释放右子树结点内存

		delete bt;  //释放结点内存
	}
}


void BinaryTree::Create(ElemType data[], int n)
{

}


void Visit(BTNode *bt)
{
	cout<< bt ->data << endl;  //输出结点元素值 
}


bool BinaryTree::PreOrder()
{
	if(root == NULL)  //二叉树为空
		return false;

	DoPreOrder(root);  //执行递归先序遍历二叉树结点
	return true;
}


void DoPreOrder(BTNode *bt)
{
	if(bt != NULL)  //结点存在
	{
		Visit(bt);  //输出节点元素值

		DoPreOrder(bt ->lchild);  //递归先序遍历左子树
		DoPreOrder(bt ->rchild);  //递归先序遍历右子树
	}
}


bool BinaryTree::InOrder()
{
	if(root == NULL)  //二叉树为空
		return false;

	DoInOrder(root);  //执行递归中序遍历二叉树结点
	return true;
}


void DoInOrder(BTNode *bt)
{
	if(bt != NULL)  //结点存在
	{
		DoInOrder(bt ->lchild);  //递归中序遍历左子树

		Visit(bt);  //输出节点元素值

		DoInOrder(bt ->rchild);  //递归中序遍历右子树
	}
}


bool BinaryTree::PostOrder()
{
	if(root == NULL)  //二叉树为空
		return false;

	DoPostOrder(root);  //执行递归后序遍历二叉树结点
	return true;
}


void DoPostOrder(BTNode *bt)
{
	if(bt != NULL)  //结点存在
	{
		DoPostOrder(bt ->lchild);  //递归后序遍历左子树
		DoPostOrder(bt ->rchild);  //递归后序遍历右子树

		Visit(bt);  //输出节点元素值	
	}
}


bool BinaryTree::LevelOrder()
{
	if(root == NULL)  //二叉树为空
		return false;

	int front = 0, rear = 0;  //循环队列，用于存放时二叉树结点
	BTNode *queue[MAX];

	queue[rear] = root;  //将根结点加入队列
	rear = (rear + 1) % MAX;

	BTNode *p;
	while(front != rear)  //当队列不为空
	{
		p = queue[front];  //出队
		front = (front + 1) % MAX;
		Visit(p);  //输出结点元素值
		if(p ->lchild != NULL)  //若左孩子存在则入队
		{
			queue[rear] = p ->lchild;
			rear = (rear + 1) % MAX;
		}
		if(p ->rchild != NULL)  //若右孩子存在则入队
		{
			queue[rear] = p ->rchild;
			rear = (rear +1) % MAX;
		}
	}
	return true;
}


bool BinaryTree::Empty()
{
	return root == NULL;  //如果根结点指针为NULL则二叉树为空  
}
