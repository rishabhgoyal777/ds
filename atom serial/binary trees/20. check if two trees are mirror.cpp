bool mirror(node* root1, node* root2){
  if(!root1 && !root2)
    return true;
  if(!root1 || !root2)
    return false;
  if(root1->data != root2->data)
    return false;

  return mirror(root1->left,root2->right) && mirror(root1->right,root2->left);
}
