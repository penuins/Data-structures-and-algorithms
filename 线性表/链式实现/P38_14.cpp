//
// 设A和B是两个单链表(带头结点)，其中元素递增有序。
// 设计一个算法从A和B中的公共元素产生链表C，要求不破坏A，B的结点
//

void Generation_ListC(LinkList& A, LinkList& B, LinkList& C)
{
    LNode* c = C;
    
    LNode* a = A->next;
    while(a != NULL)
    {
        LNode* b = B->next;
        while(b != NULL)
        {
            
        }
    }
}
