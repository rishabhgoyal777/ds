// find pivot element index. this divides array into 2 subarrays. and find the element in the suitable subarray.    

int pivot(vector<int> &nums, int n){
        int l=0;
        int h=n-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            
            if(mid < h && nums[mid] > nums[mid+1])
                return mid;
            
            if(mid > l && nums[mid-1] > nums[mid] )
                return mid-1;
            
            //left subarray contains pivot
            if(nums[l] >= nums[mid])
                h=mid-1;
                
            //right contains
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
        
        if(p==-1)
            return binarysearch(nums, 0, n-1, target);
        
        //both subarrays are sorted
        
        if(nums[0] <= target) //if target >= nums[0] then it cant be in right subarray as right subarray will have every element less than nums[0]
            return binarysearch(nums, 0, p, target);
        else
            return binarysearch(nums, p+1, n-1, target);
        
    }
};
