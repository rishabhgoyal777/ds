#include<bits/stdc++.h>
using namespace std;
int t[100009];             // t[i] represents 0 or 1 . if win possible with i stones then 1 else 0
int main(){
  int n,k;
  cin>>n>>k;
  int a[n];

  for(int i=0;i<n;i++)
    cin>>a[i];

  memset(t,0,sizeof(t));

  for(int i=1;i<=k;i++){           // i represents no. of stones    //i=0 t[0] will be 0 through memset
    for(int x:a){              //for(int j=0;j<n;j++){ if(i>=a[j] && t[i-a[j]])
      if(i>=x && t[i-x]==0){     // agar i mei se koi bhi a[j] ya x nikalne se wo loosing state bn jati matlb
        t[i]=1;               // t[i] winning state hai. us position se win possible hai
        break;
      }
    }
  }

  if(t[k]==1)
  cout<<"First";
  else
  cout<<"Second";
}
