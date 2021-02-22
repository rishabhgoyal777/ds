class Solution
{
    public:
  stack<long long> s;
  vector<long long> nextSmallerleft(long long arr[], int n){

  vector<long long> v;
  for(long long i=0;i<n;i++){
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
  while(!s.empty())
    s.pop();
  return v;
}

    vector<long long> nextSmallerright(long long arr[], int n){
   vector<long long> v;
   for(long long i=n-1;i>=0;i--){
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
   while(!s.empty())
    s.pop();
   reverse(v.begin(), v.end());
   return v;
}

    long long getMaxArea(long long arr[], int n){

    vector<long long> left=nextSmallerleft(arr,n);
    vector<long long> right=nextSmallerright(arr,n);
    vector<long long> width;
    long long mx=0;
    long long temp=0;

    for(int i=0;i<n;i++){
        temp=(right[i]-left[i]-1)*arr[i];
        mx=max(mx,temp);
    }
    return mx;
}
};



// #include <bits/stdc++.h>
// using namespace std;
//
// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	     stack <int> s;
// 	     int n,area,mx=0;
// 	     cin>>n;
// 	     int a[n];
// 	     for(int i=0;i<n;i++)
// 	        cin>>a[i];
// 	     int i=0;
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
// 	     }
// 	     cout<<mx<<endl;
// 	     }
// 	}
