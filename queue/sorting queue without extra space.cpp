int min_index(queue<int> q, int alreadysortedindex){
  int minimum=INT_MAX;
  int index=0;
  n=q.size();
  for(int i=0;i<n;i++){
    int temp=q.front();
    q.pop();
    if(temp <= minimum && i <= alreadysortedindex){
      minimum=temp;
      index=i;
    }
    q.push(temp);
  }
  return index;
}

void insertmintorear(queue<int> &q, int min_index){
  int min_value;
  int =q.size();
  for(int i=0;i<n;i++){
    int curr=q.front();
    q.pop();
    if(i!= min_index)
      q.push(curr);
    else
      min_value=curr;
  }
  q.push(min_value);
}

sort(queue<int> q){
  for(int i=1;i<=q.size();i++){
    int min_index=mini_ind(q,q.size()-i);
    insertmintorear(q,min_index);
  }
}
