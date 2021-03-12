int t[n+1][s+1];

for(int i=0;i<n+1;i++){
  for(int j=0;j<s+1;j++){
    if(i==0 || j==0)
    t[i][j]=0;
  }
}

for(int i=1;i<n+1;i++){
  for(int j=1;j<s+1;j++){
    if(arr[i-1] <= j)
    t[i][j]= max(val[i-1]+t[i][j-arr[i-1]], t[i-1][j]) ;
    else
    t[i][j]= t[i-1][j] ;
  }
}

return t[n][s];
