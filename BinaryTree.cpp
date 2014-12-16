#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	root = (BTNode*)malloc(sizeof(BTNode));  //初始化根结点指针
	root ->data = NULL;
	root ->lchild = NULL;
	root ->rchild = NULL;
}


BinaryTree::~BinaryTree()
{
}
