int pairs(Node* first, Node* last, int sum){
  int total=0;
  while(first && last && first!=last && last->next!=first){
    if(first->data + last->data == sum){
      total++; first=first->next; last=last->prev;
    }
    else if(first->data + last->data < sum)
      first=first->next;
    else
      last=last->prev;
  }
  return total;
}

int triplets(Node* head, int x){
  Node  *curr, *first, *last;
  curr=first=last=head;
  while(last->next)
    last=last->next;
  int count=0;
  for(curr;!curr;curr=curr->next){
    first=curr->next;

    count+=pairs(first,last,x-curr->data);
  }
  return count;
}
