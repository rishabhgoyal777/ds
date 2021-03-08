2 stack liye aur erative inorder daale
ek mei reverse direction mei.  similar to merging two trees
to ek stack ke top pe smallest hoga aur dusre ke top pe largest hoga
dono add kiye agar target bada hai matlab chote wale element se next badah daalke dekho matlb us element ka inorder succesor dallo pehle stack mei
similarly right side agr target chota hai x + y se

void util(Node* root, stack<Node*> &s, int direction){
  if(!root) return ;
  Node* temp= root;
  if(direction){
  while(temp){
    s.push(temp);
    temp=temp->left;
  }
}
  else{
    while(temp){
      s.push(temp);
      temp=temp->right;
    }
  }
}


int isPairPresent(struct Node *root, int target){
  stack<Node* > s1;
  stack<Node* > s2;
  util(root,s1,1);
  util(root,s2,0);
  int x=s1.top()->data;
  int y=s2.top()->data;
  while(!s1.empty() && !s2.empty() && x < y){
    if(x+y < target){
    Node* t1=s1.top(); s1.pop();
    util(t1->right,s1,1);
  }
    else if(x+y > target){
    Node* t2=s2.top(); s2.pop();
    util(t1->left,s2,0);
  }
    else{
      return 1;
    }
    x=s1.top()->data;
    y=s2.top()->data;
  }

  return 0;
}
