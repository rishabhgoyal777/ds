Node* merge(Node* root1, Node* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;

    Node* result;

    if(root1->data < root2->data){
        result=root1;
        result->bottom= merge(root1->bottom, root2);
    }
    else{
        result=root2;
        result->bottom= merge(root1, root2->bottom);
    }
    result->next=NULL;
    return result;
}

Node *flatten(Node *root)
{
   if(!root || !root->next)
    return root;

   return merge(root, flatten(root->next));
}
