agar dono key choti to lca in left subtree
agar dono key badi to lca in right subtree

agar ye nhi to return krdo root kyonki baki cases bache ki:
1. root = a or root= b   return root
2. ek left mei ek right mei to root hi lca hai
   a < root->data && b > data OR a > root->data && b < data  return root

   krna return hi root to bina conditions likhe ho gya kyonki cases hi yehi bache hai.


Node* LCA(Node *root, int n1, int n2)
{
   if(!root)
   return NULL;
   if(root->data > n1 && root->data > n2)
   return LCA(root->left,n1,n2);
   if(root->data < n1 && root->data < n2)
   return LCA(root->right,n1,n2);

   return root;
}
