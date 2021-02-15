int mxhist(int a[], int n){
        stack<int> s; int i=0;int area,mx=0;
	     while(i<n){
	        if(s.empty() || a[i]>=a[s.top()]){
	             s.push(i); i++;
	        }
	        else{
	            int p= s.top(); s.pop();
	            area= a[p] *( s.empty()?  i : i-s.top()-1);
	            mx=max(area,mx);
	            }
	        }
	     while(!s.empty()){
	         int p= s.top(); s.pop();
	            area= a[p] *( s.empty()?  i : i-s.top()-1);
	            mx=max(area,mx);

	     }
	     return mx;
	     }

int maxArea(int M[MAX][MAX], int n, int m) {
   int ans,maxans=0;
   ans= mxhist(M[0],m);
   maxans=max(ans,maxans);
  for(int i=1;i<n;i++){
      for(int j=0;j<m;j++){
      if(M[i][j]==1)
          M[i][j]=M[i-1][j]+1;
      else M[i][j]=0;}
      ans=mxhist(M[i],m);
      maxans=max(ans,maxans);
  }
return maxans;}
