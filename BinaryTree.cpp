#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	root = (BTNode*)malloc(sizeof(BTNode));  //��ʼ�������ָ��
	root ->data = NULL;
	root ->lchild = NULL;
	root ->rchild = NULL;
}


BinaryTree::~BinaryTree()
{
}