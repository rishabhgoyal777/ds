#include <bits/stdc++.h>
using namespace std;

bool func(int arr[], int n, int m, int mid){
	int sum=0;
	for(int i=0;i<n;i++){
		if(arr[i] > mid) sum+=arr[i]-mid;
		if(sum >= m) return true;
	}
	return false;
}

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0; //min cut height possible
	int h=*max_element(a,a+n); // max cut heigth possible
	int ans=0;
	while(l<=h){
		int mid=l+(h-l)/2;
		if(func(a,n,m,mid)){ // if from cutting mid we can get m wood. store it in ans. and increase cut heigth as it is possible taht we cut less wood but still complete the target for m wood 
			ans=mid;  
			l=mid+1;
		}
		else{
			h=mid-1; //if not then we have to decrease the cut height
		}
	}
	cout<<ans;
}
