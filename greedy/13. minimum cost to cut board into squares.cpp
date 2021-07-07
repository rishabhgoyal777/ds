#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		m--;
		n--;
		int a[m];
		int b[n];
		int sum=0;
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}

		
		int ht=1;
		int vt=1;
		
		int ans=0;
		
		sort(a,a+m,greater<int>());
		sort(b,b+n,greater<int>());
		
		int i=0;
		int j=0;
		
		while(i<m && j<n){
			if(a[i] < b[j]){
				sum+= b[j]*vt;
				ht++;
				j++;
			} else{
				sum+= a[i]*ht;
				vt++;
				i++;
			}
		}
		
		while(i<m){
			sum+=a[i]*ht;
			i++;
		}
		while(j<n){
			sum+=b[j]*vt;
			j++;
		}
		cout<<sum<<endl;
	}
}
