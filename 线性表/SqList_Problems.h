/* -----旋转数组----- */
void Rotate(SqList& L, int k)
{
	k = k % L.length;                   // 循环右移位数
	Reverse(L, 0, L.length - 1);        // (ab)^(-1) -> ba
	Reverse(L, 0, k - 1);               // ba -> b^(-1)a
	Reverse(L, k - 1, L.length - 1);    // b^(-1)a -> b^(-1)a^(-1)
}

/* 将数组中从 left 到 right 的部分逆置 */
void Reverse(SqList& L, int left, int right)
{
	while(left < right)
	{
		swap(L.data[left], L.data[right]);
		left++;
		right--;
	}
}

/* 交换 a 与 b 的值 */
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}



/* -----双指针法----- */

/* -----删除排序数组中值为 x 的元素----- */
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

/* -----删除排序数组中重复的元素----- */
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

/* -----合并有序顺序表----- */
bool MergeList(SqList A, SqList B, SqList& C)
{
	if(A.length + B.length > MaxSize)    // 大于顺序表的最大长度，返回 false
		return false;
	int i = 0, j = 0, k = 0;
	while(i < A.length && j < B.length)  // 循环，两两比较，较小者存入 C
	{
		if(A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	// 将剩余顺序表
	while(i < A.length)
		C.data[k++] = A.data[i++];
	while(j < B.length)
		C.data[k++] = B.data[j++];
	C.length = k;
	return true;
}

/* 两升序顺序表的中位数 */
int M_Search(int A[], int B[], int n)
{
	int left1 = 0, right1 = n - 1, mid1;
	int left2 = 0, right2 = n - 1, mid2;
	while(left1 != right1 || left2 != right2)
	{
		mid1 = (left1 + right1) / 2;
		mid2 = (left2 + right2) / 2;
		// a == b
		if(A[mid1] == B[mid2])
			return A[mid1];
		// a < b 舍弃序列 A 中较小一半，舍弃序列 B 中较大的一半，两次舍弃的长度相等
		if(A[mid1] < B[mid2])
		{
			if((left1 + right1) % 2 == 0)
			{
				left1 = mid1;
				right2 = mid2;
			}
			else
			{
				left1 = mid1 + 1;
				right2 = mid2;
			}
		}
		// a > b 舍弃序列 A 中较大一半，舍弃序列 B 中较小的一半，两次舍弃的长度相等
		else
		{
			if((left2 + right2) % 2 == 0)
			{
				right1 = mid1;
				right2 = mid2;
			}
			else
			{
				right1 = mid1;
				right2 = mid2 + 1;
			}
		}
	}
	// 直到两序列中都只剩一个元素，则较小者为所求的中位数
	if(A[left1] < B[left2])
		return A[left1];
	else
		return B[left2];
}

int Majority(int A[], int n)
{
    int i = 0, major, count = 0;
    while(i < n)
    {
        if(count == 0)
        {
            major = A[i];
            count++;
        }
        else
        {
            if(A[i] == major)
                count++;
            else
                count--;
        }
        i++;
    }
    if(count > 0)
        for(i = count = 0; i < n; i++)
            if(major == A[i])
                count++;
    if(count > n / 2)
        return major;
    else
        return -1;
}
