                                              node
                                            /       \
          agar left nhi to process node and          agar left hai to this is curr move to inorder succesor  this is prev agar prev point kar raha
          move right                                  curr ko matlb lnked hai matlab precoes node remove link and move to Right
                                                    agr prev ka right kr raha null ko to make prev right point to curr and curr to left

void morris(Node* root)
{Node* curr= root;
  while(curr){
    if(!curr->left){
    cout<<curr->data<<" ";
    curr=curr->right;
  }
  else{
    Node* prev=curr->left;
    while(prev->right != NULL && prev->right != curr  ){
      prev=prev->right;
    }
    if(!prev->right){
      prev->right=curr;
      curr=curr->left;
    }
    else{
      cout<<curr->data<<" ";
      prev->right=NULL;
      curr=curr->right;
    }
 }
}
}

vector<int> morris(Node* root)
{

  vector<int> v;
  Node* curr= root;
  while(curr){
    if(!curr->left){
    v.push_back(curr->data);
    curr=curr->right;
  }
  else{
    Node* prev=curr->left;
    while(prev->right != NULL && prev->right != curr  ){
      prev=prev->right;
    }
    if(!prev->right){
      prev->right=curr;
      curr=curr->left;
    }
    else{
      v.push_back(curr->data);
      prev->right=NULL;
      curr=curr->right;
    }
 }
}
return v;
}
