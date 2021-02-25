void maxpathsumUtil(node * root, int sum, int &ans ){
  if(!root)
    return;
  sum+= root->data;
  if(!root->left && !root->right && sum>ans)
    ans=sum;
  maxpathsum(root->left,sum,ans);
  maxpathsum(root->right,sum,ans);
}

int maxpathsum(node* root){
  int sum=ans=0;
  maxpathsumUtil(root,sum,ans);
  return ans;
}
