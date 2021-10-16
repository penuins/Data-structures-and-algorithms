//
// 12. 删除单链表中的重复元素
//
// 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素
//

// 假设该单链表有头结点
void Remove_Duplicate(LinkList& L)
{
    if(L->next == NULL)         // 如果链表为空则直接退出
        exit(-1);
    
    LNode* slow = L->next;      // 新链表尾指针
    LNode* fast = slow->next;   // 遍历原链表使用的指针
    while(fast != NULL)
    {
        // 如果当前处理元素与新链表中最后一个元素相等
        // 则将该元素插入到新链表的末尾位置
        if(slow->data != fast->data)
            slow->next = fast;
            slow = fast;
        fast = fast->next;
    }
}

//
// 如果某个结点值重复则直接在逻辑上删除，物理上结点仍然占用存储空间
//


