#include<bits/stdc++.h>
using namespace std;
#define int long long

int t[100002];

int frog(int a[] , int n, int k, int index){
  if(index== n-1)
    return 0;
  if(index>=n)
    return INT_MAX;
  if(t[index] != -1)
    return t[index];
  int temp=INT_MAX;
  for(int i=1;i<=k;i++){
    if(index+i < n)
  temp= min(temp, abs(a[index+i]-a[index]) + frog(a,n,k,index+i));
  }

  return t[index]= temp;
}
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  memset(t,-1,sizeof(t));
  cout<<frog(a,n,k,0);

  return 0;

}
