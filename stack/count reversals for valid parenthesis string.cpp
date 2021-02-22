#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	     stack <char> s;
	     string e;
	     cin>>e;
	     int n=0,m=0;
	     int i=0;
	     while(e[i]){
	         if(s.empty()){
	             s.push(e[i++]);
	         }
	         else{
	             if(e[i]=='{'){
	                 s.push(e[i++]);
	             }
	             else{
	                 if(s.top()=='{'){
	                     s.pop(); i++;
	                 }
	                 else{
	                     s.push(e[i++]);
	                 }
	             }
	         }
	     }
	     if(s.size()%2!=0)
	        cout<<-1<<endl;
	     else{
	         while(!s.empty()){
	             if(s.top()=='{'){
	                n++;
	                s.pop();
	             }
	             else{
	                 m++;
	                 s.pop();
	             }
	         }
	         int ans=(n+1)/2 + (m+1)/2;
	         cout<<ans<<endl;
	     }
	}

}
