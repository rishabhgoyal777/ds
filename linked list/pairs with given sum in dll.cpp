vector<pair<int,int>> findpair(Node *head, int sum){
  Node* low=head;
  Node* high=head;

  while(high->next)
    high=high->next;

  while(low && high && high->next!=low && high!=low){
    if(low->data + high->data==sum){
      v.push_back(make_pair(low->data, high->data));
      low=low->next;
      high=high->prev;
    }
    else if(low->data + high->data < sum){
      low=low->next;
    }
    else{
      high=high->prev;
    }
  }
  return v;
}
