#include <bits/stdc++.h>
using namespace std;

bool isoperand(char opr){
    if(opr=='^' || opr=='*' || opr=='/' || opr=='+' || opr=='-' || opr=='(' )
        return 0;
    else return 1;
}

int outpre(char ope){
    if(ope=='^')
        return 6;
    else if(ope=='*' || ope=='/')
        return 3;
    else if(ope=='+' || ope=='-')
        return 1;
    else if(ope=='(')
        return 10;

}

int inpre(char ope){
    if(ope=='^')
        return 5;
    else if(ope=='*' || ope=='/')
        return 4;
    else if(ope=='+' || ope=='-')
        return 2;
    else return 0;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    stack<char> s;
	    string infix;
	    cin>>infix;
	    string postfix="";
	    int i=0,j=0;
	    while(infix[i]!= '\0') {

	        if(infix[i]==')' ){
	            while(s.top()!='('){
	                postfix+=s.top();
	                s.pop();
	               // if(s.empty())
	               //     return  -1;
	            } s.pop(); i++;
	        }

	        else if(isoperand(infix[i]))
	            postfix+=infix[i++];


	        else {
	            if(s.empty() || (inpre(s.top()) < outpre(infix[i])))
	                s.push(infix[i++]);
	            else {
	                 while (!s.empty()  && ( outpre(infix[i]) < inpre(s.top()) ) ){
	                postfix+=s.top();
	                s.pop();} s.push(infix[i++]);
	            }
	        }


            }

	    while(!s.empty()){
	    postfix+=s.top();
	    s.pop(); }


	   cout<<postfix;

	    cout<<endl;}

}
