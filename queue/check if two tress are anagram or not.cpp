do level by level order traversal level wise and sort them and compare them.

if root 1 and root 2 null
return true
if root 1 or root 2 null  // first case is both are null if reaches this line means both not null and if this condition
return false                 //meaning one is null and other not therfore not anagrams

queue<node*> q1,q2
q1.push (root1)
q2.push(root2)

while(1){
  n1= q1.size   n2=q2.size
   if(n1!=n2)
    return false
   if(n1==0)
     break
     vector<int> curr_level1, curr_level2;
          while (n1 > 0)
          {
              Node *node1 = q1.front();
              q1.pop();
              if (node1->left != NULL)
                  q1.push(node1->left);
              if (node1->right != NULL)
                  q1.push(node1->right);
              n1--;

              Node *node2 = q2.front();
              q2.pop();
              if (node2->left != NULL)
                  q2.push(node2->left);
              if (node2->right != NULL)
                  q2.push(node2->right);

              curr_level1.push_back(node1->data);
              curr_level2.push_back(node2->data);
          }

       sort(curr_level1.begin,curr_level1.end)
       sort(curr_level2.begin,curr_level2.end)

       if (curr_level1 != curr_level2)
            return false;
}
return true;
