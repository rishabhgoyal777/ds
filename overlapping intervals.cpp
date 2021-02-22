#include <bits/stdc++.h>
using namespace std;
class interval
{   public:
    int start,end;


};
bool compare(interval a1,interval a2){
    return (a1.start < a2.start);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int l;
	    cin>>l;
	    stack<interval> s;
	    interval a[l];
	    for(int i=0;i<l;i++){
	        cin>>a[i].start;
	        cin>>a[i].end;
	    }
	    sort(a,a+l,compare);

	    s.push(a[0]);

	    for(int i=1;i<l;i++){
	        if(a[i].start > s.top().end)
	            s.push(a[i]);
	        else if(a[i].end > s.top().end){
	            s.top().end=a[i].end;
	        }
	    }
	    vector<int> v;
	    while(!s.empty()){
	        interval t = s.top();
	        v.push_back(t.start);
	        v.push_back(t.end);
	        s.pop();
	    }
	    sort(v.begin(),v.end());
	    for(auto x:v){cout<<x<<" ";}

	    cout<<endl;

	}}
