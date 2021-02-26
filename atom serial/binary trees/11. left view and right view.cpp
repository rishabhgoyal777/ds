void leftViewUtil(Node *root, vector<int> &v)
{  if(!root)
    return;
   int isfirst=1;
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       Node* t= q.front(); q.pop();
       if(!t){
          if(q.size()==0){
              return ;
          }
          else{
              q.push(NULL);
              isfirst=1;
          }
       }
       else{
          if(isfirst){
        v.push_back(t->data);
        isfirst=0;
        }
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
       }
   }return;
}

vector<int> leftView(Node *root){
  vector<int> v;
  leftViewUtil(root,v);
  return v;
}


RECURSIVE

void leftViewUtil(vector<int> &vec, struct Node *root, int level, int &max_level)
{
    // base case
    if (root==NULL)  return;

    // If this is the first node of its level
    if (max_level < level)
    {
        vec.push_back(root->data);
        max_level = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(vec,root->left, level+1, max_level);   // <
                                                           //) interchange for right view
    leftViewUtil(vec,root->right, level+1, max_level);   //<
}

// Function to get the left view
vector<int> leftView(struct Node *root)
{
    int max_level = 0;
    vector<int> vec;
    int level=1
    leftViewUtil(vec,root, level, max_level);
    return vec;
}
