preorder mei pehle node hogi pher left right to node pe index l last pe h
l index element se next bada elemet ka index nikala waha se right subtree shuru hoga
postorder ke liye phle left subtree call krdiya from l+1 to g-1
right call krdiya g to h
aur phir node push kr di.
agar node ka agge hi right subtree shuru ho raha hai to find l+1 return krega aur left subtree ki call hogi from l+1 to (l+1)-1 jo ki l>h ho  jayega
similarly agar right subtree nhi to loop pura chlega find ka aur h+1 return krega to main mei call hogi from h+1 to h aur l>h ho jayega.

int find(int arr[], int l, int h){
  for(int i=l;i<=h;i++){
    if(arr[i]>arr[l])
    return i;
  }
  return i;
}

void pretopost(int arr[], int l, int h, vector<int> &v){
  if(l>r)
  return;
  int g=find(arr,l,h);
  pretopost(arr,l+1,g-1,v);  //LEFT      |-         =|
  pretopost(arr,g,h,v);     //RIGHT      | POSTORDER |
  v.push_back(arr[l]);      //NODE       |_         _|
}
