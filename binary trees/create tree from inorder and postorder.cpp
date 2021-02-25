int search(int in[], int ins, int ine, int data){
  for(int j=ins;j<=ine;j++){
    if(in[j]==data)
      return j;
  }
}


Node* createtree(int in[], int post[], int ins , int ine, int &curr){
  if(ins>ine)
    return NULL;
  Node* root=new Node(post[curr]);
  int i= search(in,ins,ine,post[curr]);
  curr--;
  root->right=createtree(in,post,i+1,ine,curr);
  root->left=createtree(in,post,ins,i-1,curr);
  return root;
}




Node *buildTree(int in[], int post[], int n) {
    int ins=0;
    int ine=n-1;
    int curr=n-1;
    return createtree(in,post,ins,ine,curr);
}
