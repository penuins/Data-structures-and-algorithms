//
// 试编写在带头结点的单链表L中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
//

void Delete_Minimum(LinkList& L)
{
    LNode* min_pre = L;    // 保存最小值结点的前驱
    LNode* pre = p = L;
    p = p->next;
    while(p != NULL)
    {
        if(p->data < min_pre->next->data)
            min_pre = pre;
        pre = pre->next;
        p = p->next;
    }
}



