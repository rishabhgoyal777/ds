we have to create dll of leaf nodes and remove them fromm tree

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
  leaftodll
}
