dead end can be at leaf nodes only
har node ki range rakho
start  with l and h. these will depend upon que: generally l= int_min and h= INT_MAX but gfg que was that bst elements are greater than 0 therefor we took l=1
when we traverse left range will become {l, root->data-1}
when we traverse right range will become {root->data+1, r}
and for leaf nodes if upper and lower value of range is same, node value is that only and it cannot have any children so it is a dead end.
and if l>h then it is not a bst.

void dead(Node* root, int l, int h, bool& flag){
    if(!root)
    return ;
    if(flag==1)
    return;
    if(!root->left && !root->right){
        if(l==h){
        flag=1;
        return;
        }
    }
    dead(root->left, l, root->data-1,flag);
    dead(root->right, root->data+1, h,flag);
}

bool isDeadEnd(Node *root)
{
    int l = 1;
    int h = INT_MAX;
    bool flag=0;
    dead(root,l,h,flag);
    return flag;
}
