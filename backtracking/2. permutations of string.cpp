#include <bits/stdc++.h>
using namespace std;

void permutations(string &curr, int position, int length, set<string> &s){
    if(position == length-1){
        s.insert(curr);
        return;
    }

    for(int i=position;i<length;i++){
        swap(curr[position],curr[i]);
        permutations(curr,position+1,length,s);
        swap(curr[position],curr[i]);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    set<string> all;
	    permutations(a,0,a.length(),all);
	    for(auto x:all){
	        cout<<x<<" ";
	    }
	    cout<<endl;

	}
	return 0;
}
