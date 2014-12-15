#pragma once
typedef int ElemType;  //顺序栈元素类型

class SqStack
{
public:
	SqStack(int size);  //构造函数
	~SqStack();  //析构函数
	int Length();  //获取顺序栈的长度
	bool Empty();  //判断顺序栈是否为空
	bool Push(ElemType element);  //向栈中压入一个元素element
	bool Pop(ElemType &element);  //从栈中取出一个元素返回给element
	bool GetTop(ElemType &element);  //获取栈顶元素返回给element
	void Clear();  //清空栈
	bool Traversal();  //遍历栈
private:
	ElemType *sqstack;  //顺序栈元素数据
	int top;  //栈顶指针
	int SIZE;  //顺序栈的容量
};

