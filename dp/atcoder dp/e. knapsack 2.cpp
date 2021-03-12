Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
1≤wi≤W
1≤vi≤10^3

now dp cant be taken t[n][w] as it wil 10^11 so we take dp as t[n][v total] and the matrix shows min wt for a value v.
i index shows arr elements j index shows values possible(0 to v total)


#include<bits/stdc++.h>
using namespace std;
#define int long long

int knapsack(int wt[],int vl[], int W, int n, int v){
  int t[n+1][v+1];
  int i,j;
  for(i=0;i<n+1;i++){
    for(j=0;j<v+1;j++){
      if(i==0)
        t[i][j]=INT_MAX;
      if(j==0)
        t[i][j]=0;
    }
  }
  for(i=1;i<n+1;i++){
    for(j=1;j<v+1;j++){
      if(vl[i-1] <= v)
        t[i][j]= min(wt[i-1] + t[i-1][j-vl[i-1]], t[i-1][j]);
      else
        t[i][j]= t[i-1][j];
    }
  }
  for(j=v;j>=0;j--){
    if(t[n][j] <= W)
      return j;
  }
}
signed main(){
  int n,W;
  cin>>n>>W;
  int wt[n],vl[n];
  for(int i=0;i<n;i++){
    cin>>wt[i]>>vl[i];
  }
  int v=0;
  for(int i=0;i<n;i++)
  v+=vl[i];
  cout<<knapsack(wt,vl,W,n,v);
}
