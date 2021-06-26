#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int l=1;
		int h=1e9;
		int ans=0;
    
    //perform binary search
		while(l<=h){
			int mid=l+(h-l)/2; // possible max of atleast minimum distance bw cows
			int cow=1; //put 1st cow at stall 1
			int prev=a[0]; //stall 1
			
			for(int i=1;i<n;i++){ 
				if(a[i]-prev >= mid){ //check for next stall if putting cow possible, increase cow and move to next stall
					cow++;
					prev=a[i];
					if(cow==c) // if no. of cows that can be placed == c(cow he has) therefore this can be the possible ans. but also check for greater distances
						break;
        }//else do nothing. move to next stall. i.e i++
			}
			if(cow==c){ 
				ans=mid; //store ans and move to right
				l=mid+1;
			}
			else{
				h=mid-1;  //else move to left
			}
		}
		cout<<ans<<endl;
	}
}
