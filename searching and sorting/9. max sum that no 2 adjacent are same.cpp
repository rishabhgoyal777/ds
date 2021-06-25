int dp[10004];
    public:
    //Function to find the maximum money the thief can get.
    int func(int arr[], int n, int i){
        if(i>=n) return 0;
        if(dp[i] != -1)
            return dp[i];
        int a=arr[i]+func(arr,n,i+2);
        int b=func(arr,n,i+1);
        return dp[i]=max(a,b);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        memset(dp,-1,sizeof(dp));
        
        return func(arr,n,0);
    }
