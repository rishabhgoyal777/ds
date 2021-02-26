int sumtree(Node* root, bool &flag){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
    int x=sumtree(root->left,flag);
    int y=sumtree(root->right,flag);
    if(root->data!=(x+y))
        flag=false;
    return root->data + x+y;
}
bool isSumTree(Node* root)
{
    bool flag= true;
    int x=sumtree(root,flag);
    return (flag==true);

}
