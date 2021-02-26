int height(node* node, int &ans){
  if(!node)
    return 0;
  int lh=height(node->left,ans);
  int rh=height(node->right,ans);
  ans=max(ans, 1+lh+rh);                         // diameter is lh + rh + 1
  return 1+max(lh,rh);                        // we are updating diameter in ans and returning height
}

int diameter(node* node){
  if(!node)
    return 0;
  else{
  int ans=0;
  height(node,ans);
  return ans;}
}

another METHOD

int height(Node* node){
    if(!node)
        return 0;
    else{
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
}

int diameter(Node* node) {
    if(!node)
        return 0;
    else{
         int lh = height(node->left);
         int rh = height(node->right);

    // get the diameter of left and right sub-trees
    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    return max(lh + rh + 1, max(ldiameter, rdiameter));
    }
}
