void kdistUtil(node* root,int d,vector<int> &v){
  if(!root)
    return;
  if(d==0){
    v.push_back(root->data);
    return;}
  kdist(root->left,d-1,v);
  kdist(root->right,d-1,v);
}


vector<int> kdist(node* root,int d){
  vector<int> v;
  kdistUtil(root,d,v);
  return v;
}
