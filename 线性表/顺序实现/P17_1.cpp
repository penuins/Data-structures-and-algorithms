//
// 删除顺序表中最小的元素，空出的位置用最后一个元素代替
//

bool Del_Min(SqList& L)
{
	if(L.length == 0)   // 如果顺序表为空，返回false
		return false;
	int index = 0;      // 最小元素的数组下标，初始化为0
	
	// 找到最小元素的数组下标
	for(int i = 1; i < L.length; i++)
		if(L.data[i] < L.data[index])
			index = i;
	
	// 用末尾元素覆盖最小元素，并将顺序表长度减1
	L.data[index] = L.data[L.length - 1];
	L.length--;
	return true;
}

