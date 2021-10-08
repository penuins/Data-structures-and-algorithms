#ifndef SQLIST_H
#define SQLIST_H

#include<stdlib.h		// malloc()，free()函数的头文件

typedef int ElemType;	// 定义 int 型的别名 ElemType

//
// 顺序表(静态分配)
//

#define MaxSize 100			// 顺序表的最大长度

typedef struct{
	ElemType data[MaxSize];	// 数据元素
	int length;				// 顺序表表长
}SqList;					// 顺序表类型定义

// 初始化
void InitList(SqList &L)
{
	for(int i = 0; i < MaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
}

// 插入操作
bool ListInsert(SqList &L, int i, ElemType e)
{
	if(i < 1 || i > L.length + 1)	// 插入位置合法性检查
		return false;
	for(int j = L.length; j >= i; j--)	// 将 L.data[i - 1 : L.length - 1] 后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;		// 将 e 插入到 L.data[i - 1]
	// 修改顺序表表长
	L.length++;
}

#endif // !SQLIST_H
