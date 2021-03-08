traverse array from right. for every elemnt add it to bst and find inorder successor if present replace element with it in array if succ not presentthan relace elemnt with -1

void insert(Node* &root, int data, Node* &succ){
  if(!root)
  root=new Node(data);

  else if(root->data < data)
  insert(root->right,data,succ);

  else if(root->data > data){
    succ=root;
    insert(root->left,data,succ);
  }
}

replace(int arr[],n){
  Node* root=NULL;
  for(int i=n-1; i>=0; i--){
    Node* succ=NULL;
    insert(root,arr[i],succ);

    if(succ)
    arr[i]=succ->data;
    else
    arr[i]= -1;
  }
}
