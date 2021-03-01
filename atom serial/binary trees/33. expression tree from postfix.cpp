postfix created from postorder i.e. left right node
for postfix we read expresiion in reverse order and firct call right subtree then leftView


Node* expressiontree(string a, int &curr){
  if(curr < 0)
    return NULL;
  Node* root= new Node(a[curr]);
  if(a[curr]=='+' || a[curr]=='-' || a[curr]=='*' || a[curr]=='/' ){
    curr--;
    root->right=expressiontree(a,curr);
    root->left=expressiontree(a,curr);
    return root;
  }
  else{curr--;
      return root;
  }
}
