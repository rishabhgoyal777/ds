vector<int> nextSmallerleft(int arr[], int n){
stack<int> s;
vector<int> v;
for(int i=0;i<n;i++){
    if(s.empty()){
        v.push_back(-1);
        s.push(i);
    }
    else{
        if(arr[i] <= arr[s.top()]){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                s.pop();
            }
            if(s.empty())
            v.push_back(-1);
            else
            v.push_back(s.top());

        s.push(i);
        }
        else{
            v.push_back(s.top());
            s.push(i);
        }
    }
}
return v;
}

  vector<int> nextSmallerright(int arr[], int n){
 vector<int> v;
 stack<int> s;

 for(int i=n-1;i>=0;i--){
     if(s.empty()){
         v.push_back(n);
         s.push(i);
     }
     else{
         if(arr[i] <= arr[s.top()]){
             while(!s.empty() && arr[i] <= arr[s.top()]){
                 s.pop();
             }
             if(s.empty())
              v.push_back(n);
             else
              v.push_back(s.top());

          s.push(i);
         }
         else{
             v.push_back(s.top());
             s.push(i);
         }
     }
 }
 reverse(v.begin(), v.end());
 return v;
}

  int getMaxArea(int arr[], int n){

  vector<int> left=nextSmallerleft(arr,n);
  vector<int> right=nextSmallerright(arr,n);
  vector<int> width;
  int mx=0;
  int temp=0;

  for(int i=0;i<n;i++){
      temp=(right[i]-left[i]-1)*arr[i];
      mx=max(mx,temp);
  }
  return mx;
}


int maxArea(int M[MAX][MAX], int n, int m) {
  int temp=0; int ans=0;
  ans=getMaxArea(M[0],m);

  for(int i=1;i<n;i++){
      for(int j=0;j<m;j++){
          if(M[i][j]==1)
              M[i][j]=M[i-1][j]+1;
          else
              M[i][j]=0;
      }
      temp=getMaxArea(M[i],m);
      ans=max(ans,temp);
  }
  return ans;
}

// int mxhist(int a[], int n){
//         stack<int> s; int i=0;int area,mx=0;
// 	     while(i<n){
// 	        if(s.empty() || a[i]>=a[s.top()]){
// 	             s.push(i); i++;
// 	        }
// 	        else{
// 	            int p= s.top(); s.pop();
// 	            area= a[p] *( s.empty()?  i : i-s.top()-1);
// 	            mx=max(area,mx);
// 	            }
// 	        }
// 	     while(!s.empty()){
// 	         int p= s.top(); s.pop();
// 	            area= a[p] *( s.empty()?  i : i-s.top()-1);
// 	            mx=max(area,mx);
//
// 	     }
// 	     return mx;
// 	     }
//
// int maxArea(int M[MAX][MAX], int n, int m) {
//    int ans,maxans=0;
//    ans= mxhist(M[0],m);
//    maxans=max(ans,maxans);
//   for(int i=1;i<n;i++){
//       for(int j=0;j<m;j++){
//       if(M[i][j]==1)
//           M[i][j]=M[i-1][j]+1;
//       else M[i][j]=0;}
//       ans=mxhist(M[i],m);
//       maxans=max(ans,maxans);
//   }
// return maxans;}
