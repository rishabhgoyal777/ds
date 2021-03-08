we will do iterative inorder traversal
using 2 stacks

at start we will fill 2 stacks with the left childrens from root
then until both stack are not empty whatever stack top is smaller we push in vector and again push this nodes right child and all left childrens ahead into stack.
whenever 1 stack is empty
we perform same algo on the other stack




void mergeUtil(Node* root,stack<Node*> &s){
  if(!root) return;
  Node* tem=root;
    while(tem){
        s.push(tem);
        tem=tem->left;
    }
    return;
}

vector<int> merge(Node *root1, Node *root2)
{
   stack<Node*>s1;
   stack<Node*>s2;
   vector<int> v;
   mergeUtil(root1,s1);
   mergeUtil(root2,s2);
   int x,y;
   Node* temp;
   Node* t;
  while(!s1.empty() && !s2.empty()){
     x=s1.top()->data; y=s2.top()->data;
      if(x < y){
          v.push_back(x);
          temp=s1.top(); s1.pop();
          mergeUtil(temp->right,s1);
      }
      else if(x > y){
          v.push_back(y);
          temp=s2.top(); s2.pop();
          mergeUtil(temp->right,s2);
      }
      else{
         v.push_back(x);             // we will push only one because bst cannot have duplicate nodes
         // v.push_back(y);
         temp=s1.top(); s1.pop();
         t=s2.top(); s2.pop();
         mergeUtil(temp->right,s1);
         mergeUtil(t->right,s2);
      }
  }
  if(!s1.empty()){
  while(!s1.empty()){
     x=s1.top()->data;
     v.push_back(x);
     temp=s1.top(); s1.pop();
     mergeUtil(temp->right,s1);
  }}
  if(!s2.empty()){
  while(!s2.empty()){
     y=s2.top()->data;
     v.push_back(y);
     temp=s2.top(); s2.pop();
     mergeUtil(temp->right,s2);
  }}
   return v;

}
