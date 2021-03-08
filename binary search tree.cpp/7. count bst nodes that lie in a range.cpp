void countinrange(Node* root, int l,int h, int &count){
    if(!root)
        return;
    if(root->data >=l && root->data <= h)
        count++;
    if(l < root->data)
        countinrange(root->left,l,h,count);
    if(h > root->data)
        countinrange(root->right,l,h,count);
    return;
}
int getCountOfNode(Node *root, int l, int h)
{
  int count=0;
  countinrange(root,l,h,count);
  return count;

}
