void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *p = head;
    Node *q = head;
    Node *r = head;
    Node *s = p->next;
    int count=2;
    while(s->next != p ){
      count++;
      s=s->next;
    }
    count=(count+1)/2;

    if (count<2){
      p->next=p;
      s->next=s;
      *head1_ref = p;
      *head2_ref = s;
    }

    else{
      for(int i=1;i<count;i++){
        q=q->next;
        r=r->next;
      }r=r->next;

    q->next=p;
    s->next=r;

  *head1_ref = p;
  *head2_ref = r;
}
