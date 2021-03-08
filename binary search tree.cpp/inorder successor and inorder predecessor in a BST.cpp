pehle root check kro jaha key mile waha predecosr or successor nikal lo
wrna agar key root se choti to root ko succ set kr dege aur left subtree mei dekhege.
agar key root se bdi to root ko predecessor set krke right tree mei dekhenge.

Node* predecessor(Node* root){
    Node* temp=root;
    while(temp && temp->right)
        temp=temp->right;
    return temp;
}
Node* successor(Node* root){
    Node* temp=root;
    while(temp && temp->left)
        temp=temp->left;
    return temp;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{   if(!root)
    return;
    if(root->key==key){
        if(root->left)
        pre=predecessor(root->left);
        if(root->right)
        suc=successor(root->right);
    }
    if(root->key > key){
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    if(root->key < key){
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
    return;
}
