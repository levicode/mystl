#pragma once
typedef int ElemType;  //链表元素类型

struct LinkNode  //链表结点
{
	ElemType data;  //结点数据
	struct LinkNode *next;  //下一结点指针
};

class LinkList
{
public:
	LinkList();  //构造函数
	~LinkList();  //析构函数
	int Length();  //返回链表长度
	bool Empty();  //判断链表是否为空
	bool Insert(int index, ElemType element);  //在index处插入元素element
	bool Delete(int index, ElemType &element);  //删除index处元素并将值返回给element
	void Clear();  //清空链表
	bool Swap(int a, int b);  //交换索引为a和b两个元素的值
	bool Traversal();  //遍历元素
	LinkNode *FindIndex(int index);  //查找索引为index的元素结点并返回
private:
	LinkNode *head;  //链表头指针
};

