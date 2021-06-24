    int pivot(vector<int> &nums, int n){
        int l=0;
        int h=n-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(mid < h && nums[mid] > nums[mid+1])
                return mid;
            
            if(mid > l && nums[mid-1] > nums[mid] )
                return mid-1;
            
            if(nums[l] >= nums[mid])
                h=mid-1;
                
            else
                l=mid+1;
        }
        return -1;
    }
    
    int binarysearch(vector<int> &nums, int l, int h,int target){
        while(l<=h){
            int mid=(l+h)/2;
            
            if(nums[mid]==target)
                return mid;
            if(nums[mid] >= target)
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int p = pivot(nums, n);
        
        // return p;
        if(p==-1)
            return binarysearch(nums, 0, n-1, target);
        
        if(nums[0] <= target)
            return binarysearch(nums, 0, p, target);
        else
            return binarysearch(nums, p+1, n-1, target);
        
    }
};
