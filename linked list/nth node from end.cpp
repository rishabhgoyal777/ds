int getNthFromLast(Node *head, int n)
{
       Node * p=head;
       Node * q=head;
       if (head==NULL)
       return -1;
       for(int i=0;i<n-1;i++)
       { if(p->next)
            p=p->next;
         else return -1;
       }

       while(p->next)
       {p=p->next;
       q=q->next;}


       if(q)
       return q->data;
       else
       return -1;

}
