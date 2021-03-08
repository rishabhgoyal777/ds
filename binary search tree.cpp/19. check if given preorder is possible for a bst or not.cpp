we are maintaining a stack of decreasing order from bottom to top.
preorder is node left right
agar stack top se chota hai array ka next mtlb left child hoga, daldiya stack mei.
jaha stack top se bada hai mtb right child hai to stack pop krliya utni bar jaha tk stack top chota hai aur last popped ko parent mei store kr liya kyonki wo iska parent hoga. ab agge array mei agr koi iss parent se chota aajata hai to bst nhi bn skta ye preorder kyoki preorder hota node left right to right ke bad waps left child nhi ho skta us node ka.
kyoki hum pop krke parent tb store kr rahe jab uska right child aarha.


bool checkpre(int arr[], int n){
  stack<int> s;
  int parent= INT_MIN;
  for(int i=0;i<n;i++){
  while(!s.empty() && s.top()->data < arr[i]){
    parent=s.top();
    s.pop();
  }
  if(arr[i]<parent)
  return false;

  s.push(arr[i]);
  }
  return true;
}
