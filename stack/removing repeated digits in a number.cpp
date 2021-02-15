#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    stack<int> s;
	    int p;
	    while(n){
	        p=n%10;
	        n=n/10;
	        if(s.empty() || p!= s.top()){
	        s.push(p);
	             }
	    }

	    while(!s.empty()){
	        cout<<s.top(); s.pop();
	    }
	    cout<<endl;

	}}
