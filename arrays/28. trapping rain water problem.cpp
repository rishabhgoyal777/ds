Time Complexity: O(N)
Auxiliary Space: O(N)
=============================
  
int trappingWater(int arr[], int n){
        int maxl[n];
        int maxr[n];
        maxl[0]=arr[0];
        maxr[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
            maxl[i]=max(maxl[i-1],arr[i]);
        for(int i=n-2;i>=0;i--)
            maxr[i]=max(maxr[i+1],arr[i]);
            
        int res[n];
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(maxl[i],maxr[i])-arr[i];
        }
        return sum;
    }


Time Complexity: O(n)
Auxiliary Space: O(1) 
==================================
  
int maxWater(int arr[], int n)
{
   
    // indices to traverse the array
    int left = 0;
    int right = n-1;
  
    // To store Left max and right max
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;
  
    int result = 0;
    while (left <= right)
    {
      if(r_max <= l_max)
      {
        result += max(0, r_max-arr[right]);

        r_max = max(r_max, arr[right]);

        right -= 1;
      }
      else
      {
        result += max(0, l_max-arr[left]);

        l_max = max(l_max, arr[left]);

        left += 1;
      }
    }
    return result;
}
