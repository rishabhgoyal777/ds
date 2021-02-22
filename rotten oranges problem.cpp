#include<bits/stdc++.h>
using namespace std;
int r,c;

bool issafe(int i, int j){               // dekhne ke liye ki element ke cross mei jo index hai wo matrix mei hoge ke nhi
  return (i>=0 && i<r && j>=0 && j<c);
}
struct ele{
  int i;
  int j;
};
bool isboundary(ele a){                       //delimiter check krne ke liye
  return (a.i==-1 && a.j==-1);
}

int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>r>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin>>a[i][j];}}
    int count=0;
    queue<ele> q;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(a[i][j]==2)
          q.push({i,j});
        }}
      q.push({-1,-1});
    while(!q.empty()){
      int flag=0;
      while(!isboundary(q.front())){
        ele m=q.front();
        int r=m.i;
        int s=m.j;
        if(issafe(r+1,s) && a[r+1][s]==1){
          a[r+1][s]=2;  q.push({r+1,s});
          if(flag==0)
            count++;flag=1;}
        if(issafe(r-1,s) && a[r-1][s]==1){
          a[r-1][s]=2; q.push({r-1,s});
          if(flag==0)
            count++;flag=1;}
        if(issafe(r,s+1) && a[r][s+1]==1){
          a[r][s+1]=2;   q.push({r,s+1});
          if(flag==0)
            count++;flag=1;}
        if(issafe(r,s-1) && a[r][s-1]==1){
          a[r][s-1]=2;   q.push({r,s-1});
          if(flag==0)
            count++;flag=1;}
        q.pop();              //popping from queue for first count/round only
      }
      q.pop();                   // end of first count now popping boundary indicator or delimiter
      if(!q.empty())    // if elements in queue means it will go for count/round 2 therefore again add delimeter at end
        q.push({-1,-1});
      if(flag==0) break;      // if flag remains 0 meaans no change therefore no more can rott, count is ans
    }
    int h=0;
     for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(a[i][j]==1)      // agar koi ek bhi 1 matlb rott nhi hua to ans -1 agr koi 1 nhi bcha matlab count is ans
          h=1;
    }}

    if(h==1)
        cout<<-1<<endl;
    else cout<<count<<endl;


    }
}
