//
// 有一个带头节点的单链表L，设计一个算法使其元素递增有序
//

void LinkList_Sort(LinkList& L)
{
    LNode* p = L->next;
    L->next = NULL;
    while(p != NULL)
    {
        // 摘下一个结点
        LNode* s = p;
        p = p->next;
        
        // 寻找插入位置
        LNode* q = L->next;
        while(q != NULL)
        {
            if(q->next->data <= s->data)
                q = q->next;
        }
        
        // 将结点s插入新链表
        s->next = q->next;
        q->next = s;
    }
}



