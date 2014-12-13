#pragma once
typedef int ElemType;  //链栈元素类型

struct LinkNode  //链栈结点
{
	ElemType data;  //结点数据
	struct LinkNode *next;  //下一结点指针
};

class LinkStack
{
public:
	LinkStack();  //构造函数
	~LinkStack();  //析构函数
	int Length();  //返回链栈长度
	bool Empty();  //判断链栈是否为空
	bool Push(ElemType element);  //向栈中压入一个元素element
	bool Pop(ElemType &elemnet);  //从栈中取出一个元素返回给element
	bool GetTop(ElemType &element);  //获取栈顶元素返回给element
	void Clear();  //清空栈
	bool Traversal();  //遍历栈
private:
	LinkNode *top;  //栈顶指针
};

