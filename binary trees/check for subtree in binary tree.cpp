// do tree traversal where subtree root data matches with any node check for identical trees from that node. if identical return true else continue if while loop end menas return true doesnot run. therefore return false.


bool identical(node* root1, node* root2){
  if(!root1 && !root2)
    return true;
  if(!root1 || !root2)
    return false;
  if(root1->data != root2->data)
    return false;

  return identical(root1->left,root2->left) && identical(root1->right,root2->right);
}


bool check(node * root1, node* root2){
  queue<node*> q;
  q.push(root1);
  while(!q.empty()){
    node * temp= q.front();
    q.pop();
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);

    if(temp->data==root2->data){
      bool ispresent=identical(temp,root2)
        if(ispresent) return true;
    }
  }
  return false;
}


OR

bool isSubtree(node *T, node *S)
{
    /* base cases */
    if (S == NULL)
        return true;

    if (T == NULL)
        return false;

    /* Check the tree with root as current node */
    if (identical(T, S))
        return true;

    /* If the tree with root as current
    node doesn't match then try left
    and right subtrees one by one */
    return isSubtree(T->left, S) ||
        isSubtree(T->right, S);
}
