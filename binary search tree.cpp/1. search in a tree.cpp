bool search(Node* root, int key){
  if(!root)
  return false;
  if(root->data == key)
  return true;
  if(root->data < key)
  return search(root->right,key);

  return search(root->left,key);
}
