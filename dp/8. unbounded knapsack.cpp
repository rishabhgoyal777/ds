Unbounded Knapsack (Repetition of items allowed)

Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate the maximum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item.


agar koi item le rhe to usko waps lene ke liye consider kr rahe par agr koi nhi le rhe to usko waps bad mei bhi nhi consider krte

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
