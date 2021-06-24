Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        
        int l=0;
        int h=x;
        
        int ans=1;
        while(l <= h){
            int mid=(l+h)/2;
            
            if(mid == sqrt(x))
                return mid;
            
            if(mid <= sqrt(x)){
                ans=mid;  //example x=11 . when mid=3 mid*mid=9 which is less than x. so save it in ans. as last perfect sq before 11 will be of 3 and sqrt of 11 will also be 3
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
        
    }
};
