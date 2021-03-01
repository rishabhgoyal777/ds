void pathsumUtil(node * root, bool &flag,int sum,int k){
  if(!root)
    return ;
  sum+=root->data;
  if(!root->left && !root->right && sum==k)
    flag=true;

  pathsum(root->left,flag,sum,k);
  pathsum(root->right,flag,sum,k);
}

bool pathsum(node* root, int k){
  bool flag=false;
  int sum=0;
  pathsumUtil(root, flag, sum, k);
  return flag;

}
