#ifndef SQLIST_H
#define SQLIST_H

#include<stdlib.h>      // malloc()，free()函数的头文件

typedef int ElemType;   // 定义 int 型的别名 ElemType

//
// 顺序表(静态分配)
//

#define MaxSize 100          // 顺序表的最大长度

typedef struct{
	ElemType data[MaxSize];  // 数据元素
	int length;              // 顺序表表长
}SqList;                     // 顺序表类型定义

// 初始化
void InitList(SqList &L)
{
	for(int i = 0; i < MaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
}

// 插入操作
bool ListInsert(SqList &L, int i, ElemType x)
{
	if(i < 1 || i > L.length + 1)       // 插入位置合法性检查
		return false;
	for(int j = L.length; j >= i; j--)  // 将 L.data[i - 1 : L.length - 1] 后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = x;                  // 将 e 插入到 L.data[i - 1]
	L.length++;                         // 修改顺序表表长
	return true;
}

// 删除操作
bool ListDelete(SqList &L, int i, ElemType &x)
{
	if(i < 1 || i > L.length)          // 删除位置合法性检查
		return false;
	x = L.data[i - 1];                 // 返回被删除的元素
	for(int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];     // 将 L.data[i : L.length - 1] 前移
	L.length--;                        // 修改顺序表表长
	return true;
}

// 按值查找
int LocateElem(SqList L, ElemType x)
{
	for(int i = 0; i < L.length; i++)
		if(L.data[i] == x)
			return i + 1;
	return 0;
}

// 按位查找
ElemType GetElem(SqList L, int i)
{
	if(i < 1 || i > L.length)   // 查找位置合法性检查
		exit(-1);
	return L.data[i - 1];       // 返回被查找的数据元素
}

// 求表长
int Length(SqList L)
{
	return L.length;
}

// 判空
bool Emptty(SqList L)
{
	if(L.length == 0)
		return true;
	return false;
}

// 遍历
void PrintList(SqList L)
{
	for(int i = 0; i < L.length; i++)
		std::cout << L.data[i] << " ";
	std::cout << std::endl;
}

#endif // !SQLIST_H
