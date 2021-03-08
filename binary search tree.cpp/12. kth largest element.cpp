void kUtil(Node* root, int &k, int &ans){
    if(!root)
    return;
    kUtil(root->right,k,ans);
    k--;
    if(k==0){
    ans=root->data;
    return;}
    kUtil(root->left,k,ans);


}
int kthLargest(Node *root, int K)
{   int ans;
    kUtil(root,K,ans);
    return ans;
}
