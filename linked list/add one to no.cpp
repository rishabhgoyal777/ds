Node* reverse(Node* head){
    Node*p=head;
    Node*q=NULL;
    Node*r=NULL;
    while(p){
        r=q; q=p; p=p->next; q->next=r;
    }
    return q;
}

Node* addOne(Node *head){
  Node* number = reverse(head);
  Node* a=number;

  if(a->data<9)
    a->data=a->data+1;
  else{
      a->data=a->data+1;
      while(a->next){
          if(a->data==10){
              a->data=0;
              a->next->data++;
              a=a->next;
          }
          else
            break;
      }
  }
  return reverse(number);
}
