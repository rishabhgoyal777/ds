Node* leaftodll(Node* root, Node* &head, Node* &tail){
  if(!root)
    return NULL;
  if(!root->left && !root->right){
    if(!head){
      head=tail=root;
    }
    else{
      root->left=tail;
      tail->right=root;
      tail=root;
    }
    return NULL;                        //bec we have to remove them from tree
  }
  root->left= leaftodll(root->left,head,tail);
  root->right= leaftodll(root->right,head,tail);
  return root;
}

Node * convertToDLL(Node *root){
    Node* head=NULL;
    Node* tail=NULL;
    leaftodll(root,head,tail);
    return head;

}
