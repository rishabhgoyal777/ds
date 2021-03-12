Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

KNAPSACK IDENTIFICATION-  2 ARRAY DIYE EK SIZE DIYA SELECT KRNA KI ARRAY ELEMENT LE YA NA LE]




KNAPSACK recursive
===========================
 agar n ya w kuch bhi 0 to return 0
 agar item ka wait bag capacity se kam to decide wheter to include or not return max of if we take and if we not take ...
 agr item ka wt bag se bag capacity se jyada to dont include


int knapsack(int wt[], int val[], int w, int n){
if(n==0 || w==0)
return 0;
if(wt[n-1] <= w)
return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1) );
else
return knapsack(wt,val,w,n-1);
}





KNAPSACK memoization/top down ( recursion + store results in matrix for using again)
===================================================================================
matrix dimensions are kept for variable arguements(whose value is changing in recursion)     t[n][w]



int t[1001][1001];

int knapSackUtil(int w, int wt[], int val[], int n){
if(n==0 || w<=0)
return 0;
if(t[n][w] != -1)
return t[n][w];
if(wt[n-1] <= w)
return t[n][w]=max(val[n-1]+knapSackUtil(w-wt[n-1],wt,val,n-1),knapSackUtil(w,wt,val,n-1) );
else
return t[n][w]=knapSackUtil(w,wt,val,n-1);}

int knapSack(int w, int wt[], int val[], int n){
memset(t,-1,sizeof(t));
return knapSackUtil(w,wt,val,n);
}







KNAPSACK BOTTOM UP(iterative with matrix)    NO recursion     initialize forst row and column bec agar bag ka size 0 to profit 0 agar array ka size 0 to profit 0    n ki jagah i kri jana   w ki jagah j aur matrix ka end element ans dega
========================================================


int knapsack(int wt[], int val[], int w, int n){
  int t[n+1][w+1];

  for(int i=0;i<n+1;i++){
    for(int j=0;j<w+1;j++){
      if(i==0 || j==0)
      t[i][j]=0;
    }
  }

for(int i=1;i<n+1;i++){
  for(int j=1;j<w+1;j++){
    if(wt[i-1] <= j)
    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);

    else
      t[i][j]= t[i-1][j];
  }
}
 return t[n][w];
}
