void ksumUtil(node* root,int sum, int k, vector<int> &curr, ){
  if(!root)
    return;
  sum+=root->data;
  curr.push_back(root->data);
  if(sum==k){
    for(int i=0;i<curr.size();i++)
      cout<<curr[i];
    cout<<endl;
  }
  ksumUtil(root->left,sum,k,curr);
  ksumUtil(root->right,sum,k,curr);
}

void ksum(node * root, int k){
  vector<int> v;
  ksumUtil(root,sum,k,v);
}
