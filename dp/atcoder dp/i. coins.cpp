#include<bits/stdc++.h>
using namespace std;
double t[3001][3001];           // t[i][j] is storing probability of jth head at ith index(toss)

int main(){
  int n;
  cin>>n;
  double p[n];
  for(int i=0;i<n;i++)
    cin>>p[i];
  memset(t,0,sizeof(t));
  t[0][0] = 1-p[0];  // 0th index pe hai aur 0 head aaye. toh probability will be of tails at that toss(index) i.e 1 - p[0]
  t[0][1] = p[0];    // 0th pe head aaya. toh prob is of head i.e p[0]

  for(int i=1;i<n;i++){
    for(int j=0;j<=n;j++){
      t[i][j] += (1-p[i]) * t[i-1][j];   //tails => mtlb pichle index tak j head ki prob * prob of tail at this index
                                        // matlb is bar tail hai j heads pehle aa chuke
      if(j>0)
      t[i][j] += p[i]*t[i-1][j-1];      // head => is bar head *pehle j-1 head ki probability

                                        //since t[1][1] = h[0]*t[1] + h[1]*t[0]
                                        // h[0] is pehle toss pe head ki prob. h[1] is dusre toss pe head ki prob
    }
  }
  double ans=0;
  for(int j=n/2 +1;j<=n;j++){
    ans+=t[n-1][j];
  }
  cout<<fixed<<setprecision(9)<<ans;//given-The output is considered correct when the absolute error is not greater than 10^-9
}
