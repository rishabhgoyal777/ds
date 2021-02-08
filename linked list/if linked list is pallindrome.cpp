DIVIDE LIST IN 2 HALFS REVERSE THE SECOND HALF AND COMPARE EACH DATA

bool isPalindrome(Node *head)
{
    Node * p= head;
    Node * q= head;
    Node * r;
    Node * s=NULL;      // head2
    Node * t=NULL;
    Node * a= head;


    while(q->next && q->next->next)
    {p=p->next;
    q=q->next->next;}

    if(q->next)
    q=q->next;

    r=p->next;
    p->next=NULL;

    while(r)
    {t=s; s=r; r=r->next; s->next=t;}

    while(a&&s)
    {if(a->data==s->data)
        {a=a->next; s=s->next;}
    else return 0;
    }return 1;
}
