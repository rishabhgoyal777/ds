RECURSIVE

void preorder(node* root){
  if(!root)
    return NULL;
  else{
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}



ITERATIVE

stack<node*> s;

node* t = root;

while(!s.empty() || t!= NULL){
  if(t){
    s.push(t);
    cout<<t->data<<" ";
    t=t->left;
  }
  else{
    t=s.top();
    s.pop();
    t=t->right;
  }
}
