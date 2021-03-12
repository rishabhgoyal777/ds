#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
  int h,v;
  cin>>h>>v;
  char s[h][v];
  for(int i=0;i<h;i++){
    for(int j=0;j<v;j++){
      cin>>s[i][j];
    }
  }

  int dp[h][v];
  memset(dp,0,sizeof(dp));

  dp[0][0] = 1;

  for(int i=0;i<h;i++){
    for(int j=0;j<v;j++){
      if(s[i][j] == '#'){
        dp[i][j]=0;
        continue;
      }
      if(i>0){
        dp[i][j] += dp[i-1][j];      // 2 condition hai taki jab first row i.e. i=0 tab sirf pichle j element se ans aayega
      }                              // jab column 0 hai i.e. j=0 hai tab sirf upar wale i se ans ayyege
      if(j>0){                        // jab dono non zero tab dono ans add honge
        dp[i][j] += dp[i][j-1];     // matrix ka har elemnt bta raha ki us tak phuchne ke kitne treeke. isliye starting wale point
      }                              // 0,0 ko 1 value di hai.
        dp[i][j] %= MOD;
    }
  }
  cout<<dp[h-1][v-1];
}
