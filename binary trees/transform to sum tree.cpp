int sum(Node* root){
    if(!root)
        return 0;

    int x=sum(root->left);
    int y=sum(root->right);
    int d= root->data + x + y;       // pehke value ek variable mei store kr li bad mein uppdate ki root mei aur stored vali return krdi
    root->data=x+y;
    return d;
}
void toSumTree(Node *node)
{
    int x=sum(node);

}
