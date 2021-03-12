#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int t[101][100002];
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++){
      cin>>a[i];
  }

  for(int i=0;i<=n;i++){
    for(int j=0;j<=k;j++){
      if(i==0)
        t[i][j]=0;
      if(j==0)
        t[i][j]=1;
    }
  }

  for(int i=1;i<=n;i++){
    vector<int> sum(k+1);
    sum[0]=t[i-1][0];
    for(int j=1;j<=k;j++)
    sum[j]=(sum[j-1]+t[i-1][j])% MOD;
    for(int j=0;j<=k;j++){
      if(j<=a[i-1])
        t[i][j]=sum[j];
      else
        t[i][j]=(sum[j]-sum[j-a[i-1]-1] + MOD) % MOD;
    }
    sum.clear();
  }

  cout<<t[n][k];
}
