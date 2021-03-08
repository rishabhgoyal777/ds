GFG 1
=====

Node* Util(Node* root){
    Node* temp=root;
    while(temp->right)
        temp=temp->right;
    return temp;
    }

Node *deleteNode(Node *root,  int key)
{   if(!root) return NULL;
    else if(root->data==key){
        if(!root->left && !root->right)
            return NULL;
        else if(root->left && root->right){
            Node* temp=Util(root->left);
            root->data=temp->data;
            root->left= deleteNode(root->left,temp->data);
            }
        else if(root->left){
            return root->left;
            }
        else if(root->right){
            return root->right;
            }
        }
        else if(root->data > key)
            root->left= deleteNode(root->left,key);
        else if(root->data < key)
            root->right= deleteNode(root->right,key);
        return root;
    }

//
// LEETCODE
// ========
//
//     TreeNode * minValueNode( TreeNode* root)
//    {  TreeNode* current = root;
//        while (current && current->left != NULL)
//            current = current->left;
//        return current;
//    }
//     TreeNode* deleteNode( TreeNode* root, int key)
//    {
//        if (root == NULL) return root;
//        if (key < root->val)
//            root->left = deleteNode(root->left, key);
//        else if (key > root->val)
//            root->right = deleteNode(root->right, key);
//        else
//        {
//            if (root->left == NULL)
//            {
//               TreeNode *temp = root->right;
//                return temp;
//            }
//            else if (root->right == NULL)
//            {
//                 TreeNode *temp = root->left;
//                return temp;
//            }
//            TreeNode* temp = minValueNode(root->right);
//            root->val = temp->val;
//            root->right = deleteNode(root->right, temp->val);
//        }
//        return root;
//    }
// };


GFG 2
======

TreeNode* Util(TreeNode* root){
TreeNode* temp=root;
while(temp->right)
    temp=temp->right;
return temp;
}

TreeNode *deleteNode(TreeNode *root,  int key)
{   if(!root) return NULL;
else if(root->val==key){
    if(!root->left && !root->right)
        return NULL;
    else if(root->left && root->right){
        TreeNode* temp=Util(root->left);
        root->val=temp->val;
        root->left= deleteNode(root->left,temp->val);
        }
    else if(root->left){
        return root->left;
        }
    else if(root->right){
        return root->right;
        }
    }
    else if(root->val > key)
        root->left= deleteNode(root->left,key);
    else if(root->val < key)
        root->right= deleteNode(root->right,key);
    return root;
}
