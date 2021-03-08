int minValue(Node* root)
{   if(!root)
    return -1;

    Node* temp=root;
    while(temp->left)
    temp=temp->left;

    return temp->data;
}
