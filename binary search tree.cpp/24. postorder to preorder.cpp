int find(int arr[], int l, int h){
  for(int i=h;i>=l;i--){
    if(arr[i]<arr[h])
    return i;
  }
  return i;
}

void posttopre(int arr[], int l, int h, vector<int> &v){
  if(l>h)
  return;
  int g=find(arr,l,h);
  v.push_back(arr[l]);      //NODE       |_         _|
  posttopre(arr,l,g,v);  //LEFT      |- preorder =|
  posttopre(arr,g+1,h-1,v);     //RIGHT      |            |
}
