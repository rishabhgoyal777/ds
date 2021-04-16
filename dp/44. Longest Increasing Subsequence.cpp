Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
Example 1:
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

O(n^2)  dp[i] denoting LIS length at ith index
============================================
int longestSubsequence(int n, int a[])
   {
      int t[n];
      for(int i=0;i<n;i++){
          t[i]=1;
      }
      for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
              if(a[j] < a[i])
               t[i]=max(t[i],t[j]+1);
          }
      }
      int ans=INT_MIN;
      for(int i=0;i<n;i++){
          ans=max(ans,t[i]);
      }
      return ans;
   }


O(nlogn)    dp[i] denoting last element of LIS of length i
=====================
int longestSubsequence(int n, int a[])
{
  int t[n+1];
  for(int i=0;i<=n;i++){
    t[i]=INT_MAX;
  }
  t[0]=INT_MIN;

  int index=0;
  for(int i=0;i<n;i++){
    index=upper_bound(t,t+n+1,arr[i])-t; // index of elemnt just greater than arr[i]
    if(t[index-1]<a[i] && t[index]>a[i]){  // to avoid duplicate elements
      t[index]=a[i]; // replacing it bec. let index=4 pe elemnt 10 hai matlb LIS of length 4 mei last element 10 hai. now we have find an LIS jisme last 10 se chota hai. therfore more chnace of increasing length of LIS aage.
    }
  }

  int ans=0;
  for(int i=n;i>=0;i--){
    if(t[i]!=INT_MAX)
      return i;
  }
}
