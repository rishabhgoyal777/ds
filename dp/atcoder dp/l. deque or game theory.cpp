// p1 wants X-Y to max p2 wants X-Y min
//   X-Y=REQUIRED
// + X+Y=SUM
//================
// => 2*X-SUM = REQUIRED . Therefore it is depending upon X. if X is maximum X-Y is maximum. if X is minimum X-Y is minimum


#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[3002][3002][2];  // dp[i][j][turn] showing max value of X possible bw index i and j of matrix
int a[3002];

int game(int i,int j,int turn){
  if(i>j)
    return 0;
  if(t[i][j][turn] != -1)
    return t[i][j][turn];
  if(turn==0)
    return t[i][j][turn]=max(a[i]+game(i+1,j,1), a[j]+game(i,j-1,1));  // we are adding element at index a-in only p1 turn
  if(turn==1)                  // because dp is showing max value of X and X represents sum of p1's choices
    return t[i][j][turn]=min(game(i+1,j,0), game(i,j-1,0));   //p2 wants to minimize X
}

signed main(){
  int n;
  cin>>n;
	int sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  memset(t,-1,sizeof(t));

  int X=game(0,n-1,0);
  int ans= 2*X-sum;
  cout<<ans;
}
