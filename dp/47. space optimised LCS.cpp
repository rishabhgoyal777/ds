from lcs code we can see that we only need last row for calculating next row. so instead of n rows we take 2 rows and column remain m+1

int LCS(string a, string b, int n, int m){
  int t[2][m+1];
  memset(t,0,sizeof(t));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[i-1]==b[j-1])
        t[i%2][j]=t[(i+1)%2][j-1]+1;
      else
        t[i%2][j]=max(t[(i+1)%2][j], t[i%2][j-1]);
    }
  }
  return t[n%2][m];
}
