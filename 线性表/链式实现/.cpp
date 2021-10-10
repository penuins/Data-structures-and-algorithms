//
//
//


void Reverse(LinkList& L)
{
    LNode* p = L->next;
    while(p != NULL)
    {
        // 从原链表摘除一个结点
        LNode* s = p;
        p = p->next;
        s->next = NULL;
        
        // 将s插入到头结点后边
        s->next = L->next;
        L->next = s;
    }
}

void Reverse_N(LinkList& L)
{
    LNode* p = NULL;
    while(L != NULL)
    {
        // 从原链表摘除一个结点
        LNode* s = L;
        L = L->next;
        s->next = NULL;
        
        // 将s插入到第一个位置
        s->next = p;
        p = s;
    }
}

void Reverse_x(LinkList& L, int left, int right)
{
}
