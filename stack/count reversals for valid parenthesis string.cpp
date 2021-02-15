#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	     stack <char> s;
	     string e;
	     cin>>e;
	     int n=0;int m=0;
	     int ans;
	     for(int i=0;i<e.length();i++){
	         if(s.empty()){
	             s.push(e[i]);
	         }
	         else{
	             if(e[i]=='{')
	                s.push(e[i]);
	             if(e[i]=='}'){
	                 if(s.top()=='{')
	                    s.pop();
	                 else s.push(e[i]);
	             }
	         }
	     }

	     if(s.empty())
	        cout<<0<<endl;

	     else{while(!s.empty()){
	            if(s.top()=='{')
	                {s.pop();n++;}
	            else if(s.top()=='}')
	                {s.pop();m++;}}

	            if((m+n)%2 !=0)
	                cout<<-1<<endl;
	            else{ans=(((n+1)/2) + ((m+1)/2));
	            cout<<ans<<endl;}

	     }}}
