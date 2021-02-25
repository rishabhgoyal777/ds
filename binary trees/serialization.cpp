void serial(node* root,vector<int> &v){
  if(!root){}
    v.push_back(-1);
    return;
  }
  v.push_back(root->data);
  serial(root->left,v);
  serial(root->right,v);
}
