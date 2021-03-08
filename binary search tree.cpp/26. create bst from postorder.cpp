TreeNode* treeUtil(vector<int> post,int size, int l, int r, int &curr){
  if(curr < 0) return NULL;
  if(l>r) return NULL;
  if(post[curr] < l || post[curr] > r ) return NULL;
  int X=post[curr];
  TreeNode* root= new TreeNode(post[curr--]);

  root->right=treeUtil(post,size,X+1,r,curr);
  root->left=treeUtil(post,size,l,X-1,curr);

  return root;
}

TreeNode* bstFromPreorder(vector<int>& post){
  int size=pre.size();
  int l=INT_MIN;
  int r=INT_MAX;
  int curr=size-1;
  return treeUtil(post,size,l,r,curr);
}
