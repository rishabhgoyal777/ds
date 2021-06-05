Time Complexity => O(N)
=========================
  
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0; /* Current index of input array ar1[] */
    int j = 0; /* Current index of input array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    // Since there are (n+m) elements,
    // There are following two cases
    // if n+m is odd then the middle
    //index is median i.e. (m+n)/2
    if((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else{ // one of i or j have reached end of its array
                if(i < n)
              {
                  m1 = ar1[i++];
              }
              // for case when j<m,
              else
              {
                  m1 = ar2[j++];
              }  
            }
            
        }
        return m1;
    }
     
    // median will be average of elements
    // at index ((m+n)/2 - 1) and (m+n)/2
    // in the array obtained after merging ar1 and ar2
    else
    {
        for (count = 0; count <= (n + m)/2; count++)
        {
            m2 = m1;
            if(i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else{ // one of i or j have reached end of its array
                if(i < n)
                {
                    m1 = ar1[i++];
                }
                // for case when j<m,
                else
                {
                    m1 = ar2[j++];
                }  
            }
            
        }
        return (m1 + m2)/2;
    }
}


Time Complexity => O(log(min(n1,n2)))  (striver)
================================
  
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if( nums1.size() > nums2.size() )
            return findMedianSortedArrays(nums2,nums1);  // we are keeping n1 the smaller array. so that binary search is on smaller length
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0;
        int high=n1;
        
        
        while(low<=high){
            int cut1=(low+high)/2;    // element in 1st half =>  0 to cut1-1 from nums1 and 0 to cut2 -1 from nums2 similarly in second half
            int cut2=(n1+n2+1)/2 - cut1;
            
            int l1 = cut1==0 ? INT_MIN : nums1[cut1-1]; 
            int l2 = cut2==0 ? INT_MIN : nums2[cut2-1]; 
            int r1 = cut1==n1 ? INT_MAX: nums1[cut1]; 
            int r2 = cut2==n2 ? INT_MAX: nums2[cut2] ; 
            
            if(l1<=r2 && l2 <= r1){
                if((n1+n2) % 2 ==0)
                    return((max(l1,l2) + min(r1,r2))/2.0); 
                else
                    return max(l1,l2);
            }
            
            else if(l1 > r2){
                high = cut1-1;
            }
            else{
                low = cut1+1;
            }
        }
        return 0;           
    }
};
