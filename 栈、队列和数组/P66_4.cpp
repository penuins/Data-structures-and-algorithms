//
//
//

bool isDuiCheng(LinkList L, int n)
{
    int k = 0;
    LNode* p = L;
    stack<char> s;
    while(k < n / 2)
    {
        s.push(p.data);
        p = p-next;
        k++;
    }
    if(n % 2 == 1)
    {
        k++;
        p = p->next;
    }
    while(k < n)
    {
        char x;
        s.pop(x);
        if(x != p.data)
            return false;
        k++;
        p = p->next;
    }
    return true;
}
