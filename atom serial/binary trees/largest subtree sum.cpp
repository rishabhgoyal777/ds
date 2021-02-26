int largestsubtreesumUtil(node* root, int &maxsum, int sum){
  if(!root)
    return 0;
  int x=largestsubtreesum(root->left,maxsum,sum);
  int y=largestsubtreesum(root->right,maxsum,sum);
  sum+=root->data + x + y ;
  maxsum= max(maxsum,sum);
  return sum;
}

int largestsubtreesum(node* root){
  if(!root)
    return 0;
  int maxsum=INT_MIN;
  int sum=0;
  largestsubtreesumUtil(root,maxsum,sum);
  return maxsum;
}
