int maxSubarraySum(int arr[], int n){
        int t[n];
        memset(t,-1,sizeof(t));

        t[0]=arr[0];
        int maxans=t[0];

        for(int i=1;i<n;i++){
            t[i]=max(t[i-1]+arr[i],arr[i]);
            maxans=max(maxans,t[i]);
        }
        return maxans;
    }

space optimised
=========================================
int maxSubarraySum(int arr[], int n){
        int ans=arr[0];
        int maxans=ans;

        for(int i=1;i<n;i++){
            ans=max(ans+arr[i],arr[i]);
            maxans=max(maxans,ans);
        }
        return maxans;
    }
