void greatersumUtil(Node* root, int &sum){
  if(!root)
  return;
  greatersumUtil(root->right,sum);
  sum+=root->data;
  root->data=sum;
  greatersum(root->left,sum);
}

void greatersum(Node* root){
  int sum=0;
  greatersumUtil(root,sum);
}
