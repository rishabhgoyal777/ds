#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{ stack <char> s;
	 string exp;
	 cin>>exp;
	 int flag=1;
	 for(int i=0;i<exp.length();i++)
	 { if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
	     s.push(exp[i]);
	   else
	    { if(s.empty())   //this step necessary other wise s.top= empty and next statements gve sgmentation fault
	        {flag=0;break;}
	      if(exp[i]==')' && s.top()=='(' )
	        s.pop();
	      else if(exp[i]=='}' && s.top()=='{' )
	        s.pop();
	      else if(exp[i]==']' && s.top()=='[' )
	        s.pop();
	      else
	      {flag==0;break;}
	    }
	 }

	 if(!s.empty())
	 {flag=0;}

	 if(flag==0)
	 cout<<"not balanced"<<endl;
	 else
	 cout<<"balanced"<<endl;}}
