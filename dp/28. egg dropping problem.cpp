int t[501][501];
int eggDropUtil(int n, int k)
{
  if(n<=1)
    return k;
  if(k<=1)
    return k;
  if(t[n][k] != -1)
    return t[n][k];
  int ans=INT_MAX;
  for(int i=1;i<=k;i++){
    int temp = 1+ max(eggDropUtil(n-1,i-1),eggDropUtil(n,k-i));
    ans=min(ans,temp);
  }
  return t[n][k]= ans;
}

int eggDrop(int n, int k){
  if(n<=1)
    return k;
  if(k<=1)
    return k;
  memset(t,-1,sizeof(t));
  return eggDropUtil(n,k);
}
