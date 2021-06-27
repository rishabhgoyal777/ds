similar to book allocation
===========================
bool func(int a[], int n, int k, long long mid){
        int sum=0;
        int painter=1;
        for(int i=0;i<n;i++){
            if(a[i] > mid) return false;
            if(sum + a[i] > mid){
                sum=a[i];
                painter++;
                if(painter > k) return false;
            }
            else{
                sum+=a[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long sum=0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        long long l=0;
        long long h=sum;
        long long ans=0;
        
        while(l<=h){
            long long mid=l+(h-l)/2;
            
            if(func(arr,n,k,mid)){ //if k painters can do work in mid time. can also do in mid to h time. so see in left subarray
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
