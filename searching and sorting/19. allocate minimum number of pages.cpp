bool func(int a[], int n, int m, int mid){
        int sum=0;
        int student=1;
        for(int i=0;i<n;i++){
            if(a[i] > mid) return false;
            if(sum +a[i] > mid){
                student++;
                sum=a[i];
                if(student>m)   return false;
            }
            else{
                sum+=a[i];
            }
        }
        return true;
    }
    
    
    int findPages(int arr[], int n, int m) 
    {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        int ans =0;
        int l=0; //min pages that can be alotted to 1 student
        int h=sum; //max pages that can be alotted to 1 student
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(arr,n,m,mid)){ 
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }return ans;
        
    }
