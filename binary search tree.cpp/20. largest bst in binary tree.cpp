agar root null to bst b={true,0,INT_MAX,INT_MIN};
agar node ka tree bst mei hai uski conditions hai ki left subtree bst ho, right subtree bst ho, left ka max usse chota ho aur right ka minimum usse bda ho.
isliye agar node null atti hai to min ko int max rkhenge aur max ko int min.
phele Left Right pher Node therefore POSTORDER


struct bst{
    bool isbst;
    int size;
    int min;
    int max;
  };

bst largestBstUtil(Node* root){
  if(!root){
  bst b={true,0,INT_MAX,INT_MIN};
  return b;
  }
  bst l=largestBstUtil(root->left);
  bst r=largestBstUtil(root->right);

  if(l.isbst && r.isbst && l.max < root->data && r.min > root->data){

    bst b={true,1+ l.size + r.size,min(root->data,l.min), max(root->data,r.max)};
    return b;
  }

  bst b={false,max(l.size,r.size),-1, -1};
  return b;

}

int largestBst(Node *root)
{
  bst b=largestBstUtil(root);
  return b.size;
}
