void sumofsmalltreeUtil(Node* root,int &sum){
  if(!root)
  return ;
  sumofsmalltreeUtil(root->left, sum);
  sum+= root->data;
  root->data=sum;
  sumofsmalltreeUtil(root->right, sum);
  return;
}

void sumofsmalltree(Node* root){
  int sum=0;
  sumofsmalltreeUtil(root,sum);
}
