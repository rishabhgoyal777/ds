THIS METHOD USES MAP BETTER WAY IS TO TRAVERSE FROM END AND STORE RESULT IN VECTOR AND THEN REVERSE THAT VECTOR


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ stack <long long int> s;
	unordered_map<long long,long long>mp;
	  int n;
	  cin>>n;

	  long long int a[n];

	  for(int i=0;i<n;i++)
	  cin>>a[i];

	  s.push(a[0]);

	  for(int i=1;i<n;i++)
	  { if(a[i]<=s.top() || s.empty())
	        s.push(a[i]);
	    else{
	        while(!s.empty() && a[i] > s.top()  )
	        {  mp[s.top()]=a[i];s.pop(); }
	        s.push(a[i]);}
	    }

	  while(!s.empty())
	  {mp[s.top()]=-1;
	  s.pop();}

	  for(int i=0;i<n;i++)
	  { cout<<mp[a[i]]<<" ";}
	  cout<<endl;
	}}
