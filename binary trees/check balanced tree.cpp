int height(Node* root, int &flag){
    if(!root)
        return 0;
    else{
        int lh= height(root->left,flag);
        int rh= height(root->right,flag);
        if(abs(lh-rh)>1)
            flag=0;
        return 1 + max(lh,rh);
    }
}

bool isBalanced(Node *root)
{
   int flag=1;
   height(root,flag);
   return flag;
}
