void kUtil(Node* root, int &k, int &ans){
    if(!root)
    return;
    kUtil(root->left,k,ans);
    k--;                                                      //jab element mila tab k-- kr diya
    if(k==0){
        ans= root->data;
        return;
    }
    kUtil(root->right,k,ans);

}


int KthSmallestElement(Node *root, int K)
{
    int ans=-1;
    kUtil(root,K,ans);
    return ans;
}
