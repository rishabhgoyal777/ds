void binarytovector(Node* root,vector<int> &v){
    if(!root)
    return;
    binarytovector(root->left,v);
    v.push_back(root->data);
    binarytovector(root->right,v);
}
Node* vectorToBST(Node* root,vector<int> v,int &curr){
    if(!root)
    return NULL;
    vectorToBST(root->left,v,curr);
    root->data=v[curr++];
    vectorToBST(root->right,v,curr);
    return root;
}
Node* binaryTreeToBST (Node*root)
{   vector<int> v;
    binarytovector(root,v);
    sort(v.begin(),v.end());
    int curr=0;
    return vectorToBST(root,v,curr);
}
