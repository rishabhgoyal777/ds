leaf nodes are operands
others are operators

therefore if operator create node and call for left and right
else if it operand create node and return node


Node* expressiontree(string a,int &curr){
  if(curr==a.length())
    return NULL;
  Node* root= new Node(a[curr]);
  if(a[curr]=='+' || a[curr]=='-' || a[curr]=='*' || a[curr]=='/' ){
    curr++;
    root->left=expressiontree(a,curr);
    root->right=expressiontree(a,curr);
    return root;
  }
  else{curr++;
       return root;
  }
}
