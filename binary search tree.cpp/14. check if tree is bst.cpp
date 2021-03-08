void checkbst(Node* root, bool &flag, int &greatest){
    if(!root)
        return ;
    checkbst(root->left,flag,greatest);
    if(root->data <= greatest){
        flag=0; return;
    }
    else{ greatest= root->data;}
    checkbst(root->right,flag,greatest);
    // return;
}

bool isBST(Node* root) {
    bool flag=1;
    int greatest=-1000;
    checkbst(root,flag,greatest);
    return flag;

}
