#pragma once
typedef int ElemType;  //顺序队列元素类型
int SIZE = 0;  //顺序队列的容量

class SqQueue
{
public:
	SqQueue();  //构造函数
	~SqQueue();  //析构函数
	int Length();  //返回顺序队列的长度
	bool Empty();  //判断顺序队列是否为空
	bool EnQueue(ElemType element);  //向顺序队列队尾压入一个元素element
	bool DeQueue(ElemType &element);  //将顺序队列队首元素取出队列并返回给element
	bool GetHead(ElemType &element);  //获取顺序队列队首元素返回给element
	void Clear();  //清空队列
	bool Traversal();  //从队首开始遍历队列
private:
	ElemType *queue;  //顺序队列元素数据
	int head;  //队首指针
	int rear;  //队尾指针
};

