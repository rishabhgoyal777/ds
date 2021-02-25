void pathUtil(node *root, vector<int> curr, vector<vector<int> > &v){
  if(!root)
    return NULL;
  curr.push_back(root->data);
  if(!root->left &&!root->right)
    v.push_back(curr);
  path(root->left,curr,v);
  path(root->right,curr,v);
}


vector<vector<int> > path(node * root){
  vector<int> curr;
  vector<vector<int> > v;
  pathUtil(root,curr,v);
  return v;
}

iss code se curr ke har node pe nya bnega vector curr ka aur leaf pe return krne pe last vector pe control chla jayega par vector sare nye bnege isliye
OPTIMIZED
curr ko bhi reference se pass krenge aur end pe pop krdege taki vector mei se akhri node nikal jaye aur return upar wali node pe chla jayega

void pathUtil(node *root, vector<int> &curr, vector<vector<int> > &v){
  if(!root)
    return NULL;
  curr.push_back(root->data);
  if(!root->left &&!root->right)
    v.push_back(curr);
  path(root->left,curr,v);
  path(root->right,curr,v);
  curr.pop_back();
}


vector<vector<int> > path(node * root){
  vector<int> curr;
  vector<vector<int> > v;
  pathUtil(root,curr,v);
  return v;
}
