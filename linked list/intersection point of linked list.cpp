lambi list jitni lambi utni traverse krdo phir dono lathe traverse ke jaha pe dono same point kr rahe wo answer



int intersectPoint(Node* head1, Node* head2)
{   int count1=0;
    int count2=0;
    int diff=0;
    Node* p= head1;
    Node* q= head2;
    while(p)
    {count1++;
     p=p->next;   }p=head1;

    while(q)
    {count2++;
     q=q->next;   }q=head2;

    diff=abs(count1-count2);


    if(count1<count2)
    {for(int i=0;i<diff;i++)
     q=q->next;}

    else if(count1>count2)
    {for(int i=0;i<diff;i++)
     p=p->next;}

    while(p!=q)
    {
     {p=p->next;
      q=q->next;}
    }return p->data;

}
