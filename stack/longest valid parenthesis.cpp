#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	   string e;
	   cin>>e;
	   stack<int> s;
	   s.push(-1);
	   int c=0;
	   int res=0;
	   for(int i=0;i<e.length();i++){
	       if(e[i]=='('){
	           s.push(i);
	       }
	       else{
	           s.pop();
	           if(s.empty()){
	               s.push(i);
	           }
	           else{
	               c=i-s.top();
	               res=max(c,res);
	           }
	       }
	   } cout<<res<<endl;}}
