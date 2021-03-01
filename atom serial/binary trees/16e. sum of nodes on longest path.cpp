void sumlongestpathUtil(node* root, int sum, int &maxsum, int len, int &maxlen){
  if(!root){        // root null matlb travers kr layi poora root
    if(maxlen<len){
      maxlen=len;
      maxsum=sum;
    }
    else if(maxlen==len && maxsum < sum )
      maxsum=sum;

    return;
  }
  sumlongestpathUtil(root->left,sum+root->data, maxsum, len+1, maxlen);
  sumlongestpathUtil(root->right,sum+root->data, maxsum, len+1, maxlen);


}


int sumlongestpath(node * root){
  if(!root)
    return 0;

  int sum=0,len=0;
  int maxsum=INT_MIN;
  int maxlen=0;
  sumlongestpathUtil(root,sum,maxsum,len,maxlen);
  return maxsum;
}
