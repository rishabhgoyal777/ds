node* deserial(string s, int &curr){
  if(s[curr]==-1){
    curr++;
    return NULL;
  }
  node* root= new node(s[curr]);
  curr++;
  root->left=deserial(s,curr);
  root->right=deserial(s,curr);
  return root;
}
