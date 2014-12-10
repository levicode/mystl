#pragma once
typedef int ElemType;  //顺序表元素类型
#define MAXSIZE 1000  //顺序表最大长度

class SqList
{
public:
	SqList();  //构造函数
	~SqList();  //析构函数
	int Length();  //返回长度
	bool Empty();  //判断是否为空
	bool Insert(int index, ElemType element);  //插入指定元素element到index
	bool Delete(int index, ElemType &element);  //删除指定元素index并返回给element
	void Clear();  //清空元素
	bool Swap(int a, int b);  //交换两个元素
	bool Traversal();  //遍历元素
private:
	ElemType *data;  //顺序表元素数据
	int length;  //顺序表长度
};

