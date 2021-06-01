O(n)
O(1)
===========================

int sb(int arr[], int n, int x)
    {
        int l=0;
        int h=0;
        int sum=0;
        int minlength=INT_MAX;
         while( l<=h && h<n){
             while(sum<=x && h<n){
                 sum+=arr[h++];
             }
             while(sum>x && l<h){
                 minlength=min(minlength,h-l);
                 sum-=arr[l++];
             }
         }
         return minlength;
    }

