#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    priority_queue<int, vector<int>, greater<int>> minhp;
	    int index=0;
	    for(int i=0;i<n;i++){
	        minhp.push(arr[i]);
	        if(minhp.size()==k+1){
	            arr[index++]=minhp.top();
	            minhp.pop();
	        }
	    }
	    while(!minhp.empty()){
	        arr[index++]=minhp.top();
	        minhp.pop();
	    }
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }cout<<endl;
	}
	return 0;
}
