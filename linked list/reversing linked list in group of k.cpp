
struct node *reverse (struct node *head, int k)
{
    Node * p=head;
    Node * q=NULL;
    Node * r=NULL;
    int count=k;

    while(p&&count)
    { count--;
      r=q; q=p; p=p->next; q->next=r;
    }
    if(p)
    head->next=reverse(p,k);

    return q;
}
