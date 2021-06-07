Time => O(nlogn)
space => O(n) one row in heap
==================================
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater< pair<int,int>> > maxhp;
  
  int s[n];
  
  for(int i=0;i<n;i++){
      maxhp.push({mat[i][0],i});
      s[i]=0;
  }
  int res;
  int count=0;
  while(1){
      count++;
      pair<int,int> p=maxhp.top();
      maxhp.pop();
      res=p.first;
      int i=p.second;
      s[i]++;
      if(s[i]<n)
      maxhp.push({mat[i][s[i]],i});
      if(count==k)
      return res;
      
  }
  return res;
}
