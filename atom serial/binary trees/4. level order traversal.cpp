vector<int> levelOrder(Node* node)
{
  queue<Node*> q;
  vector<int> v;
  q.push(node);
  while(!q.empty()){
      Node *t=q.front();
      v.push_back(t->data);
      q.pop();
      if(t->left){
          q.push(t->left);
      }
      if(t->right){
          q.push(t->right);
      }
  }return v;
}


recursive fx

int height(node * root){
  if(root==null)
    return 0;
  else{
    int lh=height(root->left);
    int rh=height(root->right);
    if(lh>rh)
      return lh+1;
    else return rh+1;
  }}

void levelOrder(node* root){
  int h= height(root);
  for(int i=1;i<=h;i++)
  printlevel(root,i);     // i=1 pe 1st level ka h=1 hoga to root data print hoga. uske bad i=2 pe root ka h=2 HOGA
                          // to agle level pe jayge aur uska h=h-1 yani 1 hoga to uska data pirnt HOGA
                          // similarly h=height pe last level
}
void printlevel(node * root,int h){
  if(root==null)
  return;
  if(h==1)
  cout<<root->data;
  else if(h>1){
  printlevel(root->left,h-1);
  printlevel(root->right,h-1);}
}
