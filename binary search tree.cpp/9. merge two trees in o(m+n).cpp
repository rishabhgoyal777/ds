Node* createtree(vector<int> v, int l, int h){
    if(l>h)
    return NULL;

    int mid=(l+h)/2;
    Node* root=new Node(v[mid]);
    root->left=createtree(v,l,mid-1);
    root->right=createtree(v,mid+1,h);

    return root;
}

void inorder(Node* root, vector<int> &v){
  if(!root)
  return ;
  inorder(root->left,v);
  v.push_back(root->data);
  inorder(root->right,v);

}

Node* mergebst(Node* root1, Node* root2){
  vector<int> v;
  inorder(root1,v);
  inorder(root2,v);
  sort(v.begin(),v.end());
  int l=0; int h=v.size()-1;
  return createtree(v,l,h);
}
