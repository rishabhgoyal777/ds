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
class Solution 
{ public:

     int trap(vector<int>& height) {

     int n= height.size();

     int left=0; int right=n-1;

     int res=0;

     int maxleft=0, maxright=0;

     while(left<=right) {

       if(height[left]<=height[right]){

          if(height[left]>=maxleft) 
             maxleft=height[left]; 
          else 
             res+=maxleft-height[left];

       left++;
       } else{

           if(height[right]>=maxright) 
              maxright= height[right];
           else 
              res+=maxright-height[right];

         right--;
       }
     }
    return res;

   }
};
