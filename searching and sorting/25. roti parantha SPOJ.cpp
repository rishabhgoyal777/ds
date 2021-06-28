#include <bits/stdc++.h>
using namespace std;

bool func(int a[], int n, int mid, int p){
	int time=0;
	int parata=0;
	for(int i=0;i<n;i++){ //for every chef
		time=a[i]; //starting time for first parantha is rating R of chef
		int j=2; //multiple starting from 2
		while(time<=mid){ //while total time of this chef less than mid keep making paranthas
			parata++; // total parantha by all chefs
			time+=a[i]*j; //increment time according to que
			j++; //increment multiple
		}
		if(parata >= p) return true; // if total greater than required p
	}
	return false;
}


int main() {
	int t;
	cin>>t;
	while(t--){
		int p; //no of parantha
		cin>>p;
		int n; //no of chefs
		cin>>n;
		int a[n]; //rating R of chefs. time taken to make paranthas=> R then 2R then 3R. therfore for 3 paranthas total time= 6R 
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		
		int low=0;
		int high=1e8;
		int ans=0;
		
		while(low<=high){
			int mid= (low+high)/2;  //time in which n chefs can make greater than equal to p parathas or not
			
			if(func(a,n,mid,p)){ //if p paranthas can be made in mid time. can also be made in higher time. so check in left subarray
				ans=mid;
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		cout<<ans<<endl;
	}
}
