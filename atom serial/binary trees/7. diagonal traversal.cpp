void diagonalUtil(node* root, map &m , int d){
  if(!root)
    return NULL;
  m[d].push_back(root->data);
  if(root->left) diagonalUtil(root->left,m,d+1);
  if(root->right) diagonalUtil(root->right,m,d);
}

vector<int> diagonal(node *root){
map<int, vector<int> > m;
int d=0;
diagonalUtil(root,m,d);
vector<int>v;
for(i:m){
  for(x:i.second){
    v.push_back(x);
  }
}

return v;
}
