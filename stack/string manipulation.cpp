#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    stack<string> s;
	    for(int i=0;i<n;i++){
	        string a;
	        cin>>a;

	        if(s.empty())
	            s.push(a);

	        else{ string t = s.top();
	              if(t==a){
	                  s.pop();
	              }
	              else{ s.push(a);}
	        }
	    }
	    int k = s.size();
	    cout<<k<<endl;
	}}
