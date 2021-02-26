int findIndex(int arr[], int ins, int ine, int target)
{
    for(int i=ins;i<=ine;i++){
        if(arr[i]==target)
            return i;
    }
}

Node* buildUtil(int inorder[], int preorder[], int ins, int ine, int preStart)
{
    if(ins>ine) return NULL;

    Node* ret = new Node( preorder[preStart] );

    if(ins==ine)
        return ret;

    int i = findIndex( inorder, ins, ine,preorder[preStart] );
    preStart++;
    ret->left = buildUtil( inorder, preorder, ins, i-1, preStart );
    ret->right = buildUtil( inorder, preorder, i+1, ine, preStart );

    return ret;
}

Node *buildTree(int inorder[], int preorder[], int n)
{
    return buildUtil(inorder, preorder, 0, n-1, 0);
}
