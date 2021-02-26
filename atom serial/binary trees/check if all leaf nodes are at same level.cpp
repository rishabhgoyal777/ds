bool checkUtil(Node* root,int curlevel,int &leaflevel )
{
    if(!root)
    return true;

    if(!root->left & !root->right)
    {
        if(leaflevel==0){                          agar leaflevel=0 matlab pehli leaf mili to leaflevel= cur level
            leaflevel=curlevel;
            return true;
        }                                         now compare every leaf with this level
        if(leaflevel==curlevel)                   agar not = 0 matlab not first leaf to check kro is leaf ka pehli leaf jitna hai ke nhi
        return true;
        return false;
    }
    return checkUtil(root->left,curlevel+1,leaflevel) &&
    checkUtil(root->right,curlevel+1,leaflevel);

}
bool check(Node *root)
{
int curlevel=1;
int leaflevel=0;
return checkUtil(root,curlevel,leaflevel);

}
