First= 3 5  7 9 20  25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55    57 100
You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62


#include <bits/stdc++.h>
using namespace std;

int main() {
	while(true){
		int n;
		cin>>n;
		if(n==0) break;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int m;
		cin>>m;
		int b[m];
		for(int i=0;i<m;i++)
			cin>>b[i];
			
		int sum1=0;
		int sum2=0;
		int ans=0;
		
		int i=0, j=0;
		while(i<n && j<m){
			if(a[i] < b[j])
				sum1+=a[i++];
			else if(a[i] > b[j])
				sum2+=b[j++];
			else{
				ans+=max(sum1,sum2);
				sum1=0, sum2=0;
				ans+= a[i];
				i++, j++;
			}
		}
		
		// ans+= max(sum1, sum2);
		while(i<n){
			sum1+= a[i++];
		}
		while(j<m){
			sum2+=b[j++];
		}
		ans+= max(sum1, sum2);
		cout<<ans<<endl;
		
	}
	return 0;
}
