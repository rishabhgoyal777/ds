# LEETCODE
==========
TreeNode* treeUtil(vector<int> pre,int size, int l, int r, int &curr){
  if(curr >= size) return NULL;
  if(l>r) return NULL;
  if(pre[curr] < l || pre[curr] > r ) return NULL;
  int X=pre[curr];
  TreeNode* root= new TreeNode(pre[curr++]);

  root->left=treeUtil(pre,size,l,X-1,curr);
  root->right=treeUtil(pre,size,X+1,r,curr);

  return root;
}

TreeNode* bstFromPreorder(vector<int>& pre){
  int size=pre.size();
  int l=INT_MIN;
  int r=INT_MAX;
  int curr=0;
  return treeUtil(pre,size,l,r,curr);
}

===============================================================================

#GFG
=====
Node* treeUtil(int pre[],int size, int l, int r, int &curr){
  if(curr >= size) return NULL;
  if(l>r) return NULL;
  if(pre[curr] < l || pre[curr] > r ) return NULL;
  int X=pre[curr];
  Node* root= new Node(pre[curr++]);

  root->left=treeUtil(pre,size,l,X-1,curr);
  root->right=treeUtil(pre,size,X+1,r,curr);

  return root;
}

Node* constructTree(int pre[],int size){
  int l=INT_MIN;
  int r=INT_MAX;
  int curr=0;
  return treeUtil(pre,size,l,r,curr);
}
