#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	     stack <int> s;
	     int n;
	     cin>>n;
	     int a[n];
	     for(int i=0;i<n;i++)
	     cin>>a[i];

	     s.push(a[0]);
	     cout<<-1<<" ";

	     for(int i=1;i<n;i++){
	         if(a[i]>s.top()){
	             cout<<s.top()<<" "; s.push(a[i]);
	         }
	         else{
	             while(!s.empty() && s.top()>=a[i]){
	                 s.pop();
	             }
	             if(s.empty()){
	                     cout<<-1<<" "; s.push(a[i]);
	                 }
	             else{cout<<s.top()<<" "; s.push(a[i]);}
	         }
	     }cout<<endl;}}
