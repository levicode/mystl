#pragma once
typedef int ElemType;  //链队列元素类型

struct LinkNode  //链队列结点
{
	ElemType data;  //结点数据
	struct LinkNode *next;  //下一结点指针
};

class LinkQueue
{
public:
	LinkQueue();  //构造函数
	~LinkQueue();  //析构函数
	int Length();  //返回链队列的长度
	bool Empty();  //判断链队列是否为空
	void EnQueue(ElemType element);  //向链队列队尾压入一个元素element
	bool DeQueue(ElemType &element);  //将链队列队首元素取出队列并返回给element
	bool GetHead(ElemType &element);  //获取链队列队首元素返回给element
	void Clear();  //清空队列
	bool Traversal();   //从队首开始遍历队列
private:
	LinkNode *front;  //队首指针
	LinkNode *rear;  //队尾指针
};

