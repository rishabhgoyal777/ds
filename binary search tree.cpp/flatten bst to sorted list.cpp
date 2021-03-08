ek dummy node bnayi ek aur pointer le liya ussi pe temp nam ka for traversing. ab tree pe inorder ytraversal kiya aur node process krte time temp ka left null krte gye aur right pe tree ka node lgate gye jab tree khtam tab temp ke dono side null kyoki list khtam ho chuki hai. ab dummy ke next pe ek ponter le liya(start of sorted list) aur dummy delete kr diya.


            a                                            a
          /   \                                           \
        b       c              ====>                        b
      /   \    /  \                                           \
    d      e  f    g                                           c
                                                                \
                                                                  d
                                                                    \
                                                                      e ...

void inorder(Node* root,Node* &temp){
  if(!root) return;
  inorder(root->left,temp);
  temp->left=NULL;
  temp->right=root;
  temp=root;
  inorder(root->right,temp);
}

Node* flatten(Node* root){
  Node* dummy= new Node(-1);
  Node* temp= dummy;
  inorder(root, temp);

  temp->left=temp->right=NULL;

  Node* ret= dummy->right;
  delete dummy;
  return ret;


}
