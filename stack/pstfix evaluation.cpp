#include <bits/stdc++.h>
using namespace std;

bool isop(char opr){
    if( opr=='*' || opr=='/' || opr=='+' || opr=='-'  )
        return 0;
    else return 1;
}

int number(char x){
    return (x - '0');
}
int main(){
    int t;
	cin>>t;
	while(t--){
	    stack <int> s;
	    string st;
	    cin>>st;
	    int a, b;
	    int i=0;

	    while(st[i]){
	        if(isop(st[i])){
	            s.push(number(st[i]));
	        }
	        else{
	            b=s.top(); s.pop();
	            a=s.top(); s.pop();
	           	switch (st[i]) {
					case '+' :
					    s.push(a + b); break;
					case '-' :
					    s.push(a - b);  break;
					case '*' :
					    s.push(a * b);  break;
					case '/' :
					    s.push(a / b);  break;
				}

	        } i++;
	    }
	    cout<<s.top()<<endl;

	}
}
