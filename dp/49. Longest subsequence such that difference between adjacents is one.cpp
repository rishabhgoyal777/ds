Given an array of n size, the task is to find the longest subsequence such that difference between adjacents is one.

Examples:

Input :  arr[] = {10, 9, 4, 5, 4, 8, 6}
Output :  3
As longest subsequences with difference 1 are, "10, 9, 8",
"4, 5, 4" and "4, 5, 6"

Input :  arr[] = {1, 2, 3, 2, 3, 7, 2, 1}
Output :  7
As longest consecutive sequence is "1, 2, 3, 2, 3, 2, 1"


O(n^2)-time
O(n)-space
=============================================
int longestSubsequence(int n, int arr[])
    {
        int t[n];
        for(int i=0;i<n;i++){
            t[i]=1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(abs(arr[i]-arr[j])==1)
                    t[i]=max(t[i],t[j]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,t[i]);
        }
        return ans;
    }



O(n)-time
O(n)-space
using map, map will contain element and max length till it
============================
int longestSubsequence(int n, int arr[]){
  unordered_map<int,int> m;

  int result=INT_MIN;

  for(int i=0;i<n;i++){    //for every arr element
    int ans=0;

    if(m[arr[i]-1])        //checking if element minus 1 exist
      ans=m[arr[i]-1];
    if(m[arr[i]+1])        //checking if element plus 1 exists and taking max of both answers
      ans=max(ans,m[arr[i]+1]);
    ans+=1;                // then adding elemnt in subsequence

    m[arr[i]]=ans;          // storing its ans in map
    result=max(result,m[arr[i]]);    // storing max so far in map in result
  }
  return result;
}
