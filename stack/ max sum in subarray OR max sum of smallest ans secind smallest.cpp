#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long m=0;
	    long long res;
	    long long int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }

	    for(int i=0;i<n-1;i++){
	        res=a[i]+a[i+1];
	        m=max(m,res);

	    }
	    cout<<m<<endl;


	}}
