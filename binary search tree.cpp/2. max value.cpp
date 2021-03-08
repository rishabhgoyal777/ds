int maxValue(Node* root)
{   if(!root)
    return -1;

    Node* temp=root;
    while(temp->right)
    temp=temp->right;

    return temp->data;
}
