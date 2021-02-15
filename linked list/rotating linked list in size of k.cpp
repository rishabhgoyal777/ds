Node* rotating(Node* head, int k){
  Node* p=head;
  Node* temp, *q;
  int count=k;

  while(p && count--){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(count==0){
      q=p;
    }
  }
  if(p){
    head->next= rotating(p,k);
    head->next->prev=head;
  }
  return q;
}
