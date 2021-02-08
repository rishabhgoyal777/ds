int countNodesinLoop(struct Node *head)
{
     Node *p= head;
     Node *q= head;
    do {
        p=p->next;
        q=q->next;
        if(q)
        q=q->next;
    }
    while(p && q && p!=q );
    if(p==q)
    { p=p->next; int count=1;
     while(p!=q)
     {count++; p=p->next;}
    return count;}
    else return 0;

}


https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/
int removeLoop(struct Node *head)
{
     Node *p= head;
     Node *q= head;
    do {
        p=p->next;
        q=q->next;
        if(q)
        q=q->next;
    }
    while(p && q && p!=q );
    if(p==q)
    { while(p->next!=q)
     {p=p->next;}

     p->next=NULL;}
}
