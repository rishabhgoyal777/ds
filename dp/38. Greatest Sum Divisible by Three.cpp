Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.
Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int t[2][3];
        memset(t,0,sizeof(t));

        int n=nums.size();

        for(int i=0;i<n;i++){

            for(int j=0;j<3;j++){
                int c = (t[0][j]+nums[i])%3 ;
                t[1][c] = max(t[1][c],t[0][j]+nums[i]);
            }
            for(int j=0;j<3;j++){
                t[0][j]=t[1][j];
            }
        }
        return t[1][0];
    }
};
