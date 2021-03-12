Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with sum equal to given sum.

TOP DOWN
========
int subsetsum(int arr[], int n, int w){
    if(n==0 && w!=0)
      return 0;
    if(w==0)
      return 1;
    if(t[n][w]!=-1)
      return t[n][w];
    if(arr[n-1] <= w)
      return t[n][w]= subsetsum(arr,n-1,w-arr[n-1]) || subsetsum(arr,n-1,w) ;
    else
      return t[n][w] = subsetsum(arr,n-1,w);
      }


BOTTOM UP
=========
int subsetsum(int arr[], int N, int sum){
     bool t[N+1][sum+1];
     for(int i=0;i<N+1;i++){
         for(int j=0;j<sum+1;j++){
             if(i==0)
               t[i][j]=false;
             if(j==0)
               t[i][j]=true;
         }
     }
     for(int i=1;i<N+1;i++){
         for(int j=1;j<sum+1;j++){
           if(arr[i-1] <= j)
           t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j] ;
           else
           t[i][j] = t[i-1][j];
         }
     }
     return t[N][sum];
   }
