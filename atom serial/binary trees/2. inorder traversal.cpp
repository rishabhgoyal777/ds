RECURSIVE

void inorder(node* root){
  if!root)
    return null;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}


ITERATIVE

stack<Node*> s;
Node* t= root;
while(!s.empty() || t!=NULL){
  if(t!=NULL){
    s.push(t);
    t=t->left;
  }
  else{
    t=s.top();
    s.pop();
    cout<<t->data;
    t=t->right;
  }

}
