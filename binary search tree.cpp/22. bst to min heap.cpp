min heap is complete binary tree and children should be greater than parents

void Util(Node* root,vector<int> &v){
  if(!root)
  return;
  Util(root->left,v);
  v.push_back(root->data);
  Util(root->left,v);
}

void bsttoMH(Node*root, vector<int>v, int &curr){
  if(!root)
  return;
  root->data=v[curr++];
  bsttoMH(root->left,v,curr);
  bsttoMH(root->right,v,curr);
}

void bstToMinHeap(Node* root){
  vector<int> v;
  curr=0;
  Util(root,v);

  bsttoMH(root,v,curr);


}
