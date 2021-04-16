Given an integer n, break it into the sum of y positive integers, where y >= 2, and maximize the product of those integers.
Return the maximum product you can get.

class Solution {
public:
    int integerBreak(int n) {
        int t[n+1];
        for(int i=0;i<=n;i++)
            t[i]=INT_MIN;
        t[0]=1;
        for(int i=1;i<=n;i++){
            for(int k=1;k<i;k++){  //since y should be >=2 k needs to be < i not <=i
                t[i]=max(t[i], k*max(t[i-k], i-k));
            }
        }
        return t[n];
    }

};
