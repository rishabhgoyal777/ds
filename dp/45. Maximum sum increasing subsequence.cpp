Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
Example 1:
Input: N = 5, arr[] = {1, 101, 2, 3, 100}
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}


int maxSumIS(int arr[], int n)
{
    int t[n];
    for(int i=0;i<n;i++)
        t[i]=arr[i];

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i])
                t[i]=max(t[i],t[j]+arr[i]);
        }
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,t[i]);
    }
    return ans;
}
