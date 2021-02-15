int getNthFromLast(Node *head, int n)
{
       Node* p=head;
       Node* q=head;

       for(int i=0;i<n;i++){
        if(p)
            p=p->next;
        else
            return -1;
       }

       while(p){
           p=p->next;
           q=q->next;
       }
       if(q)
        return q->data;

       else
        return -1;
}
