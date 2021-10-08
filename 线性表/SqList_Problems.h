#include"SqList.h"
#include<vector>

//
// 1. 旋转数组
//

// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
void Rotate(SqList& L, int k)
{
	k = k % L.length;                   // 循环右移位数
	Reverse(L, 0, L.length - 1);        // (ab)^(-1) -> ba
	Reverse(L, 0, k - 1);               // ba -> b^(-1)a
	Reverse(L, k - 1, L.length - 1);    // b^(-1)a -> b^(-1)a^(-1)
}

// 将数组中从 left 到 right 的部分逆置
void Reverse(SqList& L, int left, int right)
{
	while(left < right)
	{
		swap(L.data[left], L.data[right]);
		left++;
		right--;
	}
}

// 交换 a 与 b 的值
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}



//
// /* 双指针法 */ //
//

//
// 2. 删除排序数组中值为 x 的元素
//

void Del_x(SqList& L, int x)
{
	int fast = 0;            // fast: 遍历数组到达的下标位置
	int slow = 0;            // slow: 下一个不为 x 的元素要填入的下标位置
	while(fast < n)
	{
		if(L.data[fast] != x)
			L.data[slow++] = L.data[fast];
		fast++;
	}
	L.length = slow + 1;     // 更新顺序表的长度
}

//
// 3. 删除排序数组中重复的元素
//

void Remove_Duplicates(SqList& L)
{
	int fast = 1;           // 快指针 fast：遍历数组到达的下标位置
	int slow = 1;           // 慢指针 slow：下一个不同元素要填入的下标位置
	while(fast < L.length)           
	{
		if(L.data[fast] != L.data[slow - 1])
			L.data[slow++] = L.data[fast];
		fast++;
	}
	L.length = slow;        // 更新顺序表的长度
}

