// The function returns the root of the BST (currently rooted at 'root')
// after inserting a new Node with value 'Key' into it.
Node* insert(Node* root, int key)
{
    if(!root){
    Node* root= new Node(key);
    return root;}
    if(root->data==key){
        return root;
    }
    else if(root->data < key){
        root->right= insert(root->right,key);
    }
    else root->left= insert(root->left,key);

    return root;
}
