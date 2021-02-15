#include <bits/stdc++.h>
using namespace std;

bool isaplha(char a){
    if(a>=65 && a<=90)
        return 1;
    else if(a>=97 && a<=122)
        return 1;
    else if(a=='[')
        return 1;
    else return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	     stack <int> st;
	     stack <int> num;
	     num.push(1);
	     string s;
	     cin>>s;
	     string r="";
	     string t="";
	     int i=0;
	     int n;
	     while(s[i]){
	         if(isaplha(s[i])){
	            st.push(s[i++]);
	           }
	         else if(s[i]=']'){
	             t=st.top(); st.pop();
	             while(st.top()!='['){
	                 t+=st.top(); st.pop();
	             }st.pop();i++; n=num.top(); num.pop();
	             for(int i=0;i<n;i++){
	                 r+=t;
	             }
	         }
	         else{
	             num.push((s[i]-'0'));i++;
	         }
	     }
	     cout<<r<<endl;}}
