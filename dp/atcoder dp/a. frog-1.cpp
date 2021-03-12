#include<bits/stdc++.h>
using namespace std;
#define int long long

int t[100002];
int frog(int a[] , int n, int index){
  if(index== n-1)
    return 0;
  if(index >= n)
    return INT_MAX;
  if(t[index] != -1)
    return t[index];
  int ans= abs(a[index]-a[index+1]) + frog(a,n,index+1);
  if(index+2<n)
   ans = min(  ans,abs( a[index]-a[index+2])+frog(a,n,index+2)  );

  return t[index]= ans;
}
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  memset(t,-1,sizeof(t));
  cout<<frog(a,n,0);

  return 0;

}
