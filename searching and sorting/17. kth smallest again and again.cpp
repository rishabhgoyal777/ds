ranges given example {10,12} {25,34} {1,3)
  therefore que becomes find kth ele in arr=>[1 2 3 10 11 12 25 26 .... 34]

1. sorting ranges
2. merging intervals.
3. finding ele 


#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			v.push_back({a,b});
		}
		sort(v.begin(),v.end());
		int index=0;
		for(int i=1;i<v.size();i++){
			if(v[index].second >= v[i].first ){
				v[index].second=max(v[index].second, v[i].second);
			}
			else{
				index++;
				v[index]=v[i];
			}
		}
		while(q--){
			int k;
			cin>>k;
			int ans=-1;
			for(int i=0;i<=index;i++){
				if((v[i].second-v[i].first+1) >= k){
					ans=v[i].first+k-1;
					break;
				}
				else{
					k-=v[i].second-v[i].first+1;
				}
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
