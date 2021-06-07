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


Time => O(nlogn)
space => O{1)         binary search on space
=================== 
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int l=mat[0][0];
    int h=mat[n-1][n-1];
    
    while(l<=h){
        int mid=(l+h)/2;
        int elelessthan=0;
        for(int i=0;i<n;i++){
            elelessthan += upper_bound(mat[i], mat[i]+n,mid)-mat[i];
        }
        
        if(elelessthan < k)
            l=mid+1;
        else
            h=mid-1;
    }
    return l;
}
