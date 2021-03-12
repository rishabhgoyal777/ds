take sum. if sum odd then not possible, if sum even find if there is a subset that can make a sum equal to sum/2. then other subset will automatically be also be equal to sum/2.

top-down/ memoization
=====================
class Solution{
public:

    int t[1001][1001];

    int equalPartition(int N, int arr[])
    { int sum=0;
      memset(t,-1,sizeof(t));
      for(int i=0;i<N;i++){
          sum+=arr[i];
      }
      if(sum%2!=0)
      return 0;
      else if(sum%2==0){
      return subsetsum(arr,N,sum/2);}
    }

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
           return t[n][w]= subsetsum(arr,n-1,w);
          }
};



BOTTOM UP
==============

class Solution{
public:
 int subsetsum(int arr[], int N, int req){
      bool t[N+1][req+1];
      for(int i=0;i<N+1;i++){
          for(int j=0;j<req+1;j++){
              if(i==0)
                t[i][j]=false;
              if(j==0)
                t[i][j]=true;
          }
      }
      for(int i=1;i<N+1;i++){
          for(int j=1;j<req+1;j++){
            if(arr[i-1] <= j)
            t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j] ;
            else
            t[i][j] = t[i-1][j];
          }
      }
      return t[N][req];
    }
    int equalPartition(int N, int arr[])
    {int sum=0;
      for(int i=0;i<N;i++){
          sum+=arr[i];
      }
      if(sum%2!=0)
      return 0;
      else if(sum%2==0){
      if( subsetsum(arr,N,sum/2))
          return 1;
        return 0;}
      }
};
