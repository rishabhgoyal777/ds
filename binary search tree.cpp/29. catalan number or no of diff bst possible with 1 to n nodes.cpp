1.......(i-1)  i  .........n
   (i-1)             (n-i)

   catalan numbers

   summation f(i-1)*f(n-i)


int bstCount(int n){
  if(n==0 || n==1)
  return 1;
  int count=0;
  for(int i=1;i<n;i++){
    count+= bstCount(i-1)*bstCount(n-i);
  }
  return count;
}




using dp to optimize

int dp[n]; // all set -1

int bstCount(int n){
  if(n==0 || n==1)
  return 1;
  if(dp[n] != -1)
  return dp[n];
  int count=0;
  for(int i=1;i<n;i++){
    count+= bstCount(i-1)*bstCount(n-i);
  }
  return dp[n]=count;
}
