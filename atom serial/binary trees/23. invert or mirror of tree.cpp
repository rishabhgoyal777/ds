typedef struct treenode {
    int val;
    struct treenode* left;
    struct treenode* right;
} node;

node* createNode(int val)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void mirrorify(node* root, node** mirror)
{
    if (root == NULL) {
        mirror = NULL;
        return;
    }
    *mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}


BETTER

void mirrorutil(node* root){
  if(!root)
  return ;
  node* temp= root->left;
  root->left=root->right;
  root->right=temp;
  mirrorutil(root->left);
  mirrorutil(root->right);
}

node* mirror(node* root){
  if(!root)
  return NULL;
  mirrorutil(root);
  return root;
}
