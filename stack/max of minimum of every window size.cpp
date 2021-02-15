#include <bits/stdc++.h>
using namespace std;

int * smallerLeft(int a[],int n){    //index of smaller on left element
    stack<int> s;
    int *r = new int[n];
     s.push(0);
	     r[0]=-1;
	     for(int i=1;i<n;i++){
	         if(a[i]>a[s.top()]){
	             r[i]=s.top(); s.push(i);
	         }
	         else{
	             while(!s.empty() && a[s.top()]>=a[i]){
	                 s.pop();
	             }
	             if(s.empty()){
	                     r[i]=-1; s.push(i);
	                 }
	             else{r[i]=s.top(); s.push(i);}
	         }
	     } return r;
}

int * smallerRight(int a[] ,int n){       //index of smaller on right element
    stack<int> s;
    int *r= new int [n];
    s.push(n-1);
    r[n-1]=n;
    for(int i=n-2;i>-1;i--){
        if(a[i]>a[s.top()]){
            r[i]=s.top(); s.push(i);
        }
        else{
	             while(!s.empty() && a[s.top()]>=a[i]){
	                 s.pop();
	             }
	             if(s.empty()){
	                     r[i]=n; s.push(i);
	                 }
	             else{r[i]=s.top(); s.push(i);}
	         }
	     } return r;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int *sl,*sr;
	    sl = smallerLeft(a,n);
	    sr = smallerRight(a,n);

	    int ans[n+1]={0};    // size n+1 bec min of len 0 is nothing and we will have element for lemgth 7

	    for(int i=0;i<n;i++){
	        int len= sr[i]- sl[i] - 1;
	        ans[len]= max(ans[len],a[i]);
	    }

	    for(int i=n-1;i>-1;i--){

	            ans[i]=max(ans[i],ans[i+1]);

	    }
	    for(int i=1;i<n+1;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}

}
