node* lca(node* root,int a, int b, bool &flag){
  if(!root)
    return NULL;
  if(root->data==a || root->data==b)
    return root;
  node* l=lca(root->left,a,b);
  node* r=lca(root->right,a,b);
  if( l && r ){
    flag= false;
    return root;
  }
  if(l)
    return l;
  if(r)
    return r;
  return NULL;
}

Bool check(node* root, int a, int b){
  Bool flag= true;
  lca(root,a,b,flag);
  Return flag;
}
