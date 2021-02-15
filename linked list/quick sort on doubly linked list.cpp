
Node* partition(Node *l, Node *h){
  int x=h->data;
  Node* p=l->prev;
  for(Node* a=l; a!=h; a=a->next){
    if(a->data < x){
      p= (p==NULL)? l: p->next;
      swap(p->data,a->data);
    }
  }
  p= (p==NULL)? l: p->next;
  swap(p->data,h->data);

  return p;
}

void sortUtil(Node* l, Node* h){
  if(h && l!=h && h->next!=l){
    Node* p=partition(l,h);
    sortUtil(l,p->prev);
    sortUtil(p->next,h);
  }
}

Node* quicksort(Node* head){
  Node* h=head;
  while(h->next)
    h=h->next;

  sortUtil(head,h);
  return head;
}
