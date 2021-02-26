bool isSymmetric(node* root){
  if(!root)
    return true;
  return ismirror(root->left,root->right);
}

bool ismirror(node* root1, node* root2){
  if(!root1 && !root2)
    return true;
  if(!root1 || !root2)
    return false;
  if(root1->data != root2->data)
    return false;
  return ismirror ( (root1->left,root2->right) && 
                            ismirror(root1->right,root2->left) ) ;
}
