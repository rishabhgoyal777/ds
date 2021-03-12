#include<bits/stdc++.h>
using namespace std;
#define int long long
int t[100002][4];
int n;
int a[100002][4];

int vacation(int day, int task){
  if(day==n)
    return 0;
  if(day>n)
    return INT_MIN;
  if(t[day][task] != -1)
    return t[day][task];

  int ans= INT_MIN;

  if(task==0){
    ans=max(ans, vacation(day+1,1) + a[day][1] );
    ans=max(ans, vacation(day+1,2) + a[day][2] );
    ans=max(ans, vacation(day+1,3) + a[day][3] );
    }

  else if(task==1){
    ans=max(ans, vacation(day+1,2) + a[day][2] );
    ans=max(ans, vacation(day+1,3) + a[day][3] );
    }

  else if(task==2){
    ans=max(ans, vacation(day+1,1) + a[day][1] );
    ans=max(ans, vacation(day+1,3) + a[day][3] );
    }

  else{
    ans=max(ans, vacation(day+1,1) + a[day][1] );
    ans=max(ans, vacation(day+1,2) + a[day][2] );
    }
  return t[day][task]=ans;
}
signed main(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=1;j<4;j++){
      cin>>a[i][j];
    }}
  memset(t,-1,sizeof(t));
  cout<<vacation(0,0);

}
