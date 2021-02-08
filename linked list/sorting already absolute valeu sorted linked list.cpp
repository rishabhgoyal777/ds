void sortList(Node** head)
{
    Node * p = *head;
    Node * q = p->next;

    while(q)
    {
        if(q->data < p->data )
        {
           p->next=q->next;
           q->next=*head;
           *head=q;
           q=p;
        }
        else
            p=p->next;

        q=q->next;

    }


}\
