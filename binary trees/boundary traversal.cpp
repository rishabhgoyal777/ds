void leafnode(Node* root, vector<int> &v){
    if(!root)
        return;

    if(!root->left && !root->right){
        v.push_back(root->data);}
    leafnode(root->left,v);
    leafnode(root->right,v);
}
void lb(Node* root, vector<int> &v){
    if(!root)
        return ;
    if(root->left || root->right)         // not a leaf node
        v.push_back(root->data);
    if(root->left)
        lb(root->left,v);
    else if(root->right)
        lb(root->right,v);
}

void rb(Node* root, vector<int> &v){
    if(!root)
        return ;
    if(root->right)
        rb(root->right,v);
    else if(root->left)
        rb(root->left,v);
    if(root->left || root->right)
        v.push_back(root->data);
}
vector <int> printBoundary(Node *root)
{   vector<int>v;
    v.push_back(root->data);
    lb(root->left,v);
    leafnode(root,v);
    rb(root->right,v);
    return v;

}\
