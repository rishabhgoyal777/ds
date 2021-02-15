#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	     stack <int> s;
	     int n,area,mx=0;
	     cin>>n;
	     int a[n];
	     for(int i=0;i<n;i++)
	        cin>>a[i];
	     int i=0;
	     while(i<n){
	        if(s.empty() || a[i]>=a[s.top()]){
	             s.push(i); i++;
	        }
	        else{
	            int p= s.top(); s.pop();
	            area= a[p] *( s.empty()?  i : i-s.top()-1);
	            mx=max(area,mx);
	            }
	        }
	     while(!s.empty()){
	         int p= s.top(); s.pop();
	            area= a[p] *( s.empty()?  i : i-s.top()-1);
	            mx=max(area,mx);
	     }
	     cout<<mx<<endl;
	     }
	}
