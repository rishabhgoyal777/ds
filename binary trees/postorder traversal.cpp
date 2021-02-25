RECURSIVE

void postorder(node* root){
  if(!root)
    return NULL;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

ITERATIVE

stack<node*> s;
node* t= root;
stack<int> p;

s.push(root);

while(!s.empty()){
  t=s.top();
  p.push(t->data);
  s.pop();

  if(t->left)
  s.push(t->left);
  if(t->right)
  s.push(t->right);           //stack mei upar right hoga toh pehle right ka data push hoga to matlab int  stack mei
                              //left ka data upar hoga
}

while(!p.empty()){
  cout<<p.top()<<" ";
  p.pop();
}
