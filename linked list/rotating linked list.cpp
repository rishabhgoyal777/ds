node* update(node*start,int w){
  node *p= start ;
  node *q= NULL ;
  node *last = start;
  while (last->next)
    last = last->next;
  for(int i=0;i<w;i++){
    q=p;
    p = p->next;
  }
  last->next=start;
  start->prev=last;
  q->next=NULL; p->prev=NULL;
  start=p;

  return start;
}
