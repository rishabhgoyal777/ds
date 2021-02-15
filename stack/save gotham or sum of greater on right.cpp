#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    stack<int> s;
	    s.push(a[n-1]);
	    int res=0;
	    for(int i=n-2;i>=0;i--){
	        if(a[i]>s.top()){
	            while(!s.empty() && a[i]>=s.top()){
	                s.pop();
	            }
	            if(!s.empty()){
	                res=(res+s.top())%1000000001;
	            }
	            s.push(a[i]);

	        }
	        else{
	            res=(res+s.top())%1000000001;
	            s.push(a[i]);
	        }
	    }
	    cout<<res<<endl;
	}
}
