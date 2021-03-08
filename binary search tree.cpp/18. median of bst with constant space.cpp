count nodes suing morris traversal
then again traverse using morris traversal and keep a tailing pointer to current if in case there are even nodes
in odd nodes middle elemnt is Median
in even nodes add the middle two elemnts and divide by 2


void CountUsingMorris(Node* root, int &Nodescount)
{Node* curr= root;
  while(curr){
    if(!curr->left){
    Nodescount++;
    curr=curr->right;
  }
  else{
    Node* prev=curr->left;
    while(prev->right != NULL && prev->right != curr  ){
      prev=prev->right;
    }
    if(!prev->right){
      prev->right=curr;
      curr=curr->left;
    }
    else{
      Nodescount++;
      prev->right=NULL;
      curr=curr->right;
    }
 }
}
}

int Median(Node* root)
{if(!root)
  return 0;
 int Nodescount=0;
 CountUsingMorris(root,Nodescount)
 Node* curr= root;
 Node* tailing;
  while(curr){
    if(!curr->left){
    currentCounter++;
    if(Nodescount%2 != 0 && currentCounter == (Nodescount+1)/2)
    return curr->data;

    if(Nodescount%2 == 0 && currentCounter == Nodescount/2 + 1)
    return (tailing->data + curr->data)/2;

    tailing=curr;

    curr=curr->right;
  }
  else{
    Node* prev=curr->left;
    while(prev->right != NULL && prev->right != curr  ){
      prev=prev->right;
    }
    if(!prev->right){
      prev->right=curr;
      curr=curr->left;
    }
    else{
      currentCounter++;
      tailing=prev;
      if(Nodescount%2 != 0 && currentCounter == (Nodescount+1)/2)
      return curr->data;

      if(Nodescount%2 == 0 && currentCounter == Nodescount/2 + 1)
      return (tailing->data + curr->data)/2;

      prev->right=NULL;
      tailing=curr;
      curr=curr->right;
    }
 }
}
}
