//
// 试编写算法将带头结点的单链表就地逆置，所谓“就地”是指辅助空间复杂度为O(1)
//

void Reverse_LinkList(LinkList& L)
{
    LNode* p = L->next;
    L->next = NULL;
    while(p != NULL)
    {
        LNode* s = p;        // 摘掉第一个结点
        p = p->next;
        
        // s->next = NULL;
        
        s->next = L->next;   // 插入头结点后边
        L->next = s;
    }
}

