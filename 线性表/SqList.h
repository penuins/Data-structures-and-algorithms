#ifndef SQLIST_H
#define SQLIST_H

#include<stdlib.h>	// malloc()，free() 函数的头文件

typedef int ElemType;

/* 顺序表：静态分配 */

#define MaxSize 100	// 顺序表的最大长度

typedef struct {
	ElemType data[MaxSize];	// 数据元素
	int length;				// 顺序表表长
}SqList;					// 顺序表的类型定义

// 初始化表
void InitList(SqList& L)
{
	L.length = 0;
}

// 插入操作
bool ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1)			// 判断 i 的范围是否有效
		return false;
	if (L.length == MaxSize)			// 当前存储空间已满，不能插入
		return false;

	for (int j = L.length; j >= i; j--)	// 将第 i 个元素及之后的元素后移
	/* 
	* for (int j = L.length-1; j >= i - 1; j--)
	*     L.data[j + 1] = L.data[j];
	*/
		L.data[j] = L.data[j - 1];	
	L.data[i - 1] = e;					// 在位置 i 处放入 e
	L.length++;							// 线性表长度加 1
	return true;
}

// 删除操作
bool ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length)						// 判断 i 的范围是否有效
		return false;

	e = L.data[i - 1];							// 将被删除的元素赋值给 e
	for (int j = i - 1; j < L.length - 1; j++)	// 将第 i 个位置后的元素前移
	/*
	* for (int j = i; j < L.length; j++)
	*     L.data[j - 1] = L.data[j];
	*/
		L.data[j] = L.data[j + 1];
	L.length--;									// 线性表长度减 1
	return true;
}

// 按值查找
int LocateElem(SqList& L, ElemType e)
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;		// 下表为 i 的元素值等于 e, 返回其位序 i+1
	return 0;					// 退出循环, 说明查找失败
}

// 按位查找
ElemType GetElem(SqList& L, int i)
{
	if (i<1 || i>L.length)
	{
		std::cout << "GetElem(): i 的位置不合法 !" << std::endl;
		exit(-1);
	}
	return L.data[i - 1];
}

// 判空操作
bool Empty(SqList L)
{
	if (L.length == 0)
		return true;
	return false;
}

// 求表长
int Length(SqList L)
{
	return L.length;
}

// 输出操作
void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++)
		std::cout << L.data[i] << "_";
	std::cout << std::endl;
}


/* 动态分配数组的顺序表 */

#define InitSize 100				// 表长度的初始定义

typedef struct {
	ElemType *data;					// 指示动态分配数组的指针
	int maxsize, length;			// 数组的最大容量和当前个数
}SeqList;			                // 动态分配数组顺序表的类型定义

// 初始化表
void InitList(SeqList& L)
{
	// 使用malloc函数申请一片连续的存储空间
	L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L.length = 0;
	L.maxsize = InitSize;
}

/* 其它操作与静态分配方式下的类似*/

// 增加动态数组的长度
void IncreaseSize(SeqList& L, int len)
{
	ElemType* p = L.data;
	L.data = (ElemType*)malloc((L.maxsize + len) * sizeof(ElemType));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];						// 将数据复制到新区域
	}
	L.maxsize = L.maxsize + len;	            // 顺序表的最大长度增加 len
	free(p);									// 释放原来的存储空间
}


#endif // !SQLIST_H
