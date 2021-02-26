      1
  2      3
4   5  6   7

level order: 1 2 3 4 5 6 7
reverse: 4 5 6 7 2 3 1

if we use stack to reverse order we get 7 6 5 4 3 2 1
therefore traverse right sid efirst then left to get 4 5 6 7 2 3 1


vector<int> reverseLevelOrder(Node *root)
{
    stack<Node *> s;
    queue<Node *> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        Node* t= q.front();
        s.push(t);
        q.pop();
        if(t->right)
            q.push(t->right);
        if(t->left)
            q.push(t->left);

    }
    while(!s.empty()){
        v.push_back(s.top()->data);
        s.pop();
    } return v;

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
  for(int i=h;i<=1;i++)
  printlevel(root,h);     // i=h gaya sbse pehle ye tb tak fx call krta rhega jb tk h=1 nhi ho jata aur wo last level pe
                          // jaake hoga matlb sbse pehle last ;evel print hoga pher h-1 pe 2nd last aise krte krte saare
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
